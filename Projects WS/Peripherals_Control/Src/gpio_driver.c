#include "gpio_driver.h"

void delay(void) {
	for (int i=0; i<100000; ++i);
}

void gpio_init(void) {
	// Init green led: PA5 -> bits 11:10
	RCC_AHB1ENR |= (1 << 0);
	GPIOA_MODER |= (1 << 10);
	GPIOA_MODER &= ~(1 << 11);

	// Init red led: PB9 -> bits 19:18
	RCC_AHB1ENR |= (1 << 1);
	GPIOB_MODER |= (1 << 18);
	GPIOB_MODER &= ~(1 << 19);

	// Init user button: PC13 -> bits 27:26
	RCC_AHB1ENR |= (1 << 2);
	GPIOC_MODER &= ~((1 << 27) | (1 << 26));
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
	delay();
}

void set_program_state(int *state) {
	if (!(GPIOC_IDR & (1 << 13))) {
		if (*state == OFF) {
			*state = ON;
		}
		else if (*state == ON) {
			*state = OFF;
		}

		delay();
	}
}
void show_program_state(int *state) {
	if (*state == OFF) {
		red_led_on();
		green_led_off();
	}
	else if (*state == ON) {
		red_led_off();
		green_led_on();
	}
}
