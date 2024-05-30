#include "inc/common.h"

//extern uint16_t potentiometerValue;
extern float filteredValue;
extern float valuePID;
void initAll(void);

int main(void) {

    initAll();

    while(1) {
        //motorLaunch(200);
        // uarTransmitFloat(filteredValue);
        // uartTransmitStr("\t");
        uarTransmitFloat(valuePID);
        //uartTransmitDec(filteredValue);
        uartTransmitStr("\r\n");
        
    }
}

void initAll() {

    serviceLedInit();
    uartInit();
    potentiometerInit();
    motorInit();
   controlInit();
    _delay_ms(100);
}