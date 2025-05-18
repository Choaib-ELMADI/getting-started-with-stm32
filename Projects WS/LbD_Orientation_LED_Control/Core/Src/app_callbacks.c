#include "main.h"

// uint32_t g_counter = 0;
// volatile uint32_t g_channel_2_state = 500;
// volatile uint32_t g_channel_3_state = 200;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	UNUSED(htim);
	/*
	g_counter = 0;
	g_channel_2_state = 500;
	g_channel_3_state = 200;
	*/
}

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim) {
	UNUSED(htim);
	/*
	if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2) {
		g_channel_2_state = 0;
	} else if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_3) {
		g_channel_3_state = 0;
	}
	*/
}

void HAL_TIM_ErrorCallback(TIM_HandleTypeDef *htim) {
	UNUSED(htim);
}
