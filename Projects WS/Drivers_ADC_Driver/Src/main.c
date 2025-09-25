#include <stdint.h>

#include "adc_interrupt_mode_driver.h"
#include "adc_one_shot_mode_driver.h"

volatile uint32_t data = 0;

int main(void) {
	adc_one_shot_init();

	while (1) {
		data = read_adc_value();
	}

	return 0;
}
