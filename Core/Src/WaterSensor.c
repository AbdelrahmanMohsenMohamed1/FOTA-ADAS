/*
 * WaterSensor.c
 *
 *  Created on: Apr 30, 2024
 *      Author: Abdelrahman
 */


#include "WaterSensor.h"

uint8_t Water_Sensor_u8WaterDetect(){
	uint8_t water_detected = HAL_GPIO_ReadPin(Water_Sensor_PORT,Water_Sensor_Pin);
	return water_detected;
}
