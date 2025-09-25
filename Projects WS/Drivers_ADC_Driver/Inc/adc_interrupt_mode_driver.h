#ifndef ADC_INTERRUPT_MODE_DRIVER_H_
#define ADC_INTERRUPT_MODE_DRIVER_H_

#include "stm32f446xx.h"

void adc_interrupt_init(void);
void ADC_IRQHandler(void);

#endif // ADC_INTERRUPT_MODE_DRIVER_H_
