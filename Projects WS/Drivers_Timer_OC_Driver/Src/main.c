#include <stdint.h>

#include "timer_oc_mode_driver.h"

int main(void) {
	led_init();
	timer_oc_mode_init();

	while (1);

	return 0;
}
