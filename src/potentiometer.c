#include "../inc/potentiometer.h"

uint16_t potentiometerValue = 0;
float filteredValue;
void potentiometerInit(void) {

    ADCSRA = (1 << ADEN) | (1 << ADSC) | (1 << ADIE) | (1 << ADPS1) |  (1 << ADPS0);
    ADMUX = (1 << REFS0) | POTENTIOMETER_ADC_CHANNEL;
    sei();
}

ISR(ADC_vect) {

    potentiometerValue = ADCL | (ADCH << 8);
    filteredValue = (filteredValue * 0.99) + (potentiometerValue * 0.01);
    ADMUX = (1 << REFS0) | POTENTIOMETER_ADC_CHANNEL;
    ADCSRA |= (1 << ADSC);
}