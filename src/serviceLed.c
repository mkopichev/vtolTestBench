#include "../inc/serviceLed.h"

void serviceLedInit(void) {

    DDRB |= (1 << 5);
    TCCR2B = (1 << CS21); // prescaler 8
    TIMSK2 = (1 << TOIE2);
    sei();
}

ISR(TIMER2_OVF_vect) { // 128 us ovf period

    static uint16_t t2_counter = 0;

    if(t2_counter < ((LED_FLASHING_PERIOD * 1000000.0) / 128.0)) {
        t2_counter++;
    } else {
        t2_counter = 0;
        PORTB ^= (1 << 5);
    }
}