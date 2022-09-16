#include <stdint.h>

extern uint8_t test_points[64];

void init_tester();
void relay_call(uint8_t pin);

#define RT68_ON     PORTB|=(1<<PB7);
#define RT68_OFF    PORTB&=~(1<<PB7);