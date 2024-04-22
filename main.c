#include "inc/common.h"

extern uint16_t potentiometerValue;

void initAll(void);

int main(void) {

    initAll();

    while(1) {

        uartTransmitDec(potentiometerValue);
        uartTransmitStr("\r\n");
    }
}

void initAll() {

    serviceLedInit();
    uartInit();
    potentiometerInit();
    motorInit();
    _delay_ms(100);
}