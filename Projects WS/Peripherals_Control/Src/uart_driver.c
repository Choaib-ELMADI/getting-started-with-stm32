#include "uart_driver.h"

#define SR_RXNE (1 << 5)
#define SR_TXE  (1 << 7)

#define CR1_UE  (1 << 13)
#define CR1_RE  (1 << 2)
#define CR1_TE  (1 << 3)

#define PERIPHERAL_CLOCK 180000000
#define BAUDRATE         115200

void usart2_init(void) {
	// Allow clock access to USART2 peripheral
	RCC_APB1ENR |= (1 << 17);

	// Set USART2 pins alternate function mode, in gpio_driver.c

	// Select the alternate function
	GPIOA_AFRL |= ((1 << 10) | (1 << 9) | (1 << 8));
	GPIOA_AFRL &= ~(1 << 11);
	GPIOA_AFRL |= ((1 << 14) | (1 << 13) | (1 << 12));
	GPIOA_AFRL &= ~(1 << 15);

	// Configure baudrate
	usart2_set_baudrate(PERIPHERAL_CLOCK, BAUDRATE);

	// Enable TX and RX
	USART_CR1 |= CR1_TE;
	USART_CR1 |= CR1_RE;

	// Enable USART2 module
	USART_CR1 |= CR1_UE;
}

void usart2_write(char data) {
	while (!(USART_SR & SR_TXE)); // Keep looping if empty
	USART_DR = data;
}
uint32_t usart2_read(void) {
	while (!(USART_SR & SR_RXNE)); // Keep looping if empty
	return (USART_DR & 0xFF);
}

void usart2_set_baudrate(uint32_t peripheral_clock, uint32_t baudrate) {
	USART_BRR = ((peripheral_clock + (baudrate / 2U)) / baudrate);
}
