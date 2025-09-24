#include <stdint.h>

#include "adc_driver.h"

volatile uint32_t data = 0;

int main(void) {
	adc_init();

	while (1) {
		// Start ADC conversion
		ADC1->CR2 |= (1UL << 30);

		// Wait for conversion to complete
		while (!(ADC1->SR & (1UL << 1)));

		// Read conversion reuslt
		data = ADC1->DR;
	}

	return 0;
}
