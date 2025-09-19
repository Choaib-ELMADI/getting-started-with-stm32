#include "usart_driver.h"

void uart_tx_init(unsigned long baudrate) {
	// Enable peripherals clock
	RCC->APB1ENR |= (1UL << 17); // For USART2
	RCC->AHB1ENR |= (1UL << 0);  // For GPIOA

	// Set PA2 pin mode as alternate function mode
	GPIOA->MODER |= (1UL << 5);
	GPIOA->MODER &= ~(1UL << 4);

	// Set alternate function of PA2 pin as USART2 TX
	GPIOA->AFR[0] |= (1UL << 8) | (1UL << 9) | (1UL << 10);
	GPIOA->AFR[0] &= ~(1UL << 11);

	// Configure baudrate
	USART2->BRR = (16000000 + (baudrate / 2U)) / baudrate;

	// Configure transfer direction
	USART2->CR1 |= (1UL << 3);

	// Enable the USART module
	USART2->CR1 |= (1UL << 13);
}

void uart_transfer(unsigned char *data) {

}

void uart_write(unsigned char data) {

}
