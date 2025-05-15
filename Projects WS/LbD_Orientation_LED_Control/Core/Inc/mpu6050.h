#ifndef INC_MPU6050_H_
#define INC_MPU6050_H_

#include "main.h"

#define MPU6050_WHOAMI_REG          ((uint8_t)117)
#define MPU6050_PWR_MNG_REG         ((uint8_t)107)
#define I2C_TIMEOUT                 10UL

typedef enum {
	MPU6050_OK    = 0x00U,
	MPU6050_ERROR = 0x01U
} mpu6050_status_t;

mpu6050_status_t mpu6050_read_byte(I2C_HandleTypeDef*, uint8_t, uint8_t*);
mpu6050_status_t mpu6050_write_byte(I2C_HandleTypeDef*, uint8_t, uint8_t);
mpu6050_status_t mpu6050_init(I2C_HandleTypeDef*, uint8_t);

#endif // INC_MPU6050_H_
