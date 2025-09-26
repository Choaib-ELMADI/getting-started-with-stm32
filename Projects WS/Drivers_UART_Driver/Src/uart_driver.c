#include "uart_driver.h"

void uart_tx_init(void) {
	// UART/USART --> PA2 - TX

	// Enable internal MCU clock
	RCC->CR |= (1UL << 0);

	// Enable PA2 pin GPIO clock
	RCC->AHB1ENR |= (1UL << 0);

	// Set PA2 mode to alternate function
	GPIOA->MODER &= ~(1UL << 4);
	GPIOA->MODER |= (1UL << 5);

	// Choose USART2 TX channel function for PA2 --> AF7
	GPIOA->AFR[0] |= (1UL << 8) | (1UL << 9) | (1UL << 10);
	GPIOA->AFR[0] &= ~(1UL << 11);

	// Enable USART2 clock
	RCC->APB1ENR |= (1UL << 17);

	// Set USART2 baudrate
	USART2->BRR = ((SYSCLOCK + (BAUDRATE / 2U)) / BAUDRATE);

	// Enable TX
	USART2->CR1 |= (1UL << 3);

	// Enable USART2
	USART2->CR1 |= (1UL << 13);
}

void uart_tx_write(unsigned char data) {
	// Wait for data to be transferred to the shift register
	while (!(USART2->SR & (1UL << 7)));

	// Write a byte to USART2 bus
	USART2->DR  = data;
}
