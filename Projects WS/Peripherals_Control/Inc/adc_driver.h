#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_

#include "base.h"

#define ADC_SR_OFFSET      (0x00)
#define ADC_CR1_OFFSET     (0x04)
#define ADC_CR2_OFFSET     (0x08)
#define ADC_SMPR1_OFFSET   (0x0C)
#define ADC_SQR1_OFFSET    (0x2C)
#define ADC_SQR3_OFFSET    (0x34)
#define ADC_DR_OFFSET      (0x4C)

#define ADC_SR             (*(volatile unsigned int *)(ADC_PERI_BASE + ADC_SR_OFFSET))
#define ADC_CR1            (*(volatile unsigned int *)(ADC_PERI_BASE + ADC_CR1_OFFSET))
#define ADC_CR2            (*(volatile unsigned int *)(ADC_PERI_BASE + ADC_CR2_OFFSET))
#define ADC_SMPR1          (*(volatile unsigned int *)(ADC_PERI_BASE + ADC_SMPR1_OFFSET))
#define ADC_SQR1           (*(volatile unsigned int *)(ADC_PERI_BASE + ADC_SQR1_OFFSET))
#define ADC_SQR3           (*(volatile unsigned int *)(ADC_PERI_BASE + ADC_SQR3_OFFSET))
#define ADC_DR             (*(volatile unsigned int *)(ADC_PERI_BASE + ADC_DR_OFFSET))

#define RCC_APB2ENR_OFFSET (0x44)
#define RCC_APB2ENR        (*(volatile unsigned int *)(RCC_PERI_BASE + RCC_APB2ENR_OFFSET))

void adc_init(void);

void adc_start_conversion(void);
int adc_read(void);

void sample_adc_signal(char*, int*);
void transmit_adc_signal(char*);

#endif // ADC_DRIVER_H_
