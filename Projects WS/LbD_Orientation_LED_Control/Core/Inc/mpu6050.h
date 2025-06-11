#ifndef INC_MPU6050_H_
#define INC_MPU6050_H_

#include "main.h"

#define MPU6050_WHOAMI_REG          	((uint8_t)117)
#define MPU6050_PWR_MNG_REG         	((uint8_t)107)
#define ACCELEROMETER_REG_BASE_ADDRESS	((uint8_t)59)
#define MPU6050_CONFIG_REG				((uint8_t)26)
#define MPU6050_I2C_ADDRESS				0x68
#define I2C_TIMEOUT                 	10UL

#define MAX_POS_ANGLE					90
#define MIN_POS_ANGLE					0
#define MAX_PWM_PULSE					1000
#define MIN_PWM_PULSE					0

typedef enum {
	MPU6050_OK    = 0x00U,
	MPU6050_ERROR = 0x01U
} mpu6050_status_t;

typedef struct {
	int16_t x;
	int16_t y;
	int16_t z;
} mpu6050_accelerometer_data_t;

typedef enum {
    INT_LEVEL_ACTIVE_HIGH = 0x00,
    INT_LEVEL_ACTIVE_LOW
} mpu6050_interrupt_config_t;

typedef enum {
    RAW_RDY_INT    = 0x01,
    I2C_MST_INT    = 0x08,
    FIFO_OFLOW_INT = 0x10,
    MOT_INT        = 0x40,
    ALL_INT        = 0xFF
} mpu6050_interrupt_t;

mpu6050_status_t mpu6050_read(I2C_HandleTypeDef*, uint8_t, uint8_t*, uint32_t);

mpu6050_status_t mpu6050_write_byte(I2C_HandleTypeDef*, uint8_t, uint8_t);

mpu6050_status_t mpu6050_init(I2C_HandleTypeDef*, uint8_t);

mpu6050_status_t mpu6050_read_accelerometer_data(I2C_HandleTypeDef*, uint8_t, mpu6050_accelerometer_data_t*);

mpu6050_accelerometer_data_t mpu6050_accelerometer_calibration(const mpu6050_accelerometer_data_t*, mpu6050_accelerometer_data_t*);

mpu6050_status_t mpu6050_configure_low_pass_filter(I2C_HandleTypeDef*, uint8_t);

mpu6050_status_t mpu6050_interrupt_config(I2C_HandleTypeDef*, mpu6050_interrupt_config_t);

mpu6050_status_t mpu6050_enable_interrupt(I2C_HandleTypeDef*, mpu6050_interrupt_t);

mpu6050_status_t mpu6050_disable_interrupt(I2C_HandleTypeDef*, mpu6050_interrupt_t);

#endif // INC_MPU6050_H_
