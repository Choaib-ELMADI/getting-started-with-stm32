#include "external_interrupt_driver.h"

void exti_init(void) {
	// Enable the clock for syscfg controller
	RCC->APB2ENR |= (1UL << 14);

	// Unmask the interrupt request line
	EXTI->IMR |= (1UL << 13);

	// Select the interrupt input source
	SYSCFG->EXTICR[3] |= (1UL << 5);
	SYSCFG->EXTICR[3] &= ~((1UL << 4) | (1UL << 6) | (1UL << 7));

	// Set the interrupt trigger configuration
	EXTI->RTSR &= ~(1UL << 13);
	EXTI->FTSR |= (1UL << 13);

	// Set the interrupt priority
	NVIC_SetPriority(EXTI15_10_IRQn, 15);

	// Enable the interrupt
	NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void EXTI15_10_IRQHandler(void) {
	// Debouncing...
	if (EXTI->PR & (1UL << 13)) {
		EXTI->PR |= (1UL << 13);
		GPIOA->ODR ^= (1UL << 5);
	}
}
