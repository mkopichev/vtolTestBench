#include "../inc/motor.h"

void motorInit(void) {

    DDRD |= (1 << 5) | (1 << 6);
    // PWM on OC0A and OC0B, PWM frequency 7.8 kHz
    TCCR0A = (1 << COM0A1) | (1 << COM0B1) | (1 << WGM01) | (1 << WGM00);
    TCCR0B = (1 << CS01);
}

void motorLaunch(bool direction, uint8_t speed) {

    switch(direction) {
    case MOTOR_CW:
        OCR0B = 0;
        OCR0A = speed;
        break;
    case MOTOR_CCW:
        OCR0A = 0;
        OCR0B = speed;
        break;
    }
    _delay_ms(1);
}