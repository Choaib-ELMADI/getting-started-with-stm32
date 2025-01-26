#include <stdio.h>

void main(void) {
    /*
        Calculate the bit band alias address for a given bit band memory address at:
            - the 4th bit position
            - position of the memory location 0x20000200
            - alias base address 0x22000000
            - bit band base address 0x20000000

        alias_address = (alias_base) + (32 * (bit_band_memory_address - bit_band_base)) + (bit * 4)
    */

    int *alias_base_address      = (unsigned *) 0x22000000;
    int *bit_band_base_address   = (unsigned *) 0x20000000;
    int *bit_band_memory_address = (unsigned *) 0x20000200;
    int bit_order = 4;
    int *alias_address;

    *bit_band_memory_address = 0xFF;
    printf("\n %d \n", *bit_band_memory_address);

    alias_address = (unsigned *) ((alias_base_address) + (32 * (bit_band_memory_address - bit_band_base_address)) + (bit_order * 4));

    *alias_address = 0;
    printf("\n %d \n", *bit_band_memory_address);
}
