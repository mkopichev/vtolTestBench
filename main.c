#include "inc/common.h"

extern float potFilteredValue, pidOutput, errorCurrent, errorIntegral;

int main(void) {

    // initAll();

    DDRB |= (1 << 0);

    clearAll();

    while(1) {

        for(uint8_t i = 0; i < 255; i = i + 2) {

            uint8_t hue = i;
            for(uint8_t j = 0; j < STRIP_LENGTH; j++) {

                hue = hue + 16;
                hueToRgb(hue, STRIP_BRITHNESS_MEDIUM);
            }
            _delay_ms(30);
        }

        // uartTransmitStr("potValue: ");
        // uarTransmitFloat(potFilteredValue);
        // uartTransmitStr("\t");
        // uartTransmitStr("pidOutput: ");
        // uarTransmitFloat(pidOutput);
        // uartTransmitStr("\t");
        // uartTransmitStr("errorCurrent: ");
        // uarTransmitFloat(errorCurrent);
        // uartTransmitStr("\t");
        // uartTransmitStr("errorIntegral: ");
        // uarTransmitFloat(errorIntegral);
        // uartTransmitStr("\r\n");
    }
}
