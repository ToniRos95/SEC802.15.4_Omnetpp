Sec-IEEE802154INET-Standalone
=========================

Network security project based on INET framework. Implemented security layer of 802.15.4 and patching "replay attack" vulnerability and "no integrity ack" attack.


Minimum requirements are:

- OMNeT++ 4.6 version
- INET 2.x (!) version (tested with 2.4 to 2.6)
  - Minimal set of enabled project features: IPv4, IPv6, Mobility, Radio
- Windows or Linux operating system

Usage instructions:

- Import the project from the Github repository into your OMNeT++ installation
- Check that you have a working INET 2.x framework installation
- Go to the project properties of the 802.15.4 project (ALT+Enter) -> Project References -> Select your INET 2.x installation
- Compile INET 2.x and the the 802.15.4. project
- Start it via the omnetpp.ini inside the simulations folder (Run/Debug As -> OMNeT Simulation)


