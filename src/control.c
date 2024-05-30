#include "../inc/control.h"
extern float filteredValue;

float controlValue = 0.0, valuePID = 0.0;
float errorPrevious = 0.0, errorPresent = 0.0;
float KpDistant = 0.9, KiDistant = 0.9, KdDistant = 0.2;
float KpNear = 1.0, KiNear = 2.0, KdNear = 0.021;
float integral = 0.0;
float dif = 0.0;
float dt = 2.5 / 1000.0;

void controlInit(void) {
    TCCR1B = (1 << CS11); // prescaler 8
    TIMSK1 = (1 << TOIE1);
    TCNT1 = 0xEC7B;
    sei();
}

ISR(TIMER1_OVF_vect) {
    TCNT1 = 0xEC7B;

    // if(VALUE_INSTALL < filteredValue) {
    //     errorPresent = filteredValue - ;
    // }
    errorPresent = VALUE_INSTALL - filteredValue;
    integral += errorPresent;
    // if(integral > 10000) {
    //     integral = 10000;
    // } 
    dif = (errorPresent - errorPrevious);
    errorPrevious = errorPresent;
    // if (errorPresent<10){
    //     valuePID = (KpNear * errorPresent) + (KiNear * integral * dt) + (KdNear * dif / dt);}
    // else
    // {
        valuePID = (KpDistant * errorPresent) + (KiDistant * integral * dt) + (KdDistant * dif / dt);
    // }
    if(valuePID > 200.0) {
        valuePID = 200.0;
    }
    //valuePID += 128;
    motorLaunch(valuePID);
}