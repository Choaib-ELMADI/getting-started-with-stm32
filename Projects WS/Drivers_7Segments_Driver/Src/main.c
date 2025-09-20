#include <stdint.h>

#include "sev_seg_driver.h"

int main(void) {
	sev_seg_init();

	while (1) {
		sev_seg_print_char(0x3F);
	}

	return 0;
}
