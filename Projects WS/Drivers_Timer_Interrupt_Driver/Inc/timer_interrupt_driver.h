#ifndef TIMER_INTERRUPT_DRIVER_H_
#define TIMER_INTERRUPT_DRIVER_H_

#include "stm32f446xx.h"
#include "led_driver.h"

void systick_timer_init(void);
void SysTick_Handler(void);

#endif // TIMER_INTERRUPT_DRIVER_H_
