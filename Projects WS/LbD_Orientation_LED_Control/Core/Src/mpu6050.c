#include "mpu6050.h"

static uint8_t mpu6050_i2c_address;

mpu6050_status_t mpu6050_read(I2C_HandleTypeDef *hi2c, uint8_t register_address, uint8_t *buffer, uint32_t nbytes) {
	HAL_StatusTypeDef status = HAL_I2C_Mem_Read(hi2c, mpu6050_i2c_address << 1, register_address, 1, buffer, nbytes,
	I2C_TIMEOUT);
	return (status == HAL_OK) ? MPU6050_OK : MPU6050_ERROR;
}

mpu6050_status_t mpu6050_write_byte(I2C_HandleTypeDef *hi2c, uint8_t register_address, uint8_t data) {
	HAL_StatusTypeDef status = HAL_I2C_Mem_Write(hi2c, mpu6050_i2c_address << 1, register_address, 1, &data, 1,
	I2C_TIMEOUT);
	return (status == HAL_OK) ? MPU6050_OK : MPU6050_ERROR;
}

mpu6050_status_t mpu6050_init(I2C_HandleTypeDef *hi2c, uint8_t i2c_slave_address) {
	mpu6050_i2c_address = i2c_slave_address;

	// CHECK AVAILABLE MPU6050 DEVICE
	uint8_t read_byte = 0;
	if (mpu6050_read(hi2c, MPU6050_WHOAMI_REG, &read_byte, 1) != MPU6050_OK) {
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

mpu6050_status_t mpu6050_read_accelerometer_data(I2C_HandleTypeDef *hi2c, uint8_t i2c_slave_address,
		mpu6050_accelerometer_data_t *accelerometer_data) {
	uint8_t raw_data[6];

	mpu6050_status_t status = mpu6050_read(hi2c, ACCELEROMETER_REG_BASE_ADDRESS, raw_data, sizeof(raw_data));
	if (status != MPU6050_OK) {
		printf("Error reading accelerometer data!\n");
		return MPU6050_ERROR;
	}

	accelerometer_data->x = (int16_t) (raw_data[0] << 8 | raw_data[1]);
	accelerometer_data->y = (int16_t) (raw_data[2] << 8 | raw_data[3]);
	accelerometer_data->z = (int16_t) (raw_data[4] << 8 | raw_data[5]);

	return MPU6050_OK;
}

mpu6050_accelerometer_data_t mpu6050_accelerometer_calibration(const mpu6050_accelerometer_data_t *error_offset,
		mpu6050_accelerometer_data_t *raw_data) {
	mpu6050_accelerometer_data_t calibrated_data;
	calibrated_data.x = raw_data->x - error_offset->x;
	calibrated_data.y = raw_data->y - error_offset->y;
	calibrated_data.z = raw_data->z - error_offset->z;

	return calibrated_data;
}

mpu6050_status_t mpu6050_configure_low_pass_filter(I2C_HandleTypeDef *hi2c, uint8_t dlpf) {
	uint8_t value = 0;
	if (mpu6050_read(hi2c, MPU6050_CONFIG_REG, &value, 1) != MPU6050_OK) {
		return MPU6050_ERROR;
	}

	value &= ~(0x7);
	value |= dlpf;

	if (mpu6050_write_byte(hi2c, MPU6050_CONFIG_REG, value) != MPU6050_OK) {
		return MPU6050_ERROR;
	}

	return MPU6050_OK;
}

mpu6050_status_t mpu6050_interrupt_config(I2C_HandleTypeDef *hi2c, mpu6050_interrupt_config_t level) {
    uint8_t int_cfg = 0;

    if (mpu6050_read(hi2c, MPU6050_REG_INT_PIN_CFG, &int_cfg, 1) != MPU6050_OK) {
        return MPU6050_ERROR;
    }

    int_cfg &= ~0x80;
    int_cfg |= (uint8_t)level;

    return mpu6050_write_byte(hi2c, MPU6050_REG_INT_PIN_CFG, int_cfg);
}

mpu6050_status_t mpu6050_enable_interrupt(I2C_HandleTypeDef *hi2c, mpu6050_interrupt_t interrupt) {
    uint8_t int_current_settings = 0;

    if (mpu6050_read(hi2c, MPU6050_REG_INT_EN, &int_current_settings, 1) != MPU6050_OK) {
        return MPU6050_ERROR;
    }

    int_current_settings |= (uint8_t)interrupt;

    return mpu6050_write_byte(hi2c, MPU6050_REG_INT_EN, int_current_settings);
}

mpu6050_status_t mpu6050_disable_interrupt(I2C_HandleTypeDef *hi2c, mpu6050_interrupt_t interrupt) {
    uint8_t int_current_settings = 0;

    if (interrupt != ALL_INT) {
        mpu6050_read(hi2c, MPU6050_REG_INT_EN, &int_current_settings, 1);
    }

    int_current_settings &= ~(uint8_t)interrupt;

    return mpu6050_write_byte(hi2c, MPU6050_REG_INT_EN, int_current_settings);
}
