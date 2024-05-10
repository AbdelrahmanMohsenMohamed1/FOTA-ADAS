/*
 * IR.c
 *
 *  Created on: Apr 30, 2024
 *      Author: Abdelrahman
 */


#include "IR.h"

uint8_t IR_LF_Left_u8ObstacleDetect()
{
	uint8_t obstacle_detected = HAL_GPIO_ReadPin(IR_LF_Left_PORT,IR_LF_Left_PIN);
	return obstacle_detected;
}

uint8_t IR_LF_Mid_u8ObstacleDetect()
{
	uint8_t obstacle_detected = HAL_GPIO_ReadPin(IR_LF_Mid_PORT,IR_LF_Mid_PIN);
	return obstacle_detected;
}

uint8_t IR_LF_Right_u8ObstacleDetect()
{
	uint8_t obstacle_detected = HAL_GPIO_ReadPin(IR_LF_Right_PORT,IR_LF_Right_PIN);
	return obstacle_detected;
}

uint8_t IR1_u8ObstacleDetect()
{
	uint8_t obstacle_detected = HAL_GPIO_ReadPin(IR1_PORT,IR1_PIN);
	return obstacle_detected;
}

uint8_t IR2_u8ObstacleDetect()
{
	uint8_t obstacle_detected = HAL_GPIO_ReadPin(IR2_PORT,IR2_PIN);
	return obstacle_detected;
}

uint8_t IR3_u8ObstacleDetect()
{
	uint8_t obstacle_detected = HAL_GPIO_ReadPin(IR3_PORT,IR3_PIN);
	return obstacle_detected;
}

uint8_t IR4_u8ObstacleDetect()
{
	uint8_t obstacle_detected = HAL_GPIO_ReadPin(IR4_PORT,IR4_PIN);
	return obstacle_detected;
}

