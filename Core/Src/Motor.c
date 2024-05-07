/*
 * Motor.c
 *
 *  Created on: May 1, 2024
 *      Author: Amr
 */

#include "Motor.h"

#define RearMotor_INT1_GPIO_Port GPIOA
#define RearMotor_INT1_Pin GPIO_PIN_4

#define RearMotor_INT2_GPIO_Port GPIOA
#define RearMotor_INT2_Pin GPIO_PIN_5

#define FrontMotor_INT1_GPIO_Port GPIOA
#define FrontMotor_INT1_Pin GPIO_PIN_6

#define FrontMotor_INT2_GPIO_Port GPIOA
#define FrontMotor_INT2_Pin GPIO_PIN_7


void Motor_Start()
{
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
//	TIM2->CCR2 = 0;
//	TIM2->CCR1 = 0;

}

void Motor_voidStopFront(void)
{
	HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_2);
	HAL_GPIO_WritePin(FrontMotor_INT1_GPIO_Port, FrontMotor_INT1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(FrontMotor_INT2_GPIO_Port, FrontMotor_INT2_Pin, GPIO_PIN_RESET);

}

void Motor_voidStopRear(void)
{
	HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_1);
	HAL_GPIO_WritePin(RearMotor_INT1_GPIO_Port, RearMotor_INT1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RearMotor_INT2_GPIO_Port, RearMotor_INT2_Pin, GPIO_PIN_RESET);
}

/*
 * values of speed between 1 ----> 500
 */
void Motor_SetSpeedFront(uint8_t copy_u8Speed)
{

	TIM2->CCR1 = copy_u8Speed;

}

void Motor_SetSpeedRear(uint8_t copy_u8Speed)
{
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
