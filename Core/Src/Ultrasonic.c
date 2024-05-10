/*
 * Ultrasonic.c
 *
 *  Created on: Apr 29, 2024
 *      Author: Amira
 */

#include "Ultrasonic.h"
#include "Ultrasonic_Confg.h"
extern TIM_HandleTypeDef htim1;

uint8_t  flag[NUMBER_OF_SENSOR] = {ZERO};
uint32_t T1[NUMBER_OF_SENSOR]={ZERO},T2[NUMBER_OF_SENSOR]={ZERO};


/**
 * @brief This function handles TIM1 capture compare interrupt.
 */
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{


	/* USER CODE BEGIN voidTIM1_CC_IRQn 0 */
	if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)
	{
		if (flag[INDEX_0] == NO_ACK ) {

			T1[INDEX_0] = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
			//Input Capture Edge Select falling edge
			__HAL_TIM_SET_CAPTUREPOLARITY(&htim1 ,TIM_CHANNEL_1 ,TIM_INPUTCHANNELPOLARITY_FALLING) ;
			flag[INDEX_0]++;

		}
		else if (flag[INDEX_0] == ACK) {

			flag[INDEX_0]++;
			T2[INDEX_0] = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
			//Input Capture Edge Select rising edge
			__HAL_TIM_SET_CAPTUREPOLARITY(&htim1 ,TIM_CHANNEL_1 ,TIM_INPUTCHANNELPOLARITY_RISING) ;
			__HAL_TIM_SET_COUNTER(htim,ZERO);
			__HAL_TIM_DISABLE_IT(&htim1, TIM_IT_CC1);
		}
		else {
			/*nothing*/
		}

	}

	else if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2)
	{
		if (flag[INDEX_1] == NO_ACK) {

			T1[INDEX_1] = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);
			//Input Capture Edge Select falling edge
			__HAL_TIM_SET_CAPTUREPOLARITY(&htim1 ,TIM_CHANNEL_2 ,TIM_INPUTCHANNELPOLARITY_FALLING) ;
			flag[INDEX_1]++;

		}
		else if (flag[INDEX_1] == ACK) {

			flag[INDEX_1]++;
			T2[INDEX_1] = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);
			//Input Capture Edge Select rising edge
			__HAL_TIM_SET_CAPTUREPOLARITY(&htim1 ,TIM_CHANNEL_2 ,TIM_INPUTCHANNELPOLARITY_RISING) ;
			__HAL_TIM_SET_COUNTER(htim,ZERO);
			__HAL_TIM_DISABLE_IT(&htim1, TIM_IT_CC2);
		}
		else
		{
			/*nothing**/
		}
	}


	else if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_3)
	{
		if (flag[INDEX_2] == NO_ACK) {

			T1[INDEX_2] = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_3);
			//Input Capture Edge Select falling edge
			__HAL_TIM_SET_CAPTUREPOLARITY(&htim1 ,TIM_CHANNEL_3 ,TIM_INPUTCHANNELPOLARITY_FALLING) ;
			flag[INDEX_2]++;

		}
		else if (flag[INDEX_2] == ACK) {

			flag[INDEX_2]++;
			T2[INDEX_2] = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_3);
			//Input Capture Edge Select rising edge
			__HAL_TIM_SET_CAPTUREPOLARITY(&htim1 ,TIM_CHANNEL_3 ,TIM_INPUTCHANNELPOLARITY_RISING) ;
			__HAL_TIM_SET_COUNTER(htim,ZERO);
			__HAL_TIM_DISABLE_IT(&htim1, TIM_IT_CC3);
		}
		else
		{
			/*nothing**/
		}
	}

	else if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_4)
	{
		if (flag[INDEX_3] == NO_ACK) {

			T1[INDEX_3] = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_4);
			//Input Capture Edge Select falling edge
			__HAL_TIM_SET_CAPTUREPOLARITY(&htim1 ,TIM_CHANNEL_4 ,TIM_INPUTCHANNELPOLARITY_FALLING) ;
			flag[INDEX_3]++;

		}
		else if (flag[INDEX_3] == ACK) {

			flag[INDEX_3]++;
			T2[INDEX_3]= HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_4);
			//Input Capture Edge Select rising edge
			__HAL_TIM_SET_CAPTUREPOLARITY(&htim1 ,TIM_CHANNEL_4 ,TIM_INPUTCHANNELPOLARITY_RISING) ;
			__HAL_TIM_SET_COUNTER(htim,ZERO);
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

float FrontUltrasonic_voidGetDistance(void)
{
	float distance;
	uint8_t time =ZERO;

	HAL_GPIO_WritePin(TRIG_PORT_1, TRIG_PIN_1, GPIO_PIN_SET);
	delay(10);
	HAL_GPIO_WritePin(TRIG_PORT_1, TRIG_PIN_1, GPIO_PIN_RESET);
	__HAL_TIM_ENABLE_IT(&htim1, TIM_IT_CC1);
	while (flag[INDEX_0] < FLAG_CHECK && time <RUN_TIME_OUT)
	{
		time++;
		HAL_Delay(DELAY_1MILLI);
	}

	if(T2[INDEX_0]>T1[INDEX_0])
	{
		distance =  (T2[INDEX_0] - T1[INDEX_0])* VELOCITY /DIVIDE_BY_TWO;
	}
	else
	{
		distance = ((0xffff - T1[INDEX_0]) + T2[INDEX_0])*VELOCITY/DIVIDE_BY_TWO;
	}

	if(distance>MAX_DISTANCE)
	{
		distance=MAX_DISTANCE;
	}
	else
	{
		/* do nothing */
	}

	flag[INDEX_0] = ZERO;
	return distance;
}


uint8_t RearUltrasonic_voidGetDistance(void)
{
	uint8_t distance;
	uint8_t time =ZERO;
	HAL_GPIO_WritePin(TRIG_PORT_2, TRIG_PIN_2, GPIO_PIN_SET);
	delay(10);
	HAL_GPIO_WritePin(TRIG_PORT_2, TRIG_PIN_2, GPIO_PIN_RESET);
	__HAL_TIM_ENABLE_IT(&htim1, TIM_IT_CC2);
	while (flag[INDEX_1] < FLAG_CHECK&& time <RUN_TIME_OUT)
	{
		time++;
		HAL_Delay(DELAY_1MILLI);
	}

	if(T2[INDEX_1]>T1[INDEX_1])
	{
		distance =  (T2[INDEX_1] - T1[INDEX_1]) * VELOCITY/DIVIDE_BY_TWO;
	}
	else
	{
		distance = ((0xffff - T1[INDEX_1]) + T2[INDEX_1])*VELOCITY/DIVIDE_BY_TWO;
	}
	if(distance>MAX_DISTANCE)
	{
		distance=MAX_DISTANCE;
	}
	else
	{
		/* do nothing */
	}
	flag[INDEX_1] = ZERO;
	return distance;
}


uint8_t RightUltrasonic_voidGetDistance(void)
{
	uint8_t distance;
	uint8_t time =ZERO;

	HAL_GPIO_WritePin(TRIG_PORT_3, TRIG_PIN_3, GPIO_PIN_SET);
	delay(10);
	HAL_GPIO_WritePin(TRIG_PORT_3, TRIG_PIN_3, GPIO_PIN_RESET);
	__HAL_TIM_ENABLE_IT(&htim1, TIM_IT_CC3);
	while (flag[INDEX_2] < FLAG_CHECK && time <RUN_TIME_OUT)
	{
		time++;
		HAL_Delay(DELAY_1MILLI);
	}

	if(T2[INDEX_2]>T1[INDEX_2])
	{
		distance =  (T2[INDEX_2] - T1[INDEX_2])*VELOCITY/DIVIDE_BY_TWO;
	}
	else
	{
		distance = ((0xffff - T1[INDEX_2]) + T2[INDEX_2])*VELOCITY/DIVIDE_BY_TWO;
	}
	if(distance>MAX_DISTANCE)
	{
		distance=MAX_DISTANCE;
	}
	else
	{
		/* do nothing */
	}
	flag[INDEX_2] = ZERO;
	return distance;
}

uint8_t LeftUltrasonic_voidGetDistance(void)
{
	uint8_t distance;
	uint8_t time =ZERO;
	HAL_GPIO_WritePin(TRIG_PORT_4, TRIG_PIN_4, GPIO_PIN_SET);
	delay(10);
	HAL_GPIO_WritePin(TRIG_PORT_4, TRIG_PIN_4, GPIO_PIN_RESET);
	__HAL_TIM_ENABLE_IT(&htim1, TIM_IT_CC4);
	while (flag[INDEX_3] < FLAG_CHECK && time <RUN_TIME_OUT)
	{
		time++;
		HAL_Delay(DELAY_1MILLI);
	}

	if(T2[INDEX_3]>T1[INDEX_3])
	{
		distance =  (T2[INDEX_3] - T1[INDEX_3])*VELOCITY/DIVIDE_BY_TWO;
	}
	else
	{
		distance = ((0xffff - T1[INDEX_3]) + T2[INDEX_3])*VELOCITY/DIVIDE_BY_TWO;
	}
	if(distance>MAX_DISTANCE)
	{
		distance = MAX_DISTANCE;
	}
	else
	{
		/* do nothing */
	}
	flag[INDEX_3] = ZERO;
	return distance;
}

void delay(uint16_t us)
{
	__HAL_TIM_SET_COUNTER(&htim1, ZERO);
	while (__HAL_TIM_GET_COUNTER(&htim1) < us);
}

