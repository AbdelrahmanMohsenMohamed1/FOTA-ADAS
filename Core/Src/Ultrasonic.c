/*
 * Ultrasonic.c
 *
 *  Created on: Apr 29, 2024
 *      Author: Amira
 */

#include "Ultrasonic.h"
#include "Ultrasonic_Confg.h"
extern TIM_HandleTypeDef htim1;

uint8_t  flag[4] = {0};
uint32_t T1[4]={0},T2[4]={0};


/**
 * @brief This function handles TIM1 capture compare interrupt.
 */
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{


	/* USER CODE BEGIN voidTIM1_CC_IRQn 0 */
	if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)
	{
		if (flag[0] == 0 ) {

			T1[0] = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
			//Input Capture Edge Select falling edge
			__HAL_TIM_SET_CAPTUREPOLARITY(&htim1 ,TIM_CHANNEL_1 ,TIM_INPUTCHANNELPOLARITY_FALLING) ;
			flag[0]++;

		}
		else if (flag[0] == 1) {

			flag[0]++;
			T2[0] = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
			//Input Capture Edge Select rising edge
			__HAL_TIM_SET_CAPTUREPOLARITY(&htim1 ,TIM_CHANNEL_1 ,TIM_INPUTCHANNELPOLARITY_RISING) ;
			__HAL_TIM_SET_COUNTER(htim,0);
			__HAL_TIM_DISABLE_IT(&htim1, TIM_IT_CC1);
		}
		else {
			/*nothing*/
		}

	}

	else if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2)
	{
		if (flag[1] == 0) {

			T1[1] = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);
			//Input Capture Edge Select falling edge
			__HAL_TIM_SET_CAPTUREPOLARITY(&htim1 ,TIM_CHANNEL_2 ,TIM_INPUTCHANNELPOLARITY_FALLING) ;
			flag[1]++;

		}
		else if (flag[1] == 1) {

			flag[1]++;
			T2[1] = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);
			//Input Capture Edge Select rising edge
			__HAL_TIM_SET_CAPTUREPOLARITY(&htim1 ,TIM_CHANNEL_2 ,TIM_INPUTCHANNELPOLARITY_RISING) ;
			__HAL_TIM_SET_COUNTER(htim,0);
			__HAL_TIM_DISABLE_IT(&htim1, TIM_IT_CC2);
		}
		else
		{
			/*nothing**/
		}
	}


	else if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_3)
	{
		if (flag[2] == 0) {

			T1[2] = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_3);
			//Input Capture Edge Select falling edge
			__HAL_TIM_SET_CAPTUREPOLARITY(&htim1 ,TIM_CHANNEL_3 ,TIM_INPUTCHANNELPOLARITY_FALLING) ;
			flag[2]++;

		}
		else if (flag[2] == 1) {

			flag[2]++;
			T2[2] = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_3);
			//Input Capture Edge Select rising edge
			__HAL_TIM_SET_CAPTUREPOLARITY(&htim1 ,TIM_CHANNEL_3 ,TIM_INPUTCHANNELPOLARITY_RISING) ;
			__HAL_TIM_SET_COUNTER(htim,0);
			__HAL_TIM_DISABLE_IT(&htim1, TIM_IT_CC3);
		}
		else
		{
			/*nothing**/
		}
	}

	else if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_4)
	{
		if (flag[3] == 0) {

			T1[3] = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_4);
			//Input Capture Edge Select falling edge
			__HAL_TIM_SET_CAPTUREPOLARITY(&htim1 ,TIM_CHANNEL_4 ,TIM_INPUTCHANNELPOLARITY_FALLING) ;
			flag[3]++;

		}
		else if (flag[3] == 1) {

			flag[3]++;
			T2[3]= HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_4);
			//Input Capture Edge Select rising edge
			__HAL_TIM_SET_CAPTUREPOLARITY(&htim1 ,TIM_CHANNEL_4 ,TIM_INPUTCHANNELPOLARITY_RISING) ;
			__HAL_TIM_SET_COUNTER(htim,0);
			__HAL_TIM_DISABLE_IT(&htim1, TIM_IT_CC4);
		}
		else
		{
			/*nothing**/
		}
	}
}

void ultrasonic_voidInit(void) {

	HAL_TIM_IC_Start_IT(&htim1 ,TIM_CHANNEL_1) ;
	HAL_TIM_IC_Start_IT(&htim1 ,TIM_CHANNEL_2) ;
	HAL_TIM_IC_Start_IT(&htim1 ,TIM_CHANNEL_3) ;
	HAL_TIM_IC_Start_IT(&htim1 ,TIM_CHANNEL_4) ;


}



float FrontUltrasonic_floatGetDistance(void)
{
	float distance;
	uint16_t time =0;

	HAL_GPIO_WritePin(TRIG_PORT_1, TRIG_PIN_1, GPIO_PIN_SET);
	delay(10);
	HAL_GPIO_WritePin(TRIG_PORT_1, TRIG_PIN_1, GPIO_PIN_RESET);
	__HAL_TIM_ENABLE_IT(&htim1, TIM_IT_CC1);
	while (flag[0] < 2 && time <50)
	{
		time++;
		HAL_Delay(1);
	}
	if(T2[0]>T1[0])
	{
		distance =  (T2[0] - T1[0])*.034/2;
	}
	else
	{
		distance = ((0xffff - T1[0]) + T2[0])*.034/2;
	}

	flag[0] = 0;
	return distance;
}


float RearUltrasonic_floatGetDistance(void)
{
	float distance;
	uint16_t time =0;
	HAL_GPIO_WritePin(TRIG_PORT_2, TRIG_PIN_2, GPIO_PIN_SET);
	delay(10);
	HAL_GPIO_WritePin(TRIG_PORT_2, TRIG_PIN_2, GPIO_PIN_RESET);
	__HAL_TIM_ENABLE_IT(&htim1, TIM_IT_CC2);
	while (flag[1] < 2&& time <50)
	{
		time++;
		HAL_Delay(1);
	}


	if(T2[1]>T1[1])
	{
		distance =  (T2[1] - T1[1])*.034/2;
	}
	else
	{
		distance = ((0xffff - T1[1]) + T2[1])*.034/2;
	}

	flag[1] = 0;
	return distance;
}


float RightUltrasonic_floatGetDistance(void)
{
	float distance;
	uint16_t time =0;

	HAL_GPIO_WritePin(TRIG_PORT_3, TRIG_PIN_3, GPIO_PIN_SET);
	delay(10);
	HAL_GPIO_WritePin(TRIG_PORT_3, TRIG_PIN_3, GPIO_PIN_RESET);
	__HAL_TIM_ENABLE_IT(&htim1, TIM_IT_CC3);
	while (flag[2] < 2&& time <50)
	{
		time++;
		HAL_Delay(1);
	}


	if(T2[2]>T1[2])
	{
		distance =  (T2[2] - T1[2])*.034/2;
	}
	else
	{
		distance = ((0xffff - T1[2]) + T2[2])*.034/2;
	}

	flag[2] = 0;
	return distance;
}

float LeftUltrasonic_floatGetDistance(void)
{
	float distance;
	uint16_t time =0;
	HAL_GPIO_WritePin(TRIG_PORT_4, TRIG_PIN_4, GPIO_PIN_SET);
	delay(10);
	HAL_GPIO_WritePin(TRIG_PORT_4, TRIG_PIN_4, GPIO_PIN_RESET);
	__HAL_TIM_ENABLE_IT(&htim1, TIM_IT_CC4);
	while (flag[3] < 2&& time <50)
	{
		time++;
		HAL_Delay(1);
	}

	if(T2[3]>T1[3])
	{
		distance =  (T2[3] - T1[3])*.034/2;
	}
	else
	{
		distance = ((0xffff - T1[3]) + T2[3])*.034/2;
	}

	flag[3] = 0;
	return distance;
}

void delay (uint16_t us)
{
	__HAL_TIM_SET_COUNTER(&htim1, 0);
	while (__HAL_TIM_GET_COUNTER(&htim1) < us);
}

