#ifndef ADC_ONE_SHOT_MODE_DRIVER_H_
#define ADC_ONE_SHOT_MODE_DRIVER_H_

#include "stm32f446xx.h"

void adc_one_shot_init(void);
uint32_t read_adc_value(void);

#endif // ADC_ONE_SHOT_MODE_DRIVER_H_
