#include <stdint.h>

int main(void) {
    volatile uint32_t *GPIOA_MODER = 0x0, *GPIOA_ODR = 0x0;

    GPIOA_MODER = (uint32_t*)0x48000000;                // Address of the GPIOA->MODER register
    GPIOA_ODR   = (uint32_t*)(0x48000000 + 0x14);      // Address of the GPIOA->ODR register

    //This ensures that the peripheral is enabled and connected to the AHB1 bus
    __HAL_RCC_GPIOA_CLK_ENABLE();

    *GPIOA_MODER = *GPIOA_MODER | 0x400;                // Sets MODER[11:10] = 0x1
    *GPIOA_ODR   = *GPIOA_ODR | 0x20;                   // Sets ODR[5] = 0x1, that is pulls PA5 high

    while(1);
}
