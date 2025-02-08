async def create_sample_network():
    discovery = NetworkDiscovery(
        seed_device='10.0.0.1',
        snmp_community='public'
    )
    
    # Sample Core Router
    core_router = {
        'ip': '10.0.0.1',
        'vendor': {'description': 'Cisco Nexus Core Switch', 'vendor': 'cisco'},
        'device_type': 'router',
        'hierarchy_level': 'core',
        'l3_neighbors': [
            {'ip': '10.0.0.2', 'protocol': 'OSPF', 'state': 'FULL'},
            {'ip': '10.0.0.3', 'protocol': 'BGP', 'state': 'ESTABLISHED'}
        ]
    }

    # Sample Distribution Switch
    dist_switch = {
        'ip': '10.0.0.2',
        'vendor': {'description': 'Cisco Catalyst 9300', 'vendor': 'cisco'},
        'device_type': 'switch',
        'hierarchy_level': 'distribution',
        'vlans': [
            {'id': '10', 'name': 'DATA', 'status': 'active'},
            {'id': '20', 'name': 'VOICE', 'status': 'active'}
        ]
    }

    # Sample Access Switch
    access_switch = {
        'ip': '10.0.0.3',
        'vendor': {'description': 'Cisco Catalyst 2960', 'vendor': 'cisco'},
        'device_type': 'switch',
        'hierarchy_level': 'access',
        'l2_neighbors': [
            {'ip': '10.0.0.4', 'hostname': 'PRINTER-1', 'protocol': 'CDP'},
            {'ip': '10.0.0.5', 'hostname': 'AP-1', 'protocol': 'LLDP'}
        ]
    }

    # Sample Wireless Controller
    wlc = {
        'ip': '10.0.0.6',
        'vendor': {'description': 'Cisco WLC', 'vendor': 'cisco'},
        'device_type': 'wlc',
        'wireless': {
            'is_wlc': True,
            'aps': [
                {
                    'name': 'AP-1',
                    'mac': '00:11:22:33:44:55',
                    'ip': '10.0.0.5',
                    'status': 'connected',
                    'clients': [
                        {'mac': 'AA:BB:CC:DD:EE:FF', 'ip': '10.0.0.100', 'ssid': 'Corporate'}
                    ]
                }
            ]
        }
    }

    # Sample Firewall
    firewall = {
        'ip': '10.0.0.7',
        'vendor': {'description': 'Cisco ASA Firewall', 'vendor': 'cisco'},
        'device_type': 'firewall',
        'vulnerabilities': [
            {'name': 'End of Support Version', 'severity': 'MEDIUM'}
        ]
    }

    # Add all devices to topology
    discovery.network_topology = {
        '10.0.0.1': core_router,
        '10.0.0.2': dist_switch,
        '10.0.0.3': access_switch,
        '10.0.0.6': wlc,
        '10.0.0.7': firewall
    }

    # Export the sample topology
    discovery.export_topology('sample_network_topology.json')
    return discovery.network_topology

if __name__ == "__main__":
    topology = asyncio.run(create_sample_network())
