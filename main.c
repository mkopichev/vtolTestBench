#include "inc/common.h"

extern float potFilteredValue, pidOutput, errorCurrent, errorIntegral;

int main(void) {

    initAll();

    while(1) {

        uartTransmitStr("potValue: ");
        uartTransmitFloat(potFilteredValue);
        uartTransmitStr("\t");
        uartTransmitStr("pidOutput: ");
        uartTransmitFloat(pidOutput);
        uartTransmitStr("\t");
        uartTransmitStr("errorCurrent: ");
        uartTransmitFloat(errorCurrent);
        uartTransmitStr("\t");
        uartTransmitStr("errorIntegral: ");
        uartTransmitFloat(errorIntegral);
        uartTransmitStr("\r\n");
    }
}
