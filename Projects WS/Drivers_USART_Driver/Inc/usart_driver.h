#ifndef USART_DRIVER_H_
#define USART_DRIVER_H_

#include "stm32f446xx.h"

void uart_tx_init(unsigned long);
void uart_transfer(unsigned char *);
void uart_write(unsigned char);

#endif // USART_DRIVER_H_
