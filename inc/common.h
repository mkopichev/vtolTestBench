#ifndef COMMON_H_
#define COMMON_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "uart.h"
#include "potentiometer.h"
#include "serviceLed.h"
#include "motor.h"
#include "control.h"

uint8_t digit(uint16_t d, uint8_t m);

#endif