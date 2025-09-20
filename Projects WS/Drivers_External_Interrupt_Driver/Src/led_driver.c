#include "led_driver.h"

void led_init(void) {
	RCC->CR |= (1UL << 0);
	RCC->AHB1ENR |= (1UL << 0);
	GPIOA->MODER |= (1UL << 10);
	GPIOA->MODER &= ~(1UL << 11);
}

void led_on(void) {
	GPIOA->ODR |= (1UL << 5);
}

void led_off(void) {
	GPIOA->ODR &= ~(1UL << 5);
}
