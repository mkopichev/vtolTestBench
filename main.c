#include "inc/common.h"

extern float potFilteredValue, pidOutput, errorCurrent, errorIntegral;

int main(void) {

    initAll();

    while(1) {

        uartTransmitStr("potValue: ");
        uarTransmitFloat(potFilteredValue);
        uartTransmitStr("\t");
        uartTransmitStr("pidOutput: ");
        uarTransmitFloat(pidOutput);
        uartTransmitStr("\t");
        uartTransmitStr("errorCurrent: ");
        uarTransmitFloat(errorCurrent);
        uartTransmitStr("\t");
        uartTransmitStr("errorIntegral: ");
        uarTransmitFloat(errorIntegral);
        uartTransmitStr("\r\n");
    }
}
