#include "../inc/potentiomter.h"

uint16_t potentiometerValue = 0;

void potentiometerInit(void) {

    ADCSRA = (1 << ADEN) | (1 << ADSC) | (1 << ADIE) | (1 << ADPS2);
    ADMUX = (1 << REFS0) | POTENTIOMETER_ADC_CHANNEL;
    sei();
}

ISR(ADC_vect){

    potentiometerValue = ADCL | (ADCH << 8);
    ADMUX = (1 << REFS0) | POTENTIOMETER_ADC_CHANNEL;
    ADCSRA |= (1 << ADSC);
}