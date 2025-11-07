#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

#include "base.h"

#define GPIOA_MODER_OFFSET (0x00)
#define GPIOA_ODR_OFFSET   (0x14)
#define GPIOB_MODER_OFFSET (0x00)
#define GPIOB_ODR_OFFSET   (0x14)
#define GPIOC_MODER_OFFSET (0x00)
#define GPIOC_IDR_OFFSET   (0x10)
#define RCC_AHB1ENR_OFFSET (0x30)

#define GPIOA_MODER        (*(volatile unsigned int *)(GPIOA_PERI_BASE + GPIOA_MODER_OFFSET))
#define GPIOA_ODR          (*(volatile unsigned int *)(GPIOA_PERI_BASE + GPIOA_ODR_OFFSET))
#define GPIOB_MODER        (*(volatile unsigned int *)(GPIOB_PERI_BASE + GPIOB_MODER_OFFSET))
#define GPIOB_ODR          (*(volatile unsigned int *)(GPIOB_PERI_BASE + GPIOB_ODR_OFFSET))
#define GPIOC_MODER        (*(volatile unsigned int *)(GPIOC_PERI_BASE + GPIOC_MODER_OFFSET))
#define GPIOC_IDR          (*(volatile unsigned int *)(GPIOC_PERI_BASE + GPIOC_IDR_OFFSET))
#define RCC_AHB1ENR        (*(volatile unsigned int *)(RCC_PERI_BASE + RCC_AHB1ENR_OFFSET))

#endif // GPIO_DRIVER_H_
