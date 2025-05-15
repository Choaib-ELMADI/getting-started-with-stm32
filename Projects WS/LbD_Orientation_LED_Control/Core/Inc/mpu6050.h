#ifndef INC_MPU6050_H_
#define INC_MPU6050_H_

#include "main.h"

#define MPU6050_WHOAMI_REG          	((uint8_t)117)
#define MPU6050_PWR_MNG_REG         	((uint8_t)107)
#define I2C_TIMEOUT                 	10UL
#define ACCELEROMETER_REG_BASE_ADDRESS	((uint8_t)59)

typedef enum {
	MPU6050_OK    = 0x00U,
	MPU6050_ERROR = 0x01U
} mpu6050_status_t;

typedef struct {
	int16_t x;
	int16_t y;
	int16_t z;
} mpu6050_accelerometer_data_t;

mpu6050_status_t mpu6050_read_byte(I2C_HandleTypeDef*, uint8_t, uint8_t*);
mpu6050_status_t mpu6050_read(I2C_HandleTypeDef*, uint8_t, uint8_t*, uint32_t);

mpu6050_status_t mpu6050_write_byte(I2C_HandleTypeDef*, uint8_t, uint8_t);

mpu6050_status_t mpu6050_init(I2C_HandleTypeDef*, uint8_t);

mpu6050_status_t mpu6050_read_accelerometer_data(I2C_HandleTypeDef*, uint8_t, mpu6050_accelerometer_data_t*);

#endif // INC_MPU6050_H_
