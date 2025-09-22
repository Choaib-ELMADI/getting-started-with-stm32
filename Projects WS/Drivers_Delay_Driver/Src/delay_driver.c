#include "delay_driver.h"

void delay_init(void) {
	// Enable timer clock
	RCC->APB1ENR |= (1UL << 0);

	// Disable timer counter
	TIM2->CR1 &= ~(1UL << 0);

	// Calculate and load prescalar value
	TIM2->PSC = 16000 - 1;

	// Calculate and load auto-reload value
	// TIM2->ARR = 0;

	// Enable timer counter
	TIM2->CR1 |= (1UL << 0);
}

void delay(uint32_t delay) {
	TIM2->ARR = delay;
	TIM2->CNT = 0;
	while (TIM2->CNT < TIM2->ARR);
}
