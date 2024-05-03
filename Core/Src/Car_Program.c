/*
 * Car_Program.c
 *
 *  Created on: May 1, 2024
 *      Author: Abdelrahman
 */

#include "Car_Interface.h"

/**
 * @brief Stops the car's movement.
 *
 * This function stops both motors to halt the car's movement.
 *
 */
Srvc_Car_state_t Service_Car_Stop() {

	Srvc_Car_state_t retState = Car_Req_Fail;

	if ((Motor_Req_Pass == Motor_frontStop())
			&& (Motor_Req_Pass == Motor_rearStop())) {
		retState = Car_Req_Done;
	} else {
		retState = Car_Req_Fail;
	}
	return retState;
}

/**
 * @brief Starts the car.
 *
 * Initializes the motors to prepare the car for movement.
 *
 */
Srvc_Car_state_t Service_Car_Start(uint8_t copy_u8Speed) {
	/*
	 * Initialize Motors
	 */
	Srvc_Car_state_t retState = Car_Req_Fail;
	if ((Motor_Req_Pass == Motor_frontStop())
			&& (Motor_Req_Pass == Motor_rearStart(copy_u8Speed))) {
		retState = Car_Req_Done;
	} else {
		retState = Car_Req_Fail;
	}
	return retState;
}

/**
 * @brief Moves the car straight forward.
 *
 * Starts motor 1 in the clockwise direction and stops motor 2 for forward motion.
 *
 */
Srvc_Car_state_t Service_Car_MoveStraightForward(uint8_t cpy_u8Speed) {
	/*
	 * Motor 1 Start --> CW
	 * Motor 2 Stop
	 */
	Srvc_Car_state_t retState = Car_Req_Fail;
	if ((Motor_Req_Pass == Motor_frontStop())
			&& (Motor_Req_Pass == Motor_rearMoveForward(cpy_u8Speed))) {

		retState = Car_Req_Done;
	} else {
		retState = Car_Req_Fail;
	}
	return retState;
}

/**
 * @brief Moves the car straight backward.
 *
 * Starts motor 1 in the counter-clockwise direction and stops motor 2 for backward motion.
 *
 */
Srvc_Car_state_t Service_Car_MoveStraightBackward(uint8_t cpy_u8Speed) {
	/*
	 * Motor 1 Start --> CCW
	 * Motor 2 Stop
	 */
	Srvc_Car_state_t retState = Car_Req_Fail;
	if ((Motor_Req_Pass == Motor_frontStop())
			&& (Motor_Req_Pass == Motor_rearMoveBackward(cpy_u8Speed))) {

		retState = Car_Req_Done;
	} else {
		retState = Car_Req_Fail;
	}
	return retState;
}

/**
 * @brief Steers the car to the right.
 *
 * Starts motor 2 in the clockwise direction for right steering.
 *
 */
Srvc_Car_state_t Service_Car_MoveSteeringRight(uint8_t cpy_u8Speed) {
	/*
	 * Motor 2 Start --> CW
	 */
	Srvc_Car_state_t retState = Car_Req_Fail;
	if ((Motor_Req_Pass == Motor_frontMoveRight())
			&& (Motor_Req_Pass == Motor_rearMoveForward(cpy_u8Speed))) {

		retState = Car_Req_Done;
	} else {
		retState = Car_Req_Fail;
	}
	return retState;
}

/**
 * @brief Steers the car to the left.
 *
 * Starts motor 2 in the counter-clockwise direction for left steering.
 *
 */
Srvc_Car_state_t Service_Car_MoveSteeringLeft(uint8_t cpy_u8Speed) {
	/*
	 * Motor 2 Start --> CCW
	 */
	Srvc_Car_state_t retState = Car_Req_Fail;
	if ((Motor_Req_Pass == Motor_frontMoveLeft())
			&& (Motor_Req_Pass == Motor_rearMoveForward(cpy_u8Speed))) {

		retState = Car_Req_Done;
	} else {
		retState = Car_Req_Fail;
	}
	return retState;
}

/**
 * @brief Steers the car forward.
 *
 * Stops motor 2 for forward steering.
 *
 */
Srvc_Car_state_t Service_Car_SteerForward(uint8_t cpy_u8Speed) {
	/*
	 * Motor 2 Stop
	 */
	Srvc_Car_state_t retState = Car_Req_Fail;
	if ((Motor_Req_Pass == Motor_frontStop())
			&& (Motor_Req_Pass == Motor_rearMoveForward(cpy_u8Speed))) {

		retState = Car_Req_Done;
	} else {
		retState = Car_Req_Fail;
	}
	return retState;
}
