/*
 * Motor.c
 *
 *  Created on: May 1, 2024
 *      Author: Amr
 */

#include "Motor.h"

void Motor_Start()
{
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);

}

void Motor_voidStop(void)
{
	HAL_TIMEx_PWMN_Stop(&htim2, TIM_CHANNEL_1);
	HAL_TIMEx_PWMN_Stop(&htim2, TIM_CHANNEL_2);
	HAL_GPIO_WritePin(RearMotor_INT1_GPIO_Port, RearMotor_INT1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RearMotor_INT2_GPIO_Port, RearMotor_INT2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(FrontMotor_INT1_GPIO_Port, FrontMotor_INT1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(FrontMotor_INT2_GPIO_Port, FrontMotor_INT2_Pin, GPIO_PIN_RESET);

}

/*
 * values of speed between 1 ----> 500
 */
void Motor_SetSpeed(uint8_t copy_u8Speed)
{

	TIM2->CCR1 = copy_u8Speed;
	TIM2->CCR2 = copy_u8Speed;
}

void Motor_voidMoveForward(void)
{
	HAL_GPIO_WritePin(RearMotor_INT1_GPIO_Port, RearMotor_INT1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RearMotor_INT2_GPIO_Port, RearMotor_INT2_Pin, GPIO_PIN_SET);

}

void Motor_voidMoveBackward(void)
{
	HAL_GPIO_WritePin(RearMotor_INT1_GPIO_Port, RearMotor_INT1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(RearMotor_INT2_GPIO_Port, RearMotor_INT2_Pin, GPIO_PIN_RESET);
}

void Motor_voidTurnRight(void)
{

	//Turn right
	HAL_GPIO_WritePin(FrontMotor_INT1_GPIO_Port, FrontMotor_INT1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(FrontMotor_INT2_GPIO_Port, FrontMotor_INT2_Pin, GPIO_PIN_SET);


}

void Motor_voidTurnLeft(void)
{

	//Turn left
	HAL_GPIO_WritePin(FrontMotor_INT1_GPIO_Port, FrontMotor_INT1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(FrontMotor_INT2_GPIO_Port, FrontMotor_INT2_Pin, GPIO_PIN_RESET);
}