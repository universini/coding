import asyncio
import json
import logging
from collections import deque
from typing import Dict, List, Set

import networkx as nx
from pysnmp.smi import *
from pysnmp.hlapi import *
from pysnmp.hlapi.asyncio import *

# import pysnmp.hlapi.asyncio
# print(dir(pysnmp.hlapi.asyncio))

class NetworkDiscovery:
    def __init__(self, seed_device: str, snmp_community: str):
        self.seed_device = seed_device
        self.snmp_community = snmp_community
        self.discovered_devices = set()
        self.network_topology = {}
        self.device_queue = deque([seed_device])
        self.max_concurrent_walks = 50
        
        # Common OIDs
        self.OIDS = {
            'sysDescr': '1.3.6.1.2.1.1.1',
            'sysObjectID': '1.3.6.1.2.1.1.2',
            'ifTable': '1.3.6.1.2.1.2.2',
            'arpTable': '1.3.6.1.2.1.3.1',
            'cdpCache': '1.3.6.1.4.1.9.9.23.1.2.1.1',
            'vlanTable': '1.3.6.1.4.1.9.9.46.1.3.1.1',
            'vrfTable': '1.3.6.1.4.1.9.9.711.1.1.1',
            'lldpRemTable': '1.0.8802.1.1.2.1.4',
            'wlcApTable': '1.3.6.1.4.1.9.9.513.1.1.1',
            'clientTable': '1.3.6.1.4.1.9.9.513.1.2.1'
        }
        
        # Device classification signatures
        self.DEVICE_SIGNATURES = {
            'iot': ['thermostat', 'camera', 'sensor', 'iot'],
            'medical': ['patient', 'monitor', 'mri', 'xray'],
            'industrial': ['plc', 'scada', 'factory'],
            'printer': ['printer', 'mfp', 'scanner'],
            'network': ['switch', 'router', 'firewall', 'ap']
        }
        
        logging.basicConfig(level=logging.INFO)
        self.logger = logging.getLogger(__name__)

    async def get_l2_neighbors(self, ip: str) -> List[Dict]:
        l2_neighbors = []
        # Combine CDP and LLDP neighbor discovery
        neighbors = await self.get_neighbors(ip)
        
        for neighbor in neighbors:
            if neighbor.get('protocol') in ['CDP', 'LLDP']:
                l2_neighbors.append({
                    'ip': neighbor['ip'],
                    'hostname': neighbor['hostname'],
                    'platform': neighbor['platform'],
                    'local_interface': neighbor['local_interface'],
                    'remote_interface': neighbor['remote_interface'],
                    'protocol': neighbor['protocol']
                })
        return l2_neighbors

    async def get_l3_neighbors(self, ip: str) -> List[Dict]:
        l3_neighbors = []
        # Get routing protocol neighbors
        ospf_neighbors = await self.snmp_walk(ip, '1.3.6.1.2.1.14.10')
        bgp_neighbors = await self.snmp_walk(ip, '1.3.6.1.2.1.15.3')
        
        for neighbor in ospf_neighbors:
            l3_neighbors.append({
                'ip': neighbor[0],
                'protocol': 'OSPF',
                'state': neighbor[1]
            })
        
        for neighbor in bgp_neighbors:
            l3_neighbors.append({
                'ip': neighbor[0],
                'protocol': 'BGP',
                'state': neighbor[1]
            })
        
        return l3_neighbors

    async def get_software_info(self, ip: str) -> Dict:
        software_info = {
            'version': '',
            'image': '',
            'uptime': ''
        }
        
        try:
            version = await self.snmp_walk(ip, '1.3.6.1.2.1.1.1.0')
            image = await self.snmp_walk(ip, '1.3.6.1.2.1.16.19.2.0')
            uptime = await self.snmp_walk(ip, '1.3.6.1.2.1.1.3.0')
            
            software_info['version'] = version[0] if version else ''
            software_info['image'] = image[0] if image else ''
            software_info['uptime'] = uptime[0] if uptime else ''
        except Exception as e:
            self.logger.error(f"Error getting software info for {ip}: {str(e)}")
        
        return software_info

    async def get_vulnerabilities(self, ip: str) -> List[Dict]:
        vulnerabilities = []
        vendor_info = await self.get_vendor_info(ip)
        software_info = await self.get_software_info(ip)
        
        # Check for known vulnerabilities based on version and vendor
        # This would typically integrate with a vulnerability database
        # For now, we'll check basic security issues
        checks = [
            {'name': 'Default SNMP Community', 'severity': 'HIGH'} if self.snmp_community in ['public', 'private'] else None,
            {'name': 'End of Support Version', 'severity': 'MEDIUM'} if self.is_eos_version(software_info['version']) else None,
            {'name': 'Telnet Enabled', 'severity': 'HIGH'} if await self.is_telnet_enabled(ip) else None
        ]
        
        vulnerabilities.extend([check for check in checks if check])
        return vulnerabilities

    async def determine_hierarchy_level(self, ip: str) -> str:
        # Determine device's role in network hierarchy
        interfaces = await self.get_interfaces(ip)
        l3_neighbors = await self.get_l3_neighbors(ip)
        vendor_info = await self.get_vendor_info(ip)
        
        if 'core' in vendor_info['description'].lower():
            return 'core'
        elif len(l3_neighbors) > 5:
            return 'distribution'
        elif any('access' in intf['name'].lower() for intf in interfaces):
            return 'access'
        else:
            return 'unknown'

    async def determine_device_type(self, ip: str) -> str:
        vendor_info = await self.get_vendor_info(ip)
        interfaces = await self.get_interfaces(ip)
        
        if await self.is_router(ip):
            return 'router'
        elif await self.is_switch(ip):
            return 'switch'
        elif await self.is_firewall(ip):
            return 'firewall'
        elif await self.is_wireless_controller(ip):
            return 'wlc'
        else:
            return 'unknown'

    async def is_telnet_enabled(self, ip: str) -> bool:
        try:
            reader, writer = await asyncio.open_connection(ip, 23)
            writer.close()
            await writer.wait_closed()
            return True
        except:
            return False

    def is_eos_version(self, version: str) -> bool:
        # Implement version checking logic based on vendor EOS dates
        # This would need to be maintained with current EOS information
        return False

    async def is_router(self, ip: str) -> bool:
        l3_neighbors = await self.get_l3_neighbors(ip)
        return len(l3_neighbors) > 0

    async def is_switch(self, ip: str) -> bool:
        vlans = await self.get_vlans(ip)
        return len(vlans) > 0

    async def is_firewall(self, ip: str) -> bool:
        vendor_info = await self.get_vendor_info(ip)
        return any(fw in vendor_info['description'].lower() 
                for fw in ['firewall', 'asa', 'palo alto', 'fortinet'])

    async def is_wireless_controller(self, ip: str) -> bool:
        wireless_info = await self.get_wireless_info(ip)
        return wireless_info['is_wlc']

    async def snmp_walk(self, ip: str, oid: str) -> List:
        try:
            result = []
            for (errorIndication,
                 errorStatus,
                 errorIndex,
                 varBinds) in next_cmd(SnmpEngine(),
                                    CommunityData(self.snmp_community),
                                    UdpTransportTarget((ip, 161)),
                                    ContextData(),
                                    ObjectType(ObjectIdentity(oid)),
                                    lexicographicMode=False):
                
                if errorIndication:
                    print(f"Error: {errorIndication}")
                    break
                elif errorStatus:
                    print(f"Error: {errorStatus}")
                    break
                else:
                    for varBind in varBinds:
                        result.append(f"{varBind[0]} = {varBind[1]}")
            return result
        except Exception as e:
            self.logger.error(f"SNMP walk failed for {ip}: {str(e)}")
            return []

    async def get_vendor_info(self, ip: str) -> Dict:
        sys_descr = await self.snmp_walk(ip, self.OIDS['sysDescr'])
        sys_object = await self.snmp_walk(ip, self.OIDS['sysObjectID'])
        
        vendor_info = {
            'description': sys_descr[0] if sys_descr else '',
            'object_id': sys_object[0] if sys_object else '',
            'vendor': self.determine_vendor(sys_descr[0] if sys_descr else '')
        }
        return vendor_info

    def determine_vendor(self, sys_descr: str) -> str:
        vendors = {
            'cisco': ['cisco', 'ios', 'catalyst', 'nexus'],
            'juniper': ['juniper', 'junos'],
            'arista': ['arista', 'eos'],
            'hp': ['hp', 'procurve', 'aruba'],
            'dell': ['dell', 'force10']
        }
        
        sys_descr = sys_descr.lower()
        for vendor, signatures in vendors.items():
            if any(sig in sys_descr for sig in signatures):
                return vendor
        return 'unknown'

    async def get_arp_table(self, ip: str) -> List[Dict]:
        arp_entries = []
        arp_table = await self.snmp_walk(ip, self.OIDS['arpTable'])
        
        for entry in arp_table:
            arp_entries.append({
                'ip': entry[0],
                'mac': entry[1],
                'interface': entry[2]
            })
        return arp_entries

    async def discover_device(self, ip: str):
        self.logger.info(f"Discovering device: {ip}")
        
        device_data = {
            'ip': ip,
            'vendor': await self.get_vendor_info(ip),
            'vrfs': await self.get_vrfs(ip),
            'vlans': await self.get_vlans(ip),
            'interfaces': await self.get_interfaces(ip),
            'arp_table': await self.get_arp_table(ip),
            'l2_neighbors': await self.get_l2_neighbors(ip),
            'l3_neighbors': await self.get_l3_neighbors(ip),
            'wireless': await self.get_wireless_info(ip),
            'software': await self.get_software_info(ip),
            'vulnerabilities': await self.get_vulnerabilities(ip),
            'hierarchy_level': await self.determine_hierarchy_level(ip),
            'device_type': await self.determine_device_type(ip)
        }
        
        self.network_topology[ip] = device_data
        self.discovered_devices.add(ip)
        
        # Add new neighbors to discovery queue
        for neighbor in device_data['neighbors']:
            if neighbor['ip'] not in self.discovered_devices:
                self.device_queue.append(neighbor['ip'])

    async def get_interfaces(self, ip: str) -> List[Dict]:
        interfaces = []
        if_table = await self.snmp_walk(ip, self.OIDS['ifTable'])
        
        for entry in if_table:
            interfaces.append({
                'index': entry[0],
                'name': entry[1],
                'type': entry[2],
                'status': entry[3]
            })
        return interfaces

    async def get_vlans(self, ip: str) -> List[Dict]:
        vlans = []
        vlan_table = await self.snmp_walk(ip, self.OIDS['vlanTable'])
        
        for entry in vlan_table:
            vlans.append({
                'id': entry[0],
                'name': entry[1],
                'status': entry[2]
            })
        return vlans

    async def get_vrfs(self, ip: str) -> List[Dict]:
        vrfs = []
        vrf_table = await self.snmp_walk(ip, self.OIDS['vrfTable'])
        
        for entry in vrf_table:
            vrfs.append({
                'name': entry[0],
                'rd': entry[1]
            })
        return vrfs

    async def get_neighbors(self, ip: str) -> List[Dict]:
        neighbors = []
        try:
            # CDP neighbors
            cdp_neighbors = await self.snmp_walk(ip, self.OIDS['cdpCache'])
            for entry in cdp_neighbors:
                neighbors.append({
                    'ip': entry[0],
                    'hostname': entry[1],
                    'platform': entry[2],
                    'local_interface': entry[3],
                    'remote_interface': entry[4],
                    'protocol': 'CDP'
                })
                
            # LLDP neighbors
            lldp_neighbors = await self.snmp_walk(ip, self.OIDS['lldpRemTable'])
            for entry in lldp_neighbors:
                neighbors.append({
                    'ip': entry[0],
                    'hostname': entry[1],
                    'platform': entry[2],
                    'local_interface': entry[3],
                    'remote_interface': entry[4],
                    'protocol': 'LLDP'
                })
        except Exception as e:
            self.logger.error(f"Error getting neighbors for {ip}: {str(e)}")
            
        return neighbors

    async def get_wireless_info(self, ip: str) -> Dict:
        wireless_info = {
            'is_wlc': False,
            'aps': [],
            'clients': []
        }
        
        # Check if device is WLC
        ap_table = await self.snmp_walk(ip, self.OIDS['wlcApTable'])
        if ap_table:
            wireless_info['is_wlc'] = True
            for ap in ap_table:
                ap_info = {
                    'name': ap[0],
                    'mac': ap[1],
                    'ip': ap[2],
                    'status': ap[3],
                    'clients': []
                }
                
                # Get clients for this AP
                client_table = await self.snmp_walk(ip, f"{self.OIDS['clientTable']}.{ap[1]}")
                for client in client_table:
                    ap_info['clients'].append({
                        'mac': client[0],
                        'ip': client[1],
                        'ssid': client[2]
                    })
                
                wireless_info['aps'].append(ap_info)
                
        return wireless_info

    async def classify_device(self, ip: str) -> str:
        vendor_info = await self.get_vendor_info(ip)
        description = vendor_info['description'].lower()
        
        for device_type, signatures in self.DEVICE_SIGNATURES.items():
            if any(sig in description for sig in signatures):
                return device_type
        return 'unknown'

    async def discover_network(self):
        self.logger.info(f"Starting network discovery from seed device: {self.seed_device}")
    
        try:
            while self.device_queue:
                batch = []
                while self.device_queue and len(batch) < self.max_concurrent_walks:
                    device = self.device_queue.popleft()
                    if device not in self.discovered_devices:
                        batch.append(device)
                    
                if batch:
                    tasks = [self.discover_device(device) for device in batch]
                    await asyncio.gather(*tasks, return_exceptions=True)
            
            self.logger.info(f"Discovery completed. Found {len(self.discovered_devices)} devices")
            return self.network_topology
        
        except Exception as e:
            self.logger.error(f"Error during network discovery: {str(e)}")
            return self.network_topology
    def export_topology(self, filename: str = 'network_topology.json'):
        with open(filename, 'w') as f:
            json.dump(self.network_topology, f, indent=2)
        self.logger.info(f"Network topology exported to {filename}")

async def main():
    discovery = NetworkDiscovery(
        seed_device='192.168.1.1',
        snmp_community='public'
    )
    
    topology = await discovery.discover_network()
    discovery.export_topology()

if __name__ == "__main__":
    asyncio.run(main())

