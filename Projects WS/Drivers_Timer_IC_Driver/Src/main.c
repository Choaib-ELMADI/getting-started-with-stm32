#include <stdint.h>

#include "oc_pin_driver.h"
#include "ic_pin_driver.h"
#include "timer_ic_mode_driver.h"
#include "timer_oc_mode_driver.h"

int main(void) {
	oc_pin_init();
	ic_pin_init();
	timer_oc_mode_init();
	timer_ic_mode_init();

	while (1);

	return 0;
}
