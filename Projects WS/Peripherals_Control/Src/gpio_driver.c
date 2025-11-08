#include "gpio_driver.h"

void delay(unsigned long delay) {
	for (int i=0; i<delay; ++i);
}

void gpio_init(void) {
	// Allow clock access to GPIOs
	RCC_AHB1ENR |= (1 << 0);
	RCC_AHB1ENR |= (1 << 1);
	RCC_AHB1ENR |= (1 << 2);

	// Init green led: PA5 -> bits 11:10
	GPIOA_MODER &= ~(1 << 11);
	GPIOA_MODER |= (1 << 10);

	// Init red led: PB9 -> bits 19:18
	GPIOB_MODER &= ~(1 << 19);
	GPIOB_MODER |= (1 << 18);

	// Init user button: PC13 -> bits 27:26
	GPIOC_MODER &= ~((1 << 27) | (1 << 26));

	// Init PA2 alternate function -> bits 5:4
	GPIOA_MODER |= (1 << 5);
	GPIOA_MODER &= ~(1 << 4);

	// Init PA3 alternate function -> bits 7:6
	GPIOA_MODER |= (1 << 7);
	GPIOA_MODER &= ~(1 << 6);

	// Init PA0 as analog input -> bits 1:0
	GPIOA_MODER |= ((1 << 1) | (1 << 0));
}

void green_led_on(void) {
	GPIOA_ODR |= (1 << 5);
}
void green_led_off(void) {
	GPIOA_ODR &= ~(1 << 5);
}

void red_led_on(void) {
	GPIOB_ODR |= (1 << 9);
}
void red_led_off(void) {
	GPIOB_ODR &= ~(1 << 9);
}

void led_toggle(void) {
	GPIOA_ODR ^= (1 << 5);
	GPIOB_ODR ^= (1 << 9);
	delay(500000);
}

void set_program_state(int *state) {
	if (!(GPIOC_IDR & (1 << 13))) {
		if (*state == OFF) {
			*state = ON;
			delay(100000);
		} else if (*state == ON) {
			*state = OFF;
			delay(100000);
		}
	}
}
void show_program_state(int *state) {
	if (*state == OFF) {
		red_led_on();
		green_led_off();
	} else if (*state == ON) {
		red_led_off();
		green_led_on();
	}
}
