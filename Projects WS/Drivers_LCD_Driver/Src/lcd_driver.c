#include "lcd_driver.h"

void convert_char_bits(unsigned char data) {
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

void gpio_init(void) {
	// Enable internal MCU clock
	RCC->CR |= (1UL << 0);

	// Enable AHB1 bus clock for GPIOA,B,C
	RCC->AHB1ENR |= (1UL << 0) | (1UL << 1) | (1UL << 2);

	// Configure pins as outputs
	// 6 7 8 9 10 in GPIOA
	GPIOA->MODER |= (1UL << 12) | (1UL << 14) | (1UL << 16) | (1UL << 18) | (1UL << 20);
	GPIOA->MODER &= ~((1UL << 13) | (1UL << 15) | (1UL << 17) | (1UL << 19) | (1UL << 21));

	// 3 4 5 6 10 in GPIOB
	GPIOB->MODER |= (1UL << 6) | (1UL << 8) | (1UL << 10) | (1UL << 12) | (1UL << 20);
	GPIOB->MODER &= ~((1UL << 7) | (1UL << 9) | (1UL << 11) | (1UL << 13) | (1UL << 21));

	// 7 in GPIOC
	GPIOC->MODER |= (1UL << 14);
	GPIOC->MODER &= ~(1UL << 15);
}

void lcd_enable_data_latch(void) {
	GPIOA->ODR |= (1UL << 6);
}
void lcd_disable_data_latch(void) {
	GPIOA->ODR &= ~(1UL << 6);
}
void lcd_enable_read(void) {
	GPIOA->ODR |= (1UL << 7);
}
void lcd_enable_write(void) {
	GPIOA->ODR &= ~(1UL << 7);
}
void lcd_enable_dr(void) {
	GPIOB->ODR &= ~(1UL << 6);
}
void lcd_enable_ir(void) {
	GPIOB->ODR |= (1UL << 6);
}

void lcd_data(unsigned char data) {
	convert_char_bits(data);
	lcd_enable_write();
	lcd_enable_dr();
	lcd_enable_data_latch();
	// Wait...
	lcd_disable_data_latch();
}
void lcd_command(unsigned char command) {
	convert_char_bits(command);
	lcd_enable_write();
	lcd_enable_ir();
	lcd_enable_data_latch();
	// Wait...
	lcd_disable_data_latch();
}
void lcd_print_string(unsigned char *buffer, unsigned char length) {
	for (unsigned char i=0; i<length; ++i) {
		lcd_data(buffer[i]);
	}
}

void lcd_init(void) {
	lcd_command(0x38);  // 16x2 LCD format
	lcd_command(0x06);  // Display ON, cursor OFF
	lcd_command(0x0C);  // Auto increment cursor
	lcd_command(0x01);  // Clear screen
}
