#include <stdint.h>

#define BITBAND_SRAM_BASE 0x20000000
#define ALIAS_SRAM_BASE 0x22000000
#define BITBAND_SRAM(target, bit_n) (ALIAS_SRAM_BASE + (((uint32_t)target - BITBAND_SRAM_BASE) * 32) + (bit_n * 4))

#define BITBAND_PERI_BASE 0x40000000
#define ALIAS_PERI_BASE 0x42000000
#define BITBAND_PERI(target, bit_n) (ALIAS_PERI_BASE + (((uint32_t)target - BITBAND_PERI_BASE) * 32) + (bit_n * 4))

#define GPIOA_PERH_ADDR 0x40020000
#define ODR_ADDR_OFF 0x14

void main(void) {
    uint32_t *GPIOA_ODR = GPIOA_PERH_ADDR + ODR_ADDR_OFF;
    uint32_t *GPIOA_PIN5 = BITBAND_PERI(GPIOA_ODR, 5);

    *GPIOA_PIN5 = 0x01; // Turns GPIO HIGH
    *GPIOA_PIN5 = 0x00; // Turns GPIO LOW
}
