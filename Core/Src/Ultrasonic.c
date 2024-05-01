/*
 * Ultrasonic.c
 *
 *  Created on: Apr 29, 2024
 *      Author: Amira
 */

#include "Ultrasonic.h"
#include "Ultrasonic_Confg.h"
extern TIM_HandleTypeDef htim1;

uint8_t  flag = 0;
uint32_t T1=0,T2=0;


/**
 * @brief This function handles TIM1 capture compare interrupt.
 */
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{

	/* USER CODE BEGIN voidTIM1_CC_IRQn 0 */
	if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)
	{
		if (flag == 0) {

			T1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
			//Input Capture Edge Select falling edge
			__HAL_TIM_SET_CAPTUREPOLARITY(&htim1 ,TIM_CHANNEL_1 ,TIM_INPUTCHANNELPOLARITY_FALLING) ;
			flag++;

		}
		else if (flag == 1) {

			flag++;
			T2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
			//Input Capture Edge Select rising edge
			__HAL_TIM_SET_CAPTUREPOLARITY(&htim1 ,TIM_CHANNEL_1 ,TIM_INPUTCHANNELPOLARITY_RISING) ;
		}
		else {
			/*nothing*/
		}

	}

	else if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2)
	{
		if (flag == 0) {

			T1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);
			//Input Capture Edge Select falling edge
			__HAL_TIM_SET_CAPTUREPOLARITY(&htim1 ,TIM_CHANNEL_2 ,TIM_INPUTCHANNELPOLARITY_FALLING) ;
			flag++;

		}
		else if (flag == 1) {

			flag++;
			T2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);
			//Input Capture Edge Select rising edge
			__HAL_TIM_SET_CAPTUREPOLARITY(&htim1 ,TIM_CHANNEL_2 ,TIM_INPUTCHANNELPOLARITY_RISING) ;
		}
		else
		{
			/*nothing**/
		}
	}


	else if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_3)
	{
		if (flag == 0) {

			T1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_3);
			//Input Capture Edge Select falling edge
			__HAL_TIM_SET_CAPTUREPOLARITY(&htim1 ,TIM_CHANNEL_3 ,TIM_INPUTCHANNELPOLARITY_FALLING) ;
			flag++;

		}
		else if (flag == 1) {

			flag++;
			T2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_3);
			//Input Capture Edge Select rising edge
			__HAL_TIM_SET_CAPTUREPOLARITY(&htim1 ,TIM_CHANNEL_3 ,TIM_INPUTCHANNELPOLARITY_RISING) ;
		}
		else
		{
			/*nothing**/
		}
	}

	else
	{
		if (flag == 0) {

			T1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_4);
			//Input Capture Edge Select falling edge
			__HAL_TIM_SET_CAPTUREPOLARITY(&htim1 ,TIM_CHANNEL_4 ,TIM_INPUTCHANNELPOLARITY_FALLING) ;
			flag++;

		}
		else if (flag == 1) {

			flag++;
			T2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_4);
			//Input Capture Edge Select rising edge
			__HAL_TIM_SET_CAPTUREPOLARITY(&htim1 ,TIM_CHANNEL_4 ,TIM_INPUTCHANNELPOLARITY_RISING) ;
		}
		else
		{
			/*nothing**/
		}
	}
	__HAL_TIM_SET_COUNTER(htim, 0);
}

void ultrasonic_voidInit(void) {

	HAL_TIM_IC_Start_IT(&htim1 ,TIM_CHANNEL_1) ;
	HAL_TIM_IC_Start_IT(&htim1 ,TIM_CHANNEL_2) ;
	HAL_TIM_IC_Start_IT(&htim1 ,TIM_CHANNEL_3) ;
	HAL_TIM_IC_Start_IT(&htim1 ,TIM_CHANNEL_4) ;


}

float ultrasonic1_voidGetDistance(void)
{
	float distance;

	HAL_GPIO_WritePin(TRIG_PORT_1, TRIG_PIN_1, GPIO_PIN_SET);
	Udelay_us(10);
	HAL_GPIO_WritePin(TRIG_PORT_1, TRIG_PIN_1, GPIO_PIN_RESET);
	__HAL_TIM_ENABLE_IT(&htim1, TIM_IT_CC1);
	while (flag < 2);

	if(T2>T1)
	{
		distance =  (T2 - T1)*.034/2;
	}
	else
	{
		distance = ((0xffff - T1) + T2)*.034/2;
	}

	flag = 0;
	return distance;
}


float ultrasonic2_voidGetDistance(void)
{
	float distance;

	HAL_GPIO_WritePin(TRIG_PORT_2, TRIG_PIN_2, GPIO_PIN_SET);
	Udelay_us(10);
	HAL_GPIO_WritePin(TRIG_PORT_2, TRIG_PIN_2, GPIO_PIN_RESET);
	__HAL_TIM_ENABLE_IT(&htim1, TIM_IT_CC2);
	while (flag < 2);

	if(T2>T1)
	{
		distance =  (T2 - T1)*.034/2;
	}
	else
	{
		distance = ((0xffff - T1) + T2)*.034/2;
	}

	flag = 0;
	return distance;
}


float ultrasonic3_voidGetDistance(void)
{
	float distance;


	HAL_GPIO_WritePin(TRIG_PORT_3, TRIG_PIN_3, GPIO_PIN_SET);
	Udelay_us(10);
	HAL_GPIO_WritePin(TRIG_PORT_3, TRIG_PIN_3, GPIO_PIN_RESET);
	__HAL_TIM_ENABLE_IT(&htim1, TIM_IT_CC3);
	while (flag < 2);

	if(T2>T1)
	{
		distance =  (T2 - T1)*.034/2;
	}
	else
	{
		distance = ((0xffff - T1) + T2)*.034/2;
	}

	flag = 0;
	return distance;
}

float ultrasonic4_voidGetDistance(void)
{
	float distance;

	HAL_GPIO_WritePin(TRIG_PORT_4, TRIG_PIN_4, GPIO_PIN_SET);
	Udelay_us(10);
	HAL_GPIO_WritePin(TRIG_PORT_4, TRIG_PIN_4, GPIO_PIN_RESET);
	__HAL_TIM_ENABLE_IT(&htim1, TIM_IT_CC4);
	while (flag < 2);
	if(T2>T1)
	{
		distance =  (T2 - T1)*.034/2;
	}
	else
	{
		distance = ((0xffff - T1) + T2)*.034/2;
	}

	flag = 0;
	return distance;
}

void Udelay_us (uint16_t us)
{
	__HAL_TIM_SET_COUNTER(&htim1, 0);
	while (__HAL_TIM_GET_COUNTER(&htim1) < us);
}

