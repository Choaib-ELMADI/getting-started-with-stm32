#include "timer_ic_mode_driver.h"

void timer_ic_mode_init(void) {
	// Enable TIM3 clock
	RCC->APB1ENR |= (1UL << 1);

	// Set timer prescalar
	TIM3->PSC = 1600 - 1;

	// Set timer channel mode
	TIM3->CCMR1 |= (1UL << 0);
	TIM3->CCMR1 &= ~(1UL << 1);

	// Set timer channel polarity
	TIM3->CCER |= (1UL << 0);
	TIM3->CCER &= ~((1UL << 1) | (1UL << 3));

	// Turn ON timer
	TIM3->CR1 |= (1UL << 0);
}
