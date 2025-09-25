#include "adc_interrupt_mode_driver.h"

extern uint32_t data;

void adc_interrupt_init(void) {
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

	// Continuous conversion mode
	ADC1->CR2 |= (1UL << 1);

	// Enable interrupt for EOC (End of conversion)
	ADC1->CR1 |= (1UL << 5);

	// Enable NVIC peripheral interrupt
	NVIC_EnableIRQ(ADC_IRQn);

	// Turn ON ADC
	ADC1->CR2 |= (1UL << 0);

	// Start ADC conversion
	ADC1->CR2 |= (1UL << 30);
}

void ADC_IRQHandler(void) {
	// Wait for conversion to complete
	while (!(ADC1->SR & (1UL << 1)));

	// Clear bit
	ADC1->SR &= ~(1UL << 1);

	// Read conversion reuslt
	data = ADC1->DR;
}
