#include "../inc/common.h"

void initAll() {

    serviceLedInit();
    uartInit();
    potentiometerInit();
    motorInit();
    controlInit();
    ledStripInit();
    _delay_ms(100);
}

uint8_t digit(uint16_t d, uint8_t m) {

    uint8_t i = 5, a;
    while(i) {      // цикл по разрядам числа
        a = d % 10; // выделяем очередной разряд
        // выделен заданный разряд - уходим
        if(i-- == m)
            break;
        d /= 10; // уменьшаем число в 10 раз
    }
    return (a);
}