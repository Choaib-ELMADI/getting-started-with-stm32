/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include <math.h>
#include "kalman_filter.h"
#include "mpu6050.h"
#include <limits.h>

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

TIM_HandleTypeDef htim2;

/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = { .name = "defaultTask", .stack_size = 128 * 4, .priority =
		(osPriority_t) osPriorityNormal, };
/* Definitions for readSensorTask */
osThreadId_t readSensorTaskHandle;
const osThreadAttr_t readSensorTask_attributes = { .name = "readSensorTask", .stack_size = 128 * 4, .priority =
		(osPriority_t) osPriorityAboveNormal, };
/* Definitions for pwmControlTask */
osThreadId_t pwmControlTaskHandle;
const osThreadAttr_t pwmControlTask_attributes = { .name = "pwmControlTask", .stack_size = 128 * 4, .priority =
		(osPriority_t) osPriorityHigh, };
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
static void MX_I2C1_Init(void);
void StartDefaultTask(void *argument);
void Read_Sensor_Task(void *argument);
void PWM_Control_Task(void *argument);

/* USER CODE BEGIN PFP */

long map(long x, long in_min, long in_max, long out_min, long out_max) {
	long result = (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;

	if (result > out_max)
		result = out_max;
	else if (result < out_min)
		result = out_min;

	return result;
}

void change_pwm_duty_cycle(uint32_t pwm_pulse, uint8_t channel) {
	__HAL_TIM_SET_COMPARE(&htim2, channel, pwm_pulse);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if (GPIO_Pin == MPU6050_INT_Pin) {
		mpu6050_interrupt_handle(&hi2c1);
	}
}

void mpu6050_raw_data_ready_callback(void) {
	BaseType_t pxHigherPriorityTaskWoken;
	pxHigherPriorityTaskWoken = pdFALSE;

	if (readSensorTaskHandle) {
		xTaskNotifyFromISR((TaskHandle_t )readSensorTaskHandle, 0, eNoAction, &pxHigherPriorityTaskWoken);
	}

	portYIELD_FROM_ISR(pxHigherPriorityTaskWoken);
}

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

const mpu6050_accelerometer_data_t error_offset = { .x = 112, .y = 164, .z = 1996 };

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void) {
	/* USER CODE BEGIN 1 */

	/* USER CODE END 1 */

	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

	/* Configure the system clock */
	SystemClock_Config();

	/* USER CODE BEGIN SysInit */

	/* USER CODE END SysInit */

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_TIM2_Init();
	MX_I2C1_Init();
	/* USER CODE BEGIN 2 */

	if (mpu6050_init(&hi2c1, MPU6050_I2C_ADDRESS) != MPU6050_OK) {
		Error_Handler();
	}

	if (mpu6050_disable_interrupt(&hi2c1, ALL_INT) != MPU6050_OK) {
		Error_Handler();
	}

	if (mpu6050_interrupt_config(&hi2c1, INT_LEVEL_ACTIVE_HIGH) != MPU6050_OK) {
		Error_Handler();
	}

	if (mpu6050_enable_interrupt(&hi2c1, RAW_RDY_INT) != MPU6050_OK) {
		Error_Handler();
	}

	if (HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1) != HAL_OK) {
		Error_Handler();
	}

	if (HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2) != HAL_OK) {
		Error_Handler();
	}

	/* USER CODE END 2 */

	/* Init scheduler */
	osKernelInitialize();

	/* USER CODE BEGIN RTOS_MUTEX */
	/* add mutexes, ... */
	/* USER CODE END RTOS_MUTEX */

	/* USER CODE BEGIN RTOS_SEMAPHORES */
	/* add semaphores, ... */
	/* USER CODE END RTOS_SEMAPHORES */

	/* USER CODE BEGIN RTOS_TIMERS */
	/* start timers, add new ones, ... */
	/* USER CODE END RTOS_TIMERS */

	/* USER CODE BEGIN RTOS_QUEUES */
	/* add queues, ... */
	/* USER CODE END RTOS_QUEUES */

	/* Create the thread(s) */
	/* creation of defaultTask */
	defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

	/* creation of readSensorTask */
	readSensorTaskHandle = osThreadNew(Read_Sensor_Task, NULL, &readSensorTask_attributes);

	/* creation of pwmControlTask */
	pwmControlTaskHandle = osThreadNew(PWM_Control_Task, NULL, &pwmControlTask_attributes);

	/* USER CODE BEGIN RTOS_THREADS */
	/* add threads, ... */
	/* USER CODE END RTOS_THREADS */

	/* USER CODE BEGIN RTOS_EVENTS */
	/* add events, ... */
	/* USER CODE END RTOS_EVENTS */

	/* Start scheduler */
	osKernelStart();

	/* We should never get here as control is now taken by the scheduler */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1) {
		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */
	}
	/* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void) {
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	/** Configure the main internal regulator output voltage
	 */
	__HAL_RCC_PWR_CLK_ENABLE();
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

	/** Initializes the RCC Oscillators according to the specified parameters
	 * in the RCC_OscInitTypeDef structure.
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/** Initializes the CPU, AHB and APB buses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV2;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK) {
		Error_Handler();
	}
}

/**
 * @brief I2C1 Initialization Function
 * @param None
 * @retval None
 */
static void MX_I2C1_Init(void) {

	/* USER CODE BEGIN I2C1_Init 0 */

	/* USER CODE END I2C1_Init 0 */

	/* USER CODE BEGIN I2C1_Init 1 */

	/* USER CODE END I2C1_Init 1 */
	hi2c1.Instance = I2C1;
	hi2c1.Init.ClockSpeed = 100000;
	hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
	hi2c1.Init.OwnAddress1 = 0;
	hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	hi2c1.Init.OwnAddress2 = 0;
	hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
	if (HAL_I2C_Init(&hi2c1) != HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN I2C1_Init 2 */

	/* USER CODE END I2C1_Init 2 */

}

/**
 * @brief TIM2 Initialization Function
 * @param None
 * @retval None
 */
static void MX_TIM2_Init(void) {

	/* USER CODE BEGIN TIM2_Init 0 */

	/* USER CODE END TIM2_Init 0 */

	TIM_ClockConfigTypeDef sClockSourceConfig = { 0 };
	TIM_MasterConfigTypeDef sMasterConfig = { 0 };
	TIM_OC_InitTypeDef sConfigOC = { 0 };

	/* USER CODE BEGIN TIM2_Init 1 */

	/* USER CODE END TIM2_Init 1 */
	htim2.Instance = TIM2;
	htim2.Init.Prescaler = 7;
	htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim2.Init.Period = 1000;
	htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim2) != HAL_OK) {
		Error_Handler();
	}
	sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK) {
		Error_Handler();
	}
	if (HAL_TIM_PWM_Init(&htim2) != HAL_OK) {
		Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK) {
		Error_Handler();
	}
	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.Pulse = 500;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1) != HAL_OK) {
		Error_Handler();
	}
	sConfigOC.Pulse = 200;
	if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_2) != HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN TIM2_Init 2 */

	/* USER CODE END TIM2_Init 2 */
	HAL_TIM_MspPostInit(&htim2);

}

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void) {
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };
	/* USER CODE BEGIN MX_GPIO_Init_1 */
	/* USER CODE END MX_GPIO_Init_1 */

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	/*Configure GPIO pin : MPU6050_INT_Pin */
	GPIO_InitStruct.Pin = MPU6050_INT_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(MPU6050_INT_GPIO_Port, &GPIO_InitStruct);

	/* EXTI interrupt init*/
	HAL_NVIC_SetPriority(EXTI9_5_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

	/* USER CODE BEGIN MX_GPIO_Init_2 */
	/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartDefaultTask */
/**
 * @brief  Function implementing the defaultTask thread.
 * @param  argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument) {
	/* USER CODE BEGIN 5 */
	/* Infinite loop */
	for (;;) {
		osDelay(1);
	}
	/* USER CODE END 5 */
}

/* USER CODE BEGIN Header_Read_Sensor_Task */
/**
 * @brief Function implementing the readSensorTask thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_Read_Sensor_Task */
void Read_Sensor_Task(void *argument) {
	/* USER CODE BEGIN Read_Sensor_Task */

	mpu6050_accelerometer_data_t accelerometer_data;
	uint32_t yz_accelerometer_data;

	for (;;) {
		// READ SENSOR DATA
		if (mpu6050_read_accelerometer_data(&hi2c1, MPU6050_I2C_ADDRESS, &accelerometer_data) != MPU6050_OK) {
			Error_Handler();
		}
		accelerometer_data = mpu6050_accelerometer_calibration(&error_offset, &accelerometer_data);
		yz_accelerometer_data = (accelerometer_data.z << 16) | accelerometer_data.y;

		// SEND NOTIFICATION TO THE PWM CONTROL TASK
		xTaskNotify((TaskHandle_t )pwmControlTaskHandle, yz_accelerometer_data, eSetValueWithOverwrite);

		// ENTER BLOCKED STATE
		xTaskNotifyWait(0, 0, NULL, portMAX_DELAY);
	}

	/* USER CODE END Read_Sensor_Task */
}

/* USER CODE BEGIN Header_PWM_Control_Task */
/**
 * @brief Function implementing the pwmControlTask thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_PWM_Control_Task */
void PWM_Control_Task(void *argument) {
	/* USER CODE BEGIN PWM_Control_Task */

	mpu6050_accelerometer_data_t accelerometer_data;
	int16_t roll_angle, kalman_roll_angle;
	float dt = 0;
	uint32_t previous_tick = osKernelGetTickCount();
	uint32_t yz_accelerometer_data;

	KalmanFilter kf;
	kalman_filter_init(&kf);

	for (;;) {
		// WAKES UP ON NOTIFICATION
		// ENTER BLOCKED STATE
		xTaskNotifyWait(0, ULONG_MAX, &yz_accelerometer_data, portMAX_DELAY);

		// EXTRACT RECEIVED DATA
		accelerometer_data.y = (uint16_t) (yz_accelerometer_data);
		accelerometer_data.z = (uint16_t) (yz_accelerometer_data >> 16);

		uint32_t current_tick = osKernelGetTickCount();
		dt = (current_tick - previous_tick) / 1000.0f;
		previous_tick = current_tick;

		roll_angle = atan2(accelerometer_data.y, accelerometer_data.z) * (180.0 / M_PI);
		kalman_roll_angle = (int16_t) kalman_filter_get_angle(&kf, roll_angle, dt);

		uint8_t channel = (kalman_roll_angle < 0) ? TIM_CHANNEL_1 : TIM_CHANNEL_2;
		kalman_roll_angle = (kalman_roll_angle < 0) ? -kalman_roll_angle : kalman_roll_angle;
		uint32_t pwm_pulse = map(kalman_roll_angle, MIN_POS_ANGLE, MAX_POS_ANGLE, MIN_PWM_PULSE, MAX_PWM_PULSE);
		change_pwm_duty_cycle(pwm_pulse, channel);

		// ENTER BLOCKED STATE
	}

	/* USER CODE END PWM_Control_Task */
}

/**
 * @brief  Period elapsed callback in non blocking mode
 * @note   This function is called  when TIM6 interrupt took place, inside
 * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
 * a global variable "uwTick" used as application time base.
 * @param  htim : TIM handle
 * @retval None
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	/* USER CODE BEGIN Callback 0 */

	/* USER CODE END Callback 0 */
	if (htim->Instance == TIM6) {
		HAL_IncTick();
	}
	/* USER CODE BEGIN Callback 1 */

	/* USER CODE END Callback 1 */
}

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void) {
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1) {
	}
	/* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
