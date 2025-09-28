#include <stdint.h>

#include "uart_driver.h"

volatile unsigned char data = 0;

void dummy_delay(unsigned long count) {
	while (count--);
}

int main(void) {
	uart_tx_init();
	// uart_rx_init();
	uart_rx_interrupt_init();

	while (1) {
		// uart_rx_read();
		// uart_tx_write(data);
	}

	return 0;
}
