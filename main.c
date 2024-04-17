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

    DDRB |= (1 << 5);
    uartInit();
    potentiometerInit();
    _delay_ms(100);
}