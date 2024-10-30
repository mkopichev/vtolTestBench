#include "../inc/control.h"
extern float potFilteredValue;

float pidOutput = 0.0, errorIntegral = 0.0, errorDif = 0.0, errorPrevious = 0.0, errorCurrent = 0.0;
float Kp = 0.95, Ki = 0.85, Kd = 0.2;
float dt = 2.5 / 1000.0;

void controlInit(void) {

    TCCR1B = (1 << CS11); // prescaler 8
    TIMSK1 = (1 << TOIE1);
    TCNT1 = 0xEC78; // freq = 400 Hz
    sei();
}

ISR(TIMER1_OVF_vect) { // executes once in 2.5 ms

    TCNT1 = 0xEC78;
    errorCurrent = VALUE_SETPOINT - potFilteredValue;
    errorIntegral += errorCurrent;
    errorDif = (errorCurrent - errorPrevious);
    errorPrevious = errorCurrent;

    pidOutput = (Kp * errorCurrent) + (Ki * errorIntegral * dt) + (Kd * errorDif / dt);

    if((pidOutput > VALUE_SETPOINT_MAX) || (pidOutput < -VALUE_SETPOINT_MAX)) {

        pidOutput = VALUE_SETPOINT_MAX;
    }
    motorLaunch(pidOutput);
}