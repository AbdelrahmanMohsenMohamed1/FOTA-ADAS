/*
 * Water_Sensor_Program.c
 *
 *  Created on: Apr 27, 2024
 *      Author: Dell
 */

#include "Water_Sensor_Interface.h"

uint8_t Water_Sensor_u8WaterDetect(){
	uint8_t water_detected = HAL_GPIO_ReadPin(Water_Sensor_PORT,Water_Sensor_Pin);
	return water_detected;
}

