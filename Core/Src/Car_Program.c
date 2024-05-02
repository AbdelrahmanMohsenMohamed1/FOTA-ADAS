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
void Service_Car_Stop()
{
	/*
	 * Motor 1 Stop
	 * Motor 2 Stop
	 */
}

/**
 * @brief Starts the car.
 *
 * Initializes the motors to prepare the car for movement.
 *
 */
void Service_Car_Start()
{
	/*
	 * Initialize Motors
	 */
}

/**
 * @brief Moves the car straight forward.
 *
 * Starts motor 1 in the clockwise direction and stops motor 2 for forward motion.
 *
 */
void Service_Car_MoveStraightForward()
{
	/*
	 * Motor 1 Start --> CW
	 * Motor 2 Stop
	 */
}

/**
 * @brief Moves the car straight backward.
 *
 * Starts motor 1 in the counter-clockwise direction and stops motor 2 for backward motion.
 *
 */
void Service_Car_MoveStraightBackward()
{
	/*
	 * Motor 1 Start --> CCW
	 * Motor 2 Stop
	 */
}

/**
 * @brief Steers the car to the right.
 *
 * Starts motor 2 in the clockwise direction for right steering.
 *
 */
void Service_Car_MoveSteeringRight()
{
	/*
	 * Motor 2 Start --> CW
	 */
}

/**
 * @brief Steers the car to the left.
 *
 * Starts motor 2 in the counter-clockwise direction for left steering.
 *
 */
void Service_Car_MoveSteeringLeft()
{
	/*
	 * Motor 2 Start --> CCW
	 */
}

/**
 * @brief Steers the car forward.
 *
 * Stops motor 2 for forward steering.
 *
 */
void Service_Car_SteerForward()
{
	/*
	 * Motor 2 Stop
	 */
}
