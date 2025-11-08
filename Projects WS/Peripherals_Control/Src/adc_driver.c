#include "uart_driver.h"
#include "adc_driver.h"

#define SR_EOC      (1 << 1)
#define CR2_ADON    (1 << 0)
#define CR2_CONT    (1 << 1)
#define CR2_SWSTART (1 << 30)
#define RCC_ADC1EN  (1 << 8)

// Needed for the conversions sequence length
#define SQR1_L0     (1 << 20)
#define SQR1_L1     (1 << 21)
#define SQR1_L2     (1 << 22)
#define SQR1_L3     (1 << 23)

// Needed for the 1st conversion channel
#define SQR3_SQ1_0  (1 << 0)
#define SQR3_SQ1_1  (1 << 1)
#define SQR3_SQ1_2  (1 << 2)
#define SQR3_SQ1_3  (1 << 3)
#define SQR3_SQ1_4  (1 << 4)

void adc_init(void) {
	// Allow clock access to ADC peripheral
	RCC_APB2ENR |= RCC_ADC1EN;

	// Set data resolution (10-bit)
	ADC_CR1 &= ~(1 << 25);
	ADC_CR1 |= (1 << 24);

	// Set the conversions sequence length
	ADC_SQR1 &= ~(SQR1_L3 | SQR1_L2 | SQR1_L1 | SQR1_L0);

	// Set the conversion channel
	ADC_SQR3 &= ~(SQR3_SQ1_4 | SQR3_SQ1_3 | SQR3_SQ1_2 | SQR3_SQ1_1 | SQR3_SQ1_0);

	// Enable ADC module
	ADC_CR2 |= CR2_ADON;
}

void adc_start_conversion(void) {
	// Set continuous conversion
	ADC_CR2 |= CR2_CONT;

	// Start ADC module
	ADC_CR2 |= CR2_SWSTART;
}
int adc_read(void) {
	while (!(ADC_SR & SR_EOC)); // Keep looping while conversion isn't complete
	return ADC_DR;
}

void sample_adc_signal(char *buffer, int *state) {
	int adc_data;
	char adc_data_first_byte;

	if (*state == ON) {
		char *start_buffer = buffer;

		for (int i=0; i<64; ++i) {
			adc_data = adc_read();
			adc_data_first_byte = (adc_data & 0xFF);
			*buffer++ = adc_data_first_byte;
		}

		transmit_adc_signal(start_buffer);
	}
}
void transmit_adc_signal(char *buffer) {
	for (int i=0; i<64; ++i) {
		usart2_write(*buffer);
	}
}
