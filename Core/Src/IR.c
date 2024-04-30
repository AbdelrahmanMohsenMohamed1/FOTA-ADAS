/*
 * IR.c
 *
 *  Created on: Apr 30, 2024
 *      Author: Abdelrahman
 */


#include "IR.h"

uint8_t IR1_u8ObstacleDetect(){
	uint8_t obstacle_detected = HAL_GPIO_ReadPin(IR_PORT,IR_PIN_1);
	return obstacle_detected;
}

uint8_t IR2_u8ObstacleDetect(){
	uint8_t obstacle_detected = HAL_GPIO_ReadPin(IR_PORT,IR_PIN_2);
	return obstacle_detected;
}

uint8_t IR3_u8ObstacleDetect(){
	uint8_t obstacle_detected = HAL_GPIO_ReadPin(IR_PORT,IR_PIN_3);
	return obstacle_detected;
}

uint8_t IR4_u8ObstacleDetect(){
	uint8_t obstacle_detected = HAL_GPIO_ReadPin(IR_PORT,IR_PIN_4);
	return obstacle_detected;
}
