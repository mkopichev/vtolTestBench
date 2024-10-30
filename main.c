#include "inc/common.h"

extern float potFilteredValue;
extern float pidOutput;

int main(void) {

    initAll();

    while(1) {

        uartTransmitStr("potValue: ");
        uarTransmitFloat(potFilteredValue);
        uartTransmitStr("\t");
        uartTransmitStr("pidOutput: ");
        uarTransmitFloat(pidOutput);
        uartTransmitStr("\r\n");
    }
}
