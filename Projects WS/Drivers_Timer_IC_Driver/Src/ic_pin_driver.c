#include "ic_pin_driver.h"

void ic_pin_init(void) {
	// Enable MCU internal clock
	RCC->CR |= (1UL << 0);

	// Enable GPIOA clock
	RCC->AHB1ENR |= (1UL << 0);

	// Set PA6 pin mode --> Alternate function
	GPIOA->MODER &= ~(1UL << 12);
	GPIOA->MODER |= (1UL << 13);

	// Select PA6 pin alternate function --> Input capture
	GPIOA->AFR[0] |= (1UL << 25);
	GPIOA->AFR[0] &= ~((1UL << 24) | (1UL << 26) | (1UL << 27));
}
