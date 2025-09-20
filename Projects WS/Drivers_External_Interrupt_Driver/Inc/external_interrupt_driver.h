#ifndef EXTERNAL_INTERRUPT_DRIVER_H_
#define EXTERNAL_INTERRUPT_DRIVER_H_

#include "stm32f446xx.h"
#include "led_driver.h"

void exti_init(void);
void EXTI15_10_IRQHandler(void);

#endif // EXTERNAL_INTERRUPT_DRIVER_H_
