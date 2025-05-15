#include "mpu6050.h"

static uint8_t mpu6050_i2c_address;

mpu6050_status_t mpu6050_read_byte(I2C_HandleTypeDef *hi2c, uint8_t register_address, uint8_t *data) {
    HAL_StatusTypeDef status = HAL_I2C_Mem_Read(hi2c, mpu6050_i2c_address << 1, register_address, 1, data, 1, I2C_TIMEOUT);
    return (status == HAL_OK) ? MPU6050_OK : MPU6050_ERROR;
}

mpu6050_status_t mpu6050_read(I2C_HandleTypeDef *hi2c, uint8_t register_base_address, uint8_t *buffer, uint32_t nbytes) {
    HAL_StatusTypeDef status = HAL_I2C_Mem_Read(hi2c, mpu6050_i2c_address << 1, register_base_address, 1, buffer, nbytes, I2C_TIMEOUT);
    return (status == HAL_OK) ? MPU6050_OK : MPU6050_ERROR;
}

mpu6050_status_t mpu6050_write_byte(I2C_HandleTypeDef *hi2c, uint8_t register_address, uint8_t data) {
    HAL_StatusTypeDef status = HAL_I2C_Mem_Write(hi2c, mpu6050_i2c_address << 1, register_address, 1, &data, 1, I2C_TIMEOUT);
    return (status == HAL_OK) ? MPU6050_OK : MPU6050_ERROR;
}

mpu6050_status_t mpu6050_init(I2C_HandleTypeDef *hi2c, uint8_t i2c_slave_address) {
    mpu6050_i2c_address = i2c_slave_address;

    // CHECK AVAILABLE MPU6050 DEVICE
    uint8_t read_byte = 0;
    if (mpu6050_read_byte(hi2c, MPU6050_WHOAMI_REG, &read_byte) != MPU6050_OK) {
        printf("Something went wrong!\n");
        return MPU6050_ERROR;
    }

    if (read_byte == 0x68 || read_byte == 0x98) {
        printf("Valid MPU6050 device with address %X!\n", mpu6050_i2c_address);
    } else {
        printf("Invalid device address %X!\n", mpu6050_i2c_address);
        return MPU6050_ERROR;
    }

    // DISABLE SLEEP MODE OF MPU6050
    uint8_t data = 0x00;
    if (mpu6050_write_byte(hi2c, MPU6050_PWR_MNG_REG, data) != MPU6050_OK) {
    	printf("Something went wrong again!\n");
        return MPU6050_ERROR;
    }

	return MPU6050_OK;
}

mpu6050_status_t mpu6050_read_accelerometer_data(I2C_HandleTypeDef *hi2c, uint8_t i2c_slave_address, mpu6050_accelerometer_data_t *accelerometer_data) {
	uint8_t raw_data[6];

	mpu6050_status_t status = mpu6050_read(hi2c, ACCELEROMETER_REG_BASE_ADDRESS, (uint8_t*)raw_data, sizeof(raw_data));
	if (status != MPU6050_OK) {
		printf("Error reading accelerometer data!\n");
		return MPU6050_ERROR;
	}

	accelerometer_data->x = (int16_t)(raw_data[0] << 8 | raw_data[1]);
	accelerometer_data->y = (int16_t)(raw_data[2] << 8 | raw_data[3]);
	accelerometer_data->z = (int16_t)(raw_data[4] << 8 | raw_data[5]);

	return MPU6050_OK;
}
