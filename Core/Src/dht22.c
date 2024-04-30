/*
 * dht22.c
 *
 *  Created on: Apr 27, 2024
 *      Author: ahmed
 */
#include "dht22.h"

uint32_t pMillis, cMillis;
extern TIM_HandleTypeDef htim1;

void Set_DHT22_Output(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = DHT22_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(DHT22_PORT, &GPIO_InitStruct);
}

void Set_DHT22_Iutput(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = DHT22_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(DHT22_PORT, &GPIO_InitStruct);
}

uint8_t DHT22_StartSignal(void)
{
	uint8_t Response = 0; // Response flag

	Set_DHT22_Output();
	HAL_GPIO_WritePin(DHT22_PORT, DHT22_PIN, GPIO_PIN_RESET);
	delay_us(1200);
	HAL_GPIO_WritePin(DHT22_PORT, DHT22_PIN, GPIO_PIN_SET);
	delay_us(40);
	Set_DHT22_Iutput();
	delay_us(40); // Wait for sensor to start transmitting data

	if (!(HAL_GPIO_ReadPin(DHT22_PORT, DHT22_PIN)))
	{
		delay_us(80); // Wait for sensor response
		if ((HAL_GPIO_ReadPin(DHT22_PORT, DHT22_PIN)))
		{
			Response = 1; // Set response flag if sensor responds
		}
	}

	pMillis = HAL_GetTick(); // Get current time in milliseconds
	cMillis = HAL_GetTick();

	// Wait for sensor response or timeout
	while ((HAL_GPIO_ReadPin(DHT22_PORT, DHT22_PIN)) && pMillis + 2 > cMillis)
	{
		cMillis = HAL_GetTick(); // Update current time
	}

	return Response;
}

uint8_t DHT22_Read(void)
{
	uint8_t i, Received_Bits;

	for (i = 0; i < 8; i++)
	{
		pMillis = HAL_GetTick();
		cMillis = HAL_GetTick();

		while (!(HAL_GPIO_ReadPin(DHT22_PORT, DHT22_PIN)) && pMillis + 2 > cMillis)
		{
			cMillis = HAL_GetTick(); 	//Update current time
		}
		delay_us(40); 	//Wait for the data bit

		if (!(HAL_GPIO_ReadPin(DHT22_PORT, DHT22_PIN)))
		{
			Received_Bits &= ~(1 << (7 - i)); 	//Clear
		}
		else
		{
			Received_Bits |= (1 << (7 - i)); 	//Set
		}

		pMillis = HAL_GetTick(); // Get start time for next bit reading
		cMillis = HAL_GetTick();

		// Wait for the pin to go low (end of data bit)
		while ((HAL_GPIO_ReadPin(DHT22_PORT, DHT22_PIN)) && pMillis + 2 > cMillis)
		{
			cMillis = HAL_GetTick(); // Update current time
		}
	}
	return Received_Bits;
}

uint8_t DHT22_GetTemperature(void)
{
	uint8_t RH1, RH2, TC1, TC2, SUM, CHECK;

	float Temperature = 0; 		// Temperature in Celsius
	if (DHT22_StartSignal())
	{
		RH1 = DHT22_Read();
		RH2 = DHT22_Read();
		TC1 = DHT22_Read();
		TC2 = DHT22_Read();
		SUM = DHT22_Read();

		// Calculate checksum
		CHECK = RH1 + RH2 + TC1 + TC2;

		// Verify checksum and process data if valid
		if (CHECK == SUM)
		{
			// Check for negative temperature
			if (TC1 > 127)
			{
				Temperature = (float)TC2 / 10 * (-1);
			}
			else
			{
				Temperature = (float)((TC1 << 8) | TC2) / 10;
			}
		}
        HAL_Delay(1000); // Delay before reading data again
	}
	return Temperature;
}

void delay_us (uint16_t us)
{
	__HAL_TIM_SET_COUNTER(&htim1, 0);
	while (__HAL_TIM_GET_COUNTER(&htim1) < us);
}

