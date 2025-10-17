#include "../inc/control.h"

extern float potFilteredValue;

float pidOutput = 0.0, errorIntegral = 0.0, errorDif = 0.0, errorPrevious = 0.0, errorCurrent = 0.0;
float Kp = 0.95, Ki = 1.75, Kd = 0.25;
float dt = 2.5 / 1000.0;

bool angleExcessFlag = false;
static uint16_t t1Counter = 0;

void controlInit(void) {

    TCCR1B = (1 << CS11); // prescaler 8
    TIMSK1 = (1 << TOIE1);
    TCNT1 = 0xEC78; // freq = 400 Hz
    sei();
}

#pragma GCC push_options
#pragma GCC optimize("O0")

ISR(TIMER1_OVF_vect) { // executes once in 2.5 ms

    TCNT1 = 0xEC78;

    errorCurrent = VALUE_SETPOINT - potFilteredValue;
    errorIntegral += errorCurrent;
    // check for integral error value top and bottom limits (for preventing the pidOutput rapid increase)
    if((errorIntegral > VALUE_ERROR_INTEGRAL_MAX) || (errorIntegral < -VALUE_ERROR_INTEGRAL_MAX)) {

        if(errorIntegral > VALUE_ERROR_INTEGRAL_MAX)
            errorIntegral = VALUE_ERROR_INTEGRAL_MAX;
        else
            errorIntegral = -VALUE_ERROR_INTEGRAL_MAX;
    }
    errorDif = (errorCurrent - errorPrevious);
    errorPrevious = errorCurrent;

    pidOutput = (Kp * errorCurrent) + (Ki * errorIntegral * dt) + (Kd * errorDif / dt);

    // check for pid control variable top and bottom limits
    if((pidOutput > VALUE_SETPOINT_MAX) || (pidOutput < -VALUE_SETPOINT_MAX)) {

        pidOutput = VALUE_SETPOINT_MAX;
    }

    // check for lever angle and if it is too high - motor goes off
    if((potFilteredValue > 600.0) && (!angleExcessFlag)) {

        angleExcessFlag = true;
        uartTransmitStr("Danger, angle excess\r\n");
    }

    if(angleExcessFlag) {

        if(t1Counter++ < 2000) {

            pidOutput = 0.0;
        } else {

            t1Counter = 0;
            angleExcessFlag = false;
        }
    }

    motorLaunch(pidOutput);

    static uint8_t ledStripTimeCounter = 0, i = 0, j = 0, hue = 0;

    if(ledStripTimeCounter < ((errorCurrent >= 0) ? ((uint8_t)errorCurrent / 2) : ((uint8_t)(-errorCurrent / 2)))) {

        ledStripTimeCounter++;
    } else {

        ledStripTimeCounter = 0;
        hue = i;
        for(j = 0; j < STRIP_LENGTH; j++) {

            hue = hue + 16;
            hueToRgb(hue, STRIP_BRITHNESS_MEDIUM);
        }
        i += 2;
    }
}

#pragma GCC pop_options
