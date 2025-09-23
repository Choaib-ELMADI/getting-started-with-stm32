#include "led_driver.h"

void led_init(void) {
	// Enable MCU internal clock
	RCC->CR |= (1UL << 0);

	// Enable GPIOA clock
	RCC->AHB1ENR |= (1UL << 0);

	// Set PA5 pin mode
	GPIOA->MODER &= ~(1UL << 10);
	GPIOA->MODER |= (1UL << 11);

	// Select PA5 pin alternate function
	GPIOA->AFR[0] |= (1UL << 20);
	GPIOA->AFR[0] &= ~((1UL << 21) | (1UL << 22) | (1UL << 23));
}

void led_on(void) {
	GPIOA->ODR |= (1UL << 5);
}

void led_off(void) {
	GPIOA->ODR &= ~(1UL << 5);
}

void led_toggle(void) {
	GPIOA->ODR ^= (1UL << 5);
}
