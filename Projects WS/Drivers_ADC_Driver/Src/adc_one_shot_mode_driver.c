#include "adc_one_shot_mode_driver.h"

void adc_one_shot_init(void) {
	// ADC module  --> ADC1
	// ADC channel --> IN1 = PA1

	// Enable MCU internal clock
	RCC->CR |= (1UL << 0);

	// Enable ADC channel port clock
	RCC->AHB1ENR |= (1UL << 0);

	// Select PA1 pin mode --> Analog input
	GPIOA->MODER |= (1UL << 2) | (1UL << 3);

	// Enable ADC clock
	RCC->APB2ENR |= (1UL << 8);

	// Turn OFF ADC
	ADC1->CR2 &= ~(1UL << 0);

	// Conversion sequence start
	ADC1->SQR3 |= (1UL << 0);

	// Set number of conversions (number of channels)
	ADC1->SQR1 = 0x0000;

	// Turn ON ADC
	ADC1->CR2 |= (1UL << 0);

	// Continuous conversion mode
	ADC1->CR2 |= (1UL << 1);
}

uint32_t read_adc_value(void) {
	// Start ADC conversion
	ADC1->CR2 |= (1UL << 30);

	// Wait for conversion to complete
	while (!(ADC1->SR & (1UL << 1)));

	// Read conversion reuslt
	return ADC1->DR;
}
