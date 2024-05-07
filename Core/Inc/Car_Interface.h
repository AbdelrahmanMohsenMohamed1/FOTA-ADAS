/*
 * Car_Interface.h
 *
 *  Created on: May 1, 2024
 *      Author: Abdelrahman
 */

#ifndef INC_CAR_INTERFACE_H_
#define INC_CAR_INTERFACE_H_

#include "Motor.h"

void Service_Car_Stop(void);
void Service_Car_Start(void);
void Service_Car_MoveStraightForward(uint8_t copy_u8Speed);
void Service_Car_MoveStraightBackward(uint8_t copy_u8Speed);
void Service_Car_MoveSteeringRightForward(uint8_t copy_u8Speed);
void Service_Car_MoveSteeringLeftForward(uint8_t copy_u8Speed);
void Service_Car_MoveSteeringLeftBackward(uint8_t copy_u8Speed);
void Service_Car_MoveSteeringRigthBackward(uint8_t copy_u8Speed);

#endif /* INC_CAR_INTERFACE_H_ */
