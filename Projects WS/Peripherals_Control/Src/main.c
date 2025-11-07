#include "gpio_driver.h"

int main(void) {
	gpio_init();

	while (1) {
		led_toggle();
	}

	return 0;
}
