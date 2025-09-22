#ifndef DELAY_DRIVER_H_
#define DELAY_DRIVER_H_

#include <stdint.h>

#include "stm32f446xx.h"

void delay_init(void);
void delay(uint32_t);

#endif // DELAY_DRIVER_H_
