#include "adc_driver.h"

#define SR_EOC      (1 << 1)
#define CR1_EOC     (1 << 5)
#define CR2_ADON    (1 << 0)
#define CR2_CONT    (1 << 1)
#define CR2_SWSTART (1 << 30)
#define ADC1_EN     (1 << 8)

// Needed for the conversions sequence length
#define SQR1_L0     (1 << 20)
#define SQR1_L1     (1 << 21)
#define SQR1_L2     (1 << 22)
#define SQR1_L3     (1 << 23)

// Needed for the 1st conversion channel
#define SQR3_SQ1_0  (1 << 0)
#define SQR3_SQ1_1  (1 << 1)
#define SQR3_SQ1_2  (1 << 2)
#define SQR3_SQ1_3  (1 << 3)
#define SQR3_SQ1_4  (1 << 4)
