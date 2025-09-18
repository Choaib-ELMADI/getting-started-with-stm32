#include "led_driver.h"

void led_init(void) {
	// Enable the clock of GPIOA
	RCC->AHB1ENR |= (1UL << 0);

	// Configure PA5 pin as output
	GPIOA->MODER |= (1UL << 10);
	GPIOA->MODER &= ~(1UL << 11);
}

void led_on(void) {
	// Turn ON PA5 pin
	GPIOA->ODR |= (1UL << 5);
}

void led_off(void) {
	// Turn OFF PA5 pin
	GPIOA->ODR &= ~(1UL << 5);
}
