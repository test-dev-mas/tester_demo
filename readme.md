# In-Circuit Tester

## Relays on Test Points
These two files are written to implement functions on tester.
- tester.cpp
- tester.h

### Relay Address
- Each relay is connected to one of 16 outputs on one of 4 HC154
- Each relay is addressed by an 8-bit address, e.g. 0b01110000 (relay 1 on U1)
- Higher 4 bits address one of 4 HC154
- Lower 4 bits address one of 16 outputs
- In total, there are 64 relays on one ICT board, these addresses are put in a array named uint8_t test_points[] in hexadecimal form
- To call one relay, simply pass its address to relay_call() function, i.e. relay_call(test_pints[10])

### Relay Call
- In total, 8 wires/GPIO need to be toggled to select/activate one particular relay
- The togglings are put inside one function to modulize code
- Each bit position is checked against a bit mask
- Toggling is done with a ternary operator

## microBUS socket
The socket is included on tester to accommodate various test products that conforms the microBUS standard. The multimeter click is the most commonly used.

### The Socket

### Multimeter Click