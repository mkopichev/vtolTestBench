#include "inc/common.h"

//extern uint16_t potentiometerValue;
extern uint16_t filteredValue;
void initAll(void);

int main(void) {

    initAll();

    while(1) {
        void motorLaunch(50);
        uartTransmitDec(filteredValue);
        uartTransmitStr("\r\n");
    }
}

void initAll() {

    serviceLedInit();
    uartInit();
    potentiometerInit();
    motorInit();
    //controlInit();
    _delay_ms(100);
}