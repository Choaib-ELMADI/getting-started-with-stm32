#include <stdint.h>

#include "usart_driver.h"

int main(void) {
	uart_tx_init(115200);

	while (1);

	return 0;
}
