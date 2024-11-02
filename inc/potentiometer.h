#ifndef POTENTIOMETER_H_
#define POTENTIOMETER_H_

#include "common.h"

#define POT_ADC_CHANNEL 0
#define LPF_BETA 0.99 // 0.0...1.0

void potentiometerInit(void);

#endif