#include <stdint.h>

#include "delay_driver.h"
#include "led_driver.h"

int main(void) {
	led_init();
	delay_init();

	while (1) {
		led_on();
		delay(1000);
		led_off();
		delay(1000);
	}

	return 0;
}
