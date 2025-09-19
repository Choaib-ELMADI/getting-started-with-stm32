#include <stdint.h>

#include "usart_driver.h"

int main(void) {
	uart_tx_init(115200);

	while (1) {
		uart_transfer((unsigned char *)"Hello, World!\n");
		// Wait...
		uart_transfer((unsigned char *)"Hello!\n");
		// Wait...
	}

	return 0;
}
