/*
 * Ultrasonic.c
 *
 *  Created on: Apr 29, 2024
 *      Author: Amira
 */

#include "Ultrasonic.h"
#include "Ultrasonic_Confg.h"
extern TIM_HandleTypeDef htim1;

uint32_t IC_Val1 = 0;
uint32_t IC_Val2 = 0;
uint32_t Difference = 0;
uint8_t Is_First_Captured = 0;  // is the first value captured ?
uint8_t Distance  = 0;



// Let's write the callback function

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)  // if the interrupt source is channel1
	{
		if (Is_First_Captured==0) // if the first value is not captured
		{
			IC_Val1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1); // read the first value
			Is_First_Captured = 1;  // set the first captured as true
			// Now change the polarity to falling edge
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_FALLING);
		}

		else if (Is_First_Captured==1)   // if the first is already captured
		{
			IC_Val2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);  // read second value
			__HAL_TIM_SET_COUNTER(htim, 0);  // reset the counter

			if (IC_Val2 > IC_Val1)
			{
				Difference = IC_Val2-IC_Val1;
			}

			else if (IC_Val1 > IC_Val2)
			{
				Difference = (0xffff - IC_Val1) + IC_Val2;
			}

			Distance = Difference * .034/2;
			Is_First_Captured = 0; // set it back to false

			// set polarity to rising edge
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_RISING);
			__HAL_TIM_DISABLE_IT(&htim1, TIM_IT_CC1);
		}
	}

	else if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2)  // if the interrupt source is channel1
	{
		if (Is_First_Captured==0) // if the first value is not captured
		{
			IC_Val1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1); // read the first value
			Is_First_Captured = 1;  // set the first captured as true
			// Now change the polarity to falling edge
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_FALLING);
		}

		else if (Is_First_Captured==1)   // if the first is already captured
		{
			IC_Val2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);  // read second value
			__HAL_TIM_SET_COUNTER(htim, 0);  // reset the counter

			if (IC_Val2 > IC_Val1)
			{
				Difference = IC_Val2-IC_Val1;
			}

			else if (IC_Val1 > IC_Val2)
			{
				Difference = (0xffff - IC_Val1) + IC_Val2;
			}

			Distance = Difference * .034/2;
			Is_First_Captured = 0; // set it back to false

			// set polarity to rising edge
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_RISING);
			__HAL_TIM_DISABLE_IT(&htim1, TIM_IT_CC1);
		}

	}
}

void ultrasonic_voidInit(void) {

	HAL_TIM_IC_Start_IT(&htim1 ,TIM_CHANNEL_1) ;
	HAL_TIM_IC_Start_IT(&htim1 ,TIM_CHANNEL_2) ;
	HAL_TIM_IC_Start_IT(&htim1 ,TIM_CHANNEL_3) ;
	HAL_TIM_IC_Start_IT(&htim1 ,TIM_CHANNEL_4) ;


}

uint8_t UltraSonic1_Read (void)
{
	HAL_GPIO_WritePin(TRIG_PORT_1, TRIG_PIN_1, GPIO_PIN_SET);  // pull the TRIG pin HIGH
	Udelay(10);  // wait for 10 us
	HAL_GPIO_WritePin(TRIG_PORT_1, TRIG_PIN_1, GPIO_PIN_RESET);  // pull the TRIG pin low

	__HAL_TIM_ENABLE_IT(&htim1, TIM_IT_CC1);
}
uint8_t UltraSonic2_Read (void)
{
	HAL_GPIO_WritePin(TRIG_PORT_2, TRIG_PIN_2, GPIO_PIN_SET);  // pull the TRIG pin HIGH
	Udelay(10);  // wait for 10 us
	HAL_GPIO_WritePin(TRIG_PORT_2, TRIG_PIN_2, GPIO_PIN_RESET);  // pull the TRIG pin low

	__HAL_TIM_ENABLE_IT(&htim1, TIM_IT_CC2);
}

void Udelay_us (uint16_t us)
{
	__HAL_TIM_SET_COUNTER(&htim1, 0);
	while (__HAL_TIM_GET_COUNTER(&htim1) < us);
}

