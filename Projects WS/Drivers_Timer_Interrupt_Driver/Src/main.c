#include <stdint.h>

#include "timer_interrupt_driver.h"

int main(void) {
	led_init();
	systick_timer_init();

	while (1);

	return 0;
}
