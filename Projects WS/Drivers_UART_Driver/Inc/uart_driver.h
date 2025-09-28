#ifndef UART_DRIVER_H_
#define UART_DRIVER_H_

#include "stm32f446xx.h"

#define BAUDRATE 115200
#define SYSCLOCK 16000000

void uart_tx_init(void);
void uart_rx_init(void);
void uart_tx_write(unsigned char);
void uart_rx_read(void);
void uart_rx_interrupt_init(void);
void USART2_IRQHandler(void);

#endif // UART_DRIVER_H_
