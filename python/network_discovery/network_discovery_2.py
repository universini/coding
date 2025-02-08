import asyncio
from pysnmp.hlapi.asyncio import SnmpEngine, CommunityData, UdpTransportTarget, ContextData, ObjectType, ObjectIdentity, getCmd, nextCmd
import networkx as nx

# SNMP Credentials (Update as needed)
SNMP_COMMUNITY = "public"
SNMP_VERSION = 2

# OIDs for Discovery
OIDS = {
    "sysName": "1.3.6.1.2.1.1.5.0",
    "sysDescr": "1.3.6.1.2.1.1.1.0",
    "ifTable": "1.3.6.1.2.1.2.2.1.2",  # Interface names
    "arpTable": "1.3.6.1.2.1.4.22.1.2",  # ARP mappings
    "lldpTable": "1.0.8802.1.1.2.1.4.1.1.9",  # LLDP neighbor info
}

# Initialize network graph
network_graph = nx.Graph()

def snmp_get(oid, target):
    """ Perform SNMP GET operation """
    return getCmd(
        SnmpEngine(),
        CommunityData(SNMP_COMMUNITY, mpModel=SNMP_VERSION - 1),
        UdpTransportTarget((target, 161)),
        ContextData(),
        ObjectType(ObjectIdentity(oid))
    )

def snmp_walk(oid, target):
    """ Perform SNMP WALK operation """
    return nextCmd(
        SnmpEngine(),
        CommunityData(SNMP_COMMUNITY, mpModel=SNMP_VERSION - 1),
        UdpTransportTarget((target, 161)),
        ContextData(),
        ObjectType(ObjectIdentity(oid)),
        lexicographicMode=False
    )

async def query_device(ip):
    """ Query a device for SNMP information and update the graph """
    global network_graph
    
    # Get basic device info
    sys_name = "Unknown"
    async for (errorIndication, errorStatus, _, varBinds) in snmp_get(OIDS["sysName"], ip):
        if errorIndication or errorStatus:
            print(f"SNMP error on {ip}")
            return
        sys_name = varBinds[0][1].prettyPrint()
    
    network_graph.add_node(ip, name=sys_name)
    
    # Walk LLDP neighbors
    async for (errorIndication, errorStatus, _, varBinds) in snmp_walk(OIDS["lldpTable"], ip):
        if not errorIndication and not errorStatus:
            neighbor_ip = varBinds[0][1].prettyPrint()
            network_graph.add_edge(ip, neighbor_ip)
            await query_device(neighbor_ip)  # BFS Expansion

async def discover_network(seed_device):
    """ Perform BFS-based network discovery """
    queue = [seed_device]
    discovered = set()
    
    while queue:
        current_device = queue.pop(0)
        if current_device in discovered:
            continue
        discovered.add(current_device)
        await query_device(current_device)

# Run discovery
if __name__ == "__main__":
    seed_ip = "192.168.1.1"  # Change as needed
    
    try:
        loop = asyncio.get_running_loop()
        loop.create_task(discover_network(seed_ip))
    except RuntimeError:
        asyncio.run(discover_network(seed_ip))
    
    # Print discovered network topology
    print("Discovered Devices:", network_graph.nodes(data=True))
    print("Network Links:", network_graph.edges)
