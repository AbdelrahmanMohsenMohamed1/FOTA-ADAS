/*
 * Motor.c
 *
 *  Created on: May 1, 2024
 *      Author: Amr
 */

#include "Motor.h"

#define RearMotor_INT1_GPIO_Port GPIOA
#define RearMotor_INT1_Pin GPIO_PIN_1

#define RearMotor_INT2_GPIO_Port GPIOA
#define RearMotor_INT2_Pin GPIO_PIN_1

#define FrontMotor_INT1_GPIO_Port GPIOA
#define FrontMotor_INT1_Pin GPIO_PIN_1

#define FrontMotor_INT2_GPIO_Port GPIOA
#define FrontMotor_INT2_Pin GPIO_PIN_1
/*
void Motor_Start() {
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);

}

void Motor_voidStop(void) {
	HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_1);
	HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_2);
	HAL_GPIO_WritePin(RearMotor_INT1_GPIO_Port, RearMotor_INT1_Pin,
			GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RearMotor_INT2_GPIO_Port, RearMotor_INT2_Pin,
			GPIO_PIN_RESET);
	HAL_GPIO_WritePin(FrontMotor_INT1_GPIO_Port, FrontMotor_INT1_Pin,
			GPIO_PIN_RESET);
	HAL_GPIO_WritePin(FrontMotor_INT2_GPIO_Port, FrontMotor_INT2_Pin,
			GPIO_PIN_RESET);

}


void Motor_SetSpeed(uint8_t copy_u8Speed) {

	TIM2->CCR1 = copy_u8Speed;
	TIM2->CCR2 = copy_u8Speed;
}

void Motor_voidMoveForward(void) {
	HAL_GPIO_WritePin(RearMotor_INT1_GPIO_Port, RearMotor_INT1_Pin,
			GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RearMotor_INT2_GPIO_Port, RearMotor_INT2_Pin,
			GPIO_PIN_SET);

}

void Motor_voidMoveBackward(void) {
	HAL_GPIO_WritePin(RearMotor_INT1_GPIO_Port, RearMotor_INT1_Pin,
			GPIO_PIN_SET);
	HAL_GPIO_WritePin(RearMotor_INT2_GPIO_Port, RearMotor_INT2_Pin,
			GPIO_PIN_RESET);
}

void Motor_voidTurnRight(void) {

	//Turn right
	HAL_GPIO_WritePin(FrontMotor_INT1_GPIO_Port, FrontMotor_INT1_Pin,
			GPIO_PIN_RESET);
	HAL_GPIO_WritePin(FrontMotor_INT2_GPIO_Port, FrontMotor_INT2_Pin,
			GPIO_PIN_SET);

}

void Motor_voidTurnLeft(void) {

	//Turn left
	HAL_GPIO_WritePin(FrontMotor_INT1_GPIO_Port, FrontMotor_INT1_Pin,
			GPIO_PIN_SET);
	HAL_GPIO_WritePin(FrontMotor_INT2_GPIO_Port, FrontMotor_INT2_Pin,
			GPIO_PIN_RESET);
}
*/

// should be called first to initialize module speed
Motor_state_t Motor_frontSetPWR(uint8_t cpy_u8Speed) {
	Motor_state_t retState = Motor_Req_Fail;
	if (cpy_u8Speed <= 100) {
		TIM2->CCR1 = cpy_u8Speed;
		retState = Motor_Req_Pass;
	} else {
		retState = Motor_Req_Fail;
	}
	return retState;
}

//@pre-requiste call frontStart to start PWM module
Motor_state_t Motor_frontMoveRight() {

	HAL_GPIO_WritePin(FrontMotor_INT1_GPIO_Port, FrontMotor_INT1_Pin,
			GPIO_PIN_RESET);
	HAL_GPIO_WritePin(FrontMotor_INT2_GPIO_Port, FrontMotor_INT2_Pin,
			GPIO_PIN_SET);

	return Motor_Req_Pass;
}

//@pre-requiste call frontStart to start PWM module
Motor_state_t Motor_frontMoveLeft() {

	HAL_GPIO_WritePin(FrontMotor_INT1_GPIO_Port, FrontMotor_INT1_Pin,
			GPIO_PIN_SET);
	HAL_GPIO_WritePin(FrontMotor_INT2_GPIO_Port, FrontMotor_INT2_Pin,
			GPIO_PIN_RESET);

	return Motor_Req_Pass;
}

Motor_state_t Motor_frontStop() {

	HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_1);
	HAL_GPIO_WritePin(FrontMotor_INT1_GPIO_Port, FrontMotor_INT1_Pin,
			GPIO_PIN_RESET);
	HAL_GPIO_WritePin(FrontMotor_INT2_GPIO_Port, FrontMotor_INT2_Pin,
			GPIO_PIN_RESET);
	return Motor_Req_Pass;
}

//@pre-requiste call setPWR to set duty cycle
Motor_state_t Motor_frontStart() {
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	return Motor_Req_Pass;
}

// 0 to 100 percent values
Motor_state_t Motor_rearSetPWR(uint8_t cpy_u8Speed) {
	Motor_state_t retState = Motor_Req_Fail;
	if (cpy_u8Speed <= 100) {
		TIM2->CCR2 = cpy_u8Speed;
		retState = Motor_Req_Pass;
	} else {
		retState = Motor_Req_Fail;
	}
	return retState;
}

Motor_state_t Motor_rearMoveForward(uint8_t cpy_u8Speed) {
	Motor_state_t retState = Motor_Req_Fail;

	retState |= Motor_rearSetPWR(cpy_u8Speed);
	HAL_GPIO_WritePin(RearMotor_INT1_GPIO_Port, RearMotor_INT1_Pin,
			GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RearMotor_INT2_GPIO_Port, RearMotor_INT2_Pin,
			GPIO_PIN_SET);
	retState |= Motor_Req_Pass;
	return retState;
}
Motor_state_t Motor_rearMoveBackward(uint8_t cpy_u8Speed) {
	Motor_state_t retState = Motor_Req_Fail;

	retState |= Motor_rearSetPWR(cpy_u8Speed);
	HAL_GPIO_WritePin(RearMotor_INT1_GPIO_Port, RearMotor_INT1_Pin,
			GPIO_PIN_SET);
	HAL_GPIO_WritePin(RearMotor_INT2_GPIO_Port, RearMotor_INT2_Pin,
			GPIO_PIN_RESET);
	retState |= Motor_Req_Pass;
	return retState;
}
Motor_state_t Motor_rearStop() {

	HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_2);
	HAL_GPIO_WritePin(RearMotor_INT1_GPIO_Port, RearMotor_INT1_Pin,
			GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RearMotor_INT2_GPIO_Port, RearMotor_INT2_Pin,
			GPIO_PIN_RESET);

	return Motor_Req_Pass;
}

Motor_state_t Motor_rearStart(uint8_t cpy_u8Speed){
	Motor_state_t retState = Motor_Req_Fail;

	retState |= Motor_rearSetPWR(cpy_u8Speed);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);

	retState |= Motor_Req_Pass;

	return retState;
}
