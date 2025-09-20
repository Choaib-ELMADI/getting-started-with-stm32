#include <stdint.h>

#include "lcd_driver.h"

int main(void) {
	gpio_init();
	lcd_init();

	while (1) {
		lcd_command(0x80);
		lcd_print_string((unsigned char *)"Hello, World!", 13);
		lcd_command(0xC0);
		lcd_print_string((unsigned char *)"Hello!", 6);
	}

	return 0;
}
