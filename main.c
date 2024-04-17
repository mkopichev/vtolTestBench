#include "inc/common.h"

void initAll(void);

int main(void) {

    initAll();

    while(1) {

        uartTransmitStr("A\r\n");
    }
}

void initAll() {

    DDRB |= (1 << 5);
    uartInit();
    _delay_ms(100);
}