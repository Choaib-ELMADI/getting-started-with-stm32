#ifndef INC_MPU6050_H_
#define INC_MPU6050_H_

#include "main.h"

typedef enum {
	MPU6050_OK    = 0x00U,
	MPU6050_ERROR = 0x01U
} mpu6050_status_t;

mpu6050_status_t mpu6050_init(I2C_HandleTypeDef*, uint8_t);

#endif // INC_MPU6050_H_
