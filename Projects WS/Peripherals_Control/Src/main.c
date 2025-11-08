#include "gpio_driver.h"
#include "uart_driver.h"
#include "adc_driver.h"

int program_state = OFF;

char buffer[64];
char adc_value;

int main(void) {
	gpio_init();
	usart2_init();
	adc_init();
	adc_start_conversion();

	while (1) {
		set_program_state(&program_state);
		show_program_state(&program_state);
		sample_adc_signal(buffer, &program_state);
		adc_value = *buffer;
	}

	return 0;
}
