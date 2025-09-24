#include "oc_pin_driver.h"

void oc_pin_init(void) {
	// Enable MCU internal clock
	RCC->CR |= (1UL << 0);

	// Enable GPIOA clock
	RCC->AHB1ENR |= (1UL << 0);

	// Set PA5 pin mode --> Alternate function
	GPIOA->MODER &= ~(1UL << 10);
	GPIOA->MODER |= (1UL << 11);

	// Select PA5 pin alternate function --> Output compare
	GPIOA->AFR[0] |= (1UL << 20);
	GPIOA->AFR[0] &= ~((1UL << 21) | (1UL << 22) | (1UL << 23));
}
