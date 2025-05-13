#include "mpu6050.h"

static uint8_t mpu6050_i2c_address;

mpu6050_status_t mpu6050_init(I2C_HandleTypeDef *hi2c, uint8_t i2c_slave_address) {
	mpu6050_i2c_address = i2c_slave_address;
	uint8_t who_am_i_register_address = 117;
	uint8_t register_value = 0;

	if (HAL_I2C_Mem_Read(hi2c, i2c_slave_address, who_am_i_register_address, 1, &register_value, 1, 10) == HAL_OK) {
		if (register_value == 0x68) {
			printf("Valid MPU6050 device!");
		} else {
			printf("Invalid device address!");
			return MPU6050_ERROR;
		}
	} else {
		return MPU6050_ERROR;
	}

	return MPU6050_OK;
}
