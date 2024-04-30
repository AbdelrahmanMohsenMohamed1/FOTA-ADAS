/*
 * dht22.h
 *
 *  Created on: Apr 27, 2024
 *      Author: ahmed
 */

#ifndef INC_DHT22_H_
#define INC_DHT22_H_
#include "stm32f1xx_hal.h"

#define DHT22_PORT		GPIOA
#define DHT22_PIN		GPIO_PIN_8

void Set_DHT22_Output(void);

void Set_DHT22_Iutput(void);

uint8_t DHT22_StartSignal(void);

uint8_t DHT22_Read(void);

uint8_t DHT22_GetTemperature(void);

void delay_us (uint16_t us);

#endif /* INC_DHT22_H_ */
