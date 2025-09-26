#include <stdint.h>

#include "uart_driver.h"

void dummy_delay(unsigned long count) {
	while (count--);
}

int main(void) {
	uart_tx_init();

	while (1) {
		uart_tx_write('C');
		dummy_delay(1000000);
		uart_tx_write('\n');
		dummy_delay(1000000);
	}

	return 0;
}
