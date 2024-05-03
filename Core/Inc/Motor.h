/*
 * Motor.h
 *
 *  Created on: May 1, 2024
 *      Author: Amr
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_


#include "main.h"
#include <stdint.h>

extern TIM_HandleTypeDef htim2;

typedef enum{
	Motor_Req_Pass,
	Motor_Req_Fail
}Motor_state_t;
/**
 * frontal motor setpwr(init)  left right stop
 * rear motor    setpwr(init) start left right stop set speed
 * */
/*

void Motor_Start();
void Motor_voidStop(void);
void Motor_SetSpeed(uint8_t copy_u8Speed);
void Motor_voidMoveForward(void);
void Motor_voidMoveBackward(void);
void Motor_voidTurnRight(void);
void Motor_voidTurnLeft(void);
 * */

Motor_state_t Motor_frontSetPWR(uint8_t cpy_u8Speed);
Motor_state_t Motor_frontMoveRight();
Motor_state_t Motor_frontMoveLeft();
Motor_state_t Motor_frontStop();
Motor_state_t Motor_frontStart();


Motor_state_t Motor_rearSetPWR(uint8_t cpy_u8Speed);
Motor_state_t Motor_rearMoveForward(uint8_t cpy_u8Speed);
Motor_state_t Motor_rearMoveBackward(uint8_t cpy_u8Speed);
Motor_state_t Motor_rearStop();
Motor_state_t Motor_rearStart(uint8_t cpy_u8Speed);


/*
 * if i want to set freg.
 * desired freq = Ftc \ ( pre + 1)*(peiod + 1 )
 *
 * duty = CCR / period + 1
 */

#endif /* INC_MOTOR_H_ */
