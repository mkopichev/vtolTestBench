#ifndef CONTROL_H_
#define CONTROL_H_

#include "common.h"

#define VALUE_SETPOINT 500.0
#define VALUE_SETPOINT_MAX 200.0
#define VALUE_ERROR_INTEGRAL_MAX 50000.0

void controlInit(void);

#endif