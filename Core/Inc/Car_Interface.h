/*
 * Car_Interface.h
 *
 *  Created on: May 1, 2024
 *      Author: Abdelrahman
 */

#ifndef INC_CAR_INTERFACE_H_
#define INC_CAR_INTERFACE_H_

#include "main.h"
#include "Motor.h"
typedef enum {
	Car_Req_Done,
	Car_Req_Fail,
} Srvc_Car_state_t;
/**
 * @brief Stops the car's movement.
 *
 * This function is responsible for stopping the car's movement.
 *
 */
Srvc_Car_state_t Service_Car_Stop();

/**
 * @brief Starts the car.
 *
 * Initiates the starting sequence for the car.
 *
 */
Srvc_Car_state_t Service_Car_Start(uint8_t cpy_u8Speed);

/**
 * @brief Moves the car straight forward.
 *
 * Moves the car forward in a straight line.
 *
 */
Srvc_Car_state_t Service_Car_MoveStraightForward(uint8_t cpy_u8Speed);

/**
 * @brief Moves the car straight backward.
 *
 * Moves the car backward in a straight line.
 *
 */
Srvc_Car_state_t Service_Car_MoveStraightBackward(uint8_t cpy_u8Speed);

/**
 * @brief Steers the car to the right.
 *
 * Makes the car steer to the right.
 *
 */
Srvc_Car_state_t Service_Car_MoveSteeringRight(uint8_t cpy_u8Speed);

/**
 * @brief Steers the car to the left.
 *
 * Makes the car steer to the left.
 *
 */
Srvc_Car_state_t Service_Car_MoveSteeringLeft(uint8_t cpy_u8Speed);

/**
 * @brief Steers the car forward.
 *
 * Steers the car's wheels forward.
 *
 */
Srvc_Car_state_t Service_Car_SteerForward(uint8_t cpy_u8Speed);

#endif /* INC_CAR_INTERFACE_H_ */
