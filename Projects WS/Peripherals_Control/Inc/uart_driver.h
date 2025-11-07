#ifndef UART_DRIVER_H_
#define UART_DRIVER_H_

#include <stdint.h>
#include "base.h"

#define USART_SR_OFFSET    (0x00)
#define USART_DR_OFFSET    (0x04)
#define USART_BRR_OFFSET   (0x08)
#define USART_CR1_OFFSET   (0x0C)

#define USART_SR           (*(volatile unsigned int *)(UART_PERI_BASE + USART_SR_OFFSET))
#define USART_DR           (*(volatile unsigned int *)(UART_PERI_BASE + USART_DR_OFFSET))
#define USART_BRR          (*(volatile unsigned int *)(UART_PERI_BASE + USART_BRR_OFFSET))
#define USART_CR1          (*(volatile unsigned int *)(UART_PERI_BASE + USART_CR1_OFFSET))

#define GPIOA_AFRL_OFFSET  (0x20)
#define GPIOA_AFRL         (*(volatile unsigned int *)(GPIOA_PERI_BASE + GPIOA_AFRL_OFFSET))

#define RCC_APB1ENR_OFFSET (0x40)
#define RCC_APB1ENR        (*(volatile unsigned int *)(RCC_PERI_BASE + RCC_APB1ENR_OFFSET))

void usart2_init(void);

void usart2_write(char);
uint32_t usart2_read(void);

void usart2_set_baudrate(uint32_t, uint32_t);

#endif // UART_DRIVER_H_
