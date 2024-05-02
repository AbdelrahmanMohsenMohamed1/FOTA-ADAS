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

void Motor_Start();
void Motor_voidStop(void);
void Motor_SetSpeed(uint8_t copy_u8Speed);
void Motor_voidMoveForward(void);
void Motor_voidMoveBackward(void);
void Motor_voidTurnRight(void);
void Motor_voidTurnLeft(void);

/*
 * if i want to set freg.
 * desired freq = Ftc \ ( pre + 1)*(peiod + 1 )
 */

/*
 * duty = CCR / period + 1
 */

#endif /* INC_MOTOR_H_ */
