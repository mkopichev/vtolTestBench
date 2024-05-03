#ifndef MOTOR_H_
#define MOTOR_H_

#include "common.h"

#define MOTOR_CW  false
#define MOTOR_CCW true

void motorInit(void);
void motorLaunch(bool direction, uint8_t speed);

#endif