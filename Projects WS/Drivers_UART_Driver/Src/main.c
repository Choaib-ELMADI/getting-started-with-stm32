#include <stdint.h>

#include "uart_driver.h"

volatile unsigned char data = 0;

void dummy_delay(unsigned long count) {
	while (count--);
}

int main(void) {
	uart_tx_init();
	uart_rx_init();

	while (1) {
		uart_rx_read();
		dummy_delay(100000);
		uart_tx_write(data);
		dummy_delay(1000000);
	}

	return 0;
}
