#include <stdint.h>

void main(void) {
    uint8_t temp = 2;

    temp |= 0x4;
    temp &= ~0x4;
}
