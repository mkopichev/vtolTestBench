#ifndef CONTROL_H_
#define CONTROL_H_

#include "common.h"

#define VALUE_SETPOINT 505.0
#define VALUE_SETPOINT_MAX 220.0
#define VALUE_ERROR_INTEGRAL_MAX 50000.0

void controlInit(void);

#endif