/*
 * Ultrasonic.c
 *
 *  Created on: May 2, 2024
 *      Author: Abdelrahman
 */

#include "Ultrasonic.h"
#include "main.h"

extern TIM_HandleTypeDef htim1;

void delay (uint16_t time)
{
	__HAL_TIM_SET_COUNTER(&htim1, 0);
	while (__HAL_TIM_GET_COUNTER (&htim1) < time);
}

uint32_t IC1_Val1 = 0;
uint32_t IC1_Val2 = 0;
uint32_t Difference1 = 0;
uint8_t Is_First_Captured1 = 0;  // is the first value captured ?
uint8_t Distance1  = 0;


uint32_t IC2_Val1 = 0;
uint32_t IC2_Val2 = 0;
uint32_t Difference2 = 0;
uint8_t Is_First_Captured2 = 0;  // is the first value captured ?
uint8_t Distance2  = 0;


uint32_t IC3_Val1 = 0;
uint32_t IC3_Val2 = 0;
uint32_t Difference3 = 0;
uint8_t Is_First_Captured3 = 0;  // is the first value captured ?
uint8_t Distance3  = 0;



uint32_t IC4_Val1 = 0;
uint32_t IC4_Val2 = 0;
uint32_t Difference4 = 0;
uint8_t Is_First_Captured4 = 0;  // is the first value captured ?
uint8_t Distance4  = 0;



// Let's write the callback function

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	if (   (htim == &htim1)  && htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)  // if the interrupt source is channel1
	{
		if (Is_First_Captured1==0) // if the first value is not captured
		{
			IC1_Val1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1); // read the first value
			Is_First_Captured1 = 1;  // set the first captured as true
			// Now change the polarity to falling edge
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_FALLING);
		}

		else if (Is_First_Captured1==1)   // if the first is already captured
		{
			IC1_Val2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);  // read second value
			__HAL_TIM_SET_COUNTER(htim, 0);  // reset the counter

			if (IC1_Val2 > IC1_Val1)
			{
				Difference1 = IC1_Val2-IC1_Val1;
			}

			else if (IC1_Val1 > IC1_Val2)
			{
				Difference1 = (0xffff - IC1_Val1) + IC1_Val2;
			}

			Distance1 = Difference1 * .034/2;
			Is_First_Captured1 = 0; // set it back to false

			// set polarity to rising edge
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_RISING);
			__HAL_TIM_DISABLE_IT(&htim1, TIM_IT_CC1);
		}
	}

	if ((htim == &htim1)  && htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2)  // if the interrupt source is channel1
	{
		if (Is_First_Captured2==0) // if the first value is not captured
		{
			IC2_Val1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2); // read the first value
			Is_First_Captured2 = 1;  // set the first captured as true
			// Now change the polarity to falling edge
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_2, TIM_INPUTCHANNELPOLARITY_FALLING);
		}

		else if (Is_First_Captured2==1)   // if the first is already captured
		{
			IC2_Val2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);  // read second value
			__HAL_TIM_SET_COUNTER(htim, 0);  // reset the counter

			if (IC2_Val2 > IC2_Val1)
			{
				Difference2 = IC2_Val2-IC2_Val1;
			}

			else if (IC2_Val1 > IC2_Val2)
			{
				Difference2 = (0xffff - IC2_Val1) + IC2_Val2;
			}

			Distance2 = Difference2 * .034/2;
			Is_First_Captured2 = 0; // set it back to false

			// set polarity to rising edge
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_2, TIM_INPUTCHANNELPOLARITY_RISING);
			__HAL_TIM_DISABLE_IT(&htim1, TIM_IT_CC2);
		}
	}

	if ((htim == &htim1)  && htim->Channel == HAL_TIM_ACTIVE_CHANNEL_3)  // if the interrupt source is channel1
	{
		if (Is_First_Captured3==0) // if the first value is not captured
		{
			IC3_Val1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_3); // read the first value
			Is_First_Captured3 = 1;  // set the first captured as true
			// Now change the polarity to falling edge
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_3, TIM_INPUTCHANNELPOLARITY_FALLING);
		}

		else if (Is_First_Captured3==1)   // if the first is already captured
		{
			IC3_Val2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_3);  // read second value
			__HAL_TIM_SET_COUNTER(htim, 0);  // reset the counter

			if (IC3_Val2 > IC3_Val1)
			{
				Difference3 = IC3_Val2-IC3_Val1;
			}

			else if (IC3_Val1 > IC3_Val2)
			{
				Difference3 = (0xffff - IC3_Val1) + IC3_Val2;
			}

			Distance3 = Difference3 * .034/2;
			Is_First_Captured3 = 0; // set it back to false

			// set polarity to rising edge
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_3, TIM_INPUTCHANNELPOLARITY_RISING);
			__HAL_TIM_DISABLE_IT(&htim1, TIM_IT_CC3);
		}
	}




	if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_4)  // if the interrupt source is channel1
	{
		if (Is_First_Captured4==0) // if the first value is not captured
		{
			IC4_Val1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_4); // read the first value
			Is_First_Captured4 = 1;  // set the first captured as true
			// Now change the polarity to falling edge
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_4, TIM_INPUTCHANNELPOLARITY_FALLING);
		}

		else if (Is_First_Captured4==1)   // if the first is already captured
		{
			IC4_Val2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_4);  // read second value
			__HAL_TIM_SET_COUNTER(htim, 0);  // reset the counter

			if (IC4_Val2 > IC4_Val1)
			{
				Difference4 = IC4_Val2-IC4_Val1;
			}

			else if (IC4_Val1 > IC4_Val2)
			{
				Difference4 = (0xffff - IC4_Val1) + IC4_Val2;
			}

			Distance4 = Difference4 * .034/2;
			Is_First_Captured4 = 0; // set it back to false

			// set polarity to rising edge
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_4, TIM_INPUTCHANNELPOLARITY_RISING);
			__HAL_TIM_DISABLE_IT(&htim1, TIM_IT_CC4);
		}
	}
}

void HCSR04_Read1 (void)
{
	HAL_GPIO_WritePin(TRIG_PORT_1, TRIG_PIN_1, GPIO_PIN_SET);  // pull the TRIG pin HIGH
	delay(10);  // wait for 10 us
	HAL_GPIO_WritePin(TRIG_PORT_1, TRIG_PIN_1, GPIO_PIN_RESET);  // pull the TRIG pin low

	__HAL_TIM_ENABLE_IT(&htim1, TIM_IT_CC1);
}

void HCSR04_Read2 (void)
{
	HAL_GPIO_WritePin(TRIG_PORT_2, TRIG_PIN_2, GPIO_PIN_SET);  // pull the TRIG pin HIGH
	delay(10);  // wait for 10 us
	HAL_GPIO_WritePin(TRIG_PORT_2, TRIG_PIN_2, GPIO_PIN_RESET);  // pull the TRIG pin low

	__HAL_TIM_ENABLE_IT(&htim1, TIM_IT_CC2);
}

void HCSR04_Read3 (void)
{
	HAL_GPIO_WritePin(TRIG_PORT_3, TRIG_PIN_3, GPIO_PIN_SET);  // pull the TRIG pin HIGH
	delay(10);  // wait for 10 us
	HAL_GPIO_WritePin(TRIG_PORT_3, TRIG_PIN_3, GPIO_PIN_RESET);  // pull the TRIG pin low

	__HAL_TIM_ENABLE_IT(&htim1, TIM_IT_CC3);
}
void HCSR04_Read4 (void)
{
	HAL_GPIO_WritePin(TRIG_PORT_4, TRIG_PIN_4, GPIO_PIN_SET);  // pull the TRIG pin HIGH
	delay(10);  // wait for 10 us
	HAL_GPIO_WritePin(TRIG_PORT_4, TRIG_PIN_4, GPIO_PIN_RESET);  // pull the TRIG pin low

	__HAL_TIM_ENABLE_IT(&htim1, TIM_IT_CC4);
}

