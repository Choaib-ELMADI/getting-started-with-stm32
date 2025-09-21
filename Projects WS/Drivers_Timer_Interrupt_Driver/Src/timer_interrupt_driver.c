#include "timer_interrupt_driver.h"

void systick_timer_init(void) {
	SysTick->CTRL |= (1UL << 0) | (1UL << 1) | (1UL << 2);
	SysTick->LOAD = (16000000 - 1);
}

void SysTick_Handler(void) {
	led_toggle();
}
