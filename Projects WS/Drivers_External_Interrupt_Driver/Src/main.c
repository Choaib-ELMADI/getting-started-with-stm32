#include <stdint.h>

#include "external_interrupt_driver.h"

int main(void) {
	led_init();
	exti_init();

	while (1);

	return 0;
}
