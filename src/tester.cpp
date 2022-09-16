#include <avr/io.h>
#include "tester.h"

uint8_t test_points[64] = {
    0x70, 0x78, 0x74, 0x7C, 0x72, 0x7A, 0x76, 0x7E, 0x71, 0x79, 0x75, 0x7D, 0x73, 0x7B, 0x77, 0x7F,\
    0xB0, 0xB8, 0xB4, 0xBC, 0xB2, 0xBA, 0xB6, 0xBE, 0xB1, 0xB9, 0xB5, 0xBD, 0xB3, 0xBB, 0xB7, 0xBF,\
    0xD0, 0xD8, 0xD4, 0xDC, 0xD2, 0xDA, 0xD6, 0xDE, 0xD1, 0xD9, 0xD5, 0xDD, 0xD3, 0xDB, 0xD7, 0xDF,\
    0xE0, 0xE8, 0xE4, 0xEC, 0xE2, 0xEA, 0xE6, 0xEE, 0xE1, 0xE9, 0xE5, 0xED, 0xE3, 0xEB, 0xE7, 0xEF};

void init_tester() {
    DDRB |= (1 << PB6) | (1 << PB7);                                        // RT68 (MULTIMETER) COIL, initialize both pins to OUTPUT LOW

    /*  HC154 chip select
        U1 - D2 (PE4)
        U2 - D3 (PE5)
        U3 - D4 (PG5)
        U4 - D5 (PE3)
    */
    DDRE |= (1 << PE3) | (1 << PE4) | (1 << PE5);                         
    PORTE |= (1 << PE3) | (1 << PE4) | (1 << PE5);                          // HIGH to disable       
    DDRG |= (1 << PG5);
    PORTG |= (1 << PG5);                                                    // HIGH to disable

    /*  HC154 input 
        A0 - D6 (PH3)
        A1 - D7 (PH4)
        A2 - D8 (PH5)
        A3 - D9 (PH6)
    */
    DDRH |= (1 << PH3) | (1 << PH4) | (1 << PH5) | (1 << PH6);
    PORTH |= (1 << PH3) | (1 << PH4) | (1 << PH5) | (1 << PH6);
}

void relay_call(uint8_t pin) {
    (pin & 0x80) ? (PORTE |= (1 << PE4)) : (PORTE &= ~(1 << PE4));          // U1
    (pin & 0x40) ? (PORTE |= (1 << PE5)) : (PORTE &= ~(1 << PE5));          // U2
    (pin & 0x20) ? (PORTG |= (1 << PG5)) : (PORTG &= ~(1 << PG5));          // U3
    (pin & 0x10) ? (PORTE |= (1 << PE3)) : (PORTE &= ~(1 << PE3));          // U4
    (pin & 0x08) ? (PORTH |= (1 << PH3)) : (PORTH &= ~(1 << PH3));          // A0
    (pin & 0x04) ? (PORTH |= (1 << PH4)) : (PORTH &= ~(1 << PH4));          // A1
    (pin & 0x02) ? (PORTH |= (1 << PH5)) : (PORTH &= ~(1 << PH5));          // A2
    (pin & 0x01) ? (PORTH |= (1 << PH6)) : (PORTH &= ~(1 << PH6));          // A3
}