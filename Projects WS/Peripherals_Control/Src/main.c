#include "gpio_driver.h"

int program_state = OFF;

int main(void) {
	gpio_init();

	while (1) {
		set_program_state(&program_state);
		show_program_state(&program_state);
	}

	return 0;
}
