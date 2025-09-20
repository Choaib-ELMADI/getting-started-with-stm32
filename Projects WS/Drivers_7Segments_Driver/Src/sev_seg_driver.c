#include "sev_seg_driver.h"

// a  --> PA10
// b  --> PB3
// c  --> PB5
// d  --> PB4
// e  --> PB10
// f  --> PA8
// g  --> PA9
// dp --> PC7

void sev_seg_init(void) {
	// Enable internal MCU clock
	RCC->CR |= (1UL << 0);

	// Enable AHB1 bus clock for GPIOA,B,C
	RCC->AHB1ENR |= (1UL << 0) | (1UL << 1) | (1UL << 2);

	// Configure pins as outputs
	// 8 9 10 in GPIOA
	GPIOA->MODER |= (1UL << 16) | (1UL << 18) | (1UL << 20);
	GPIOA->MODER &= ~((1UL << 17) | (1UL << 19) | (1UL << 21));

	// 3 4 5 10 in GPIOB
	GPIOB->MODER |= (1UL << 6) | (1UL << 8) | (1UL << 10) | (1UL << 20);
	GPIOB->MODER &= ~((1UL << 7) | (1UL << 9) | (1UL << 11) | (1UL << 21));

	// 7 in GPIOC
	GPIOC->MODER |= (1UL << 14);
	GPIOC->MODER &= ~(1UL << 15);
}

void sev_seg_print_char(unsigned char data) {
	if ((data & (1UL << 0)) == (1UL << 0)) GPIOA->ODR |= (1UL << 10);
	else GPIOA->ODR &= ~(1UL << 10);

	if ((data & (1UL << 1)) == (1UL << 1)) GPIOB->ODR |= (1UL << 3);
	else GPIOB->ODR &= ~(1UL << 3);

	if ((data & (1UL << 2)) == (1UL << 2)) GPIOB->ODR |= (1UL << 5);
	else GPIOB->ODR &= ~(1UL << 5);

	if ((data & (1UL << 3)) == (1UL << 3)) GPIOB->ODR |= (1UL << 4);
	else GPIOB->ODR &= ~(1UL << 4);

	if ((data & (1UL << 4)) == (1UL << 4)) GPIOB->ODR |= (1UL << 10);
	else GPIOB->ODR &= ~(1UL << 10);

	if ((data & (1UL << 5)) == (1UL << 5)) GPIOA->ODR |= (1UL << 8);
	else GPIOA->ODR &= ~(1UL << 8);

	if ((data & (1UL << 6)) == (1UL << 6)) GPIOA->ODR |= (1UL << 9);
	else GPIOA->ODR &= ~(1UL << 9);

	if ((data & (1UL << 7)) == (1UL << 7)) GPIOC->ODR |= (1UL << 7);
	else GPIOC->ODR &= ~(1UL << 7);
}
