#include "../inc/potentiometer.h"

uint16_t potValue = 0;
float potFilteredValue = VALUE_SETPOINT;

void potentiometerInit(void) {

    ADCSRA = (1 << ADEN) | (1 << ADSC) | (1 << ADIE) | (1 << ADPS1) | (1 << ADPS0);
    ADMUX = (1 << REFS0) | POT_ADC_CHANNEL;
    sei();
}

ISR(ADC_vect) {

    potValue = ADCL | (ADCH << 8);
    potFilteredValue = (potFilteredValue * 0.99) + (potValue * 0.01);
    ADMUX = (1 << REFS0) | POT_ADC_CHANNEL;
    ADCSRA |= (1 << ADSC);
}