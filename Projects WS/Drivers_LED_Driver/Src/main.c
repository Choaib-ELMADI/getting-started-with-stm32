#include <stdint.h>

#include "led_driver.h"

int main(void) {
	led_init();

	while (1) {
		led_on();
		// Wait...
		led_off();
		// Wait...
	}

	return 0;
}
