#include <stdint.h>

#include "oc_pin_driver.h"
#include "ic_pin_driver.h"
#include "timer_ic_mode_driver.h"
#include "timer_oc_mode_driver.h"

volatile unsigned int timestamp;

int main(void) {
	oc_pin_init();
	ic_pin_init();
	timer_oc_mode_init(); // TIM2 Output Compare Mode
	timer_ic_mode_init(); // TIM3 Input  Capture Mode

	while (1) {
		while (!(TIM3->SR & (1UL << 0)));
		timestamp = TIM3->CCR1;
		TIM3->SR &= ~(1UL << 0);
	}

	return 0;
}
