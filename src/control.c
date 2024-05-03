#include "../inc/control.h"
extern uint16_t filterValue;

float controlValue = 0.0, valuePID = 0.0;
float errorPrevious = 0.0, errorPresent = 0.001;
float Kp = 1.0, Ki = 0, Kd = 0;
float integral = 0.000001;
float dif = 0.000001;
const float dt = 127.5 / 1000000;

void controlInit(void) {
    TCCR1A = (1 << COM1A1) | (1 << COM1B1) | (1 << WGM11) | (1 << WGM10); // Fast PWM
    TCCR1B = (1 << CS11);                                                 // prescaler 8
    TIMSK1 = (1 << TOIE1);
    sei();
}

ISR(TIMER1_OVF_vect) {
    static uint8_t acsT1Counter = 0;
    if(acsT1Counter < 10)
        acsT1Counter++;
    else {
        errorPresent = VALUE_INSTALL - filterValue;
        integral += errorPresent;
        dif = (errorPresent - errorPrevious);
        errorPrevious = errorPresent;
        valuePID = (Kp * errorPresent) + (Ki * integral * dt) + ((Kd * dif) / dt);
        if(valuePID > 255) {
            controlValue =255
        }
        void motorLaunch(valuePID);
    }
}