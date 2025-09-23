#include "timer_oc_mode_driver.h"

void timer_oc_mode_init(void) {
	// Enable TIM2 clock
	RCC->APB1ENR |= (1UL << 0);

	// ARR and CNT registers on match action
	TIM2->CCMR1 &= ~((1UL << 0) | (1UL << 1));
	TIM2->CCMR1 |= (1UL << 4) | (1UL << 5);
	TIM2->CCMR1 &= ~(1UL << 6);

	// Enbale TIM2 output compare
	TIM2->CCER |= (1UL << 0);

	// Configure timer frequency
	TIM2->PSC = 16000 - 1;

	// Configure match period
	TIM2->ARR = 1000 - 1;

	// Initialize timer counter
	TIM2->CNT = 0;

	// Turn ON timer
	TIM2->CR1 |= (1UL << 0);
}
