#include "../inc/motor.h"

void motorInit(void) {
    DDRD |= (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6);
    PORTD |= (1 << 3) | (1 << 4);// PWM on OC0A and OC0B, PWM frequency 7.8 kHz
    TCCR0A = (1 << COM0A1) | (1 << COM0B1) | (1 << WGM01) | (1 << WGM00); // Fast PWM
    TCCR0B = (1 << CS01);                                                 // prescaler 8
}


void motorLaunch(uint8_t speed) {

    OCR0B = 0;
    OCR0A = speed;
}