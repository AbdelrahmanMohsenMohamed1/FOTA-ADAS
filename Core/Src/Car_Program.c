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

// INT4  PA7
// INT3 PA6
// INT2 PA5
//INT1 PA4
//ENB PA0
//ENA PA1

void Service_Car_Stop(void)
{
	/*
	 * Motor 1 Stop
	 * Motor 2 Stop
	 */
	Motor_SetSpeedRear(0);
	Motor_SetSpeedFront(0);

}

/**
 * @brief Starts the car.
 *
 * Initializes the motors to prepare the car for movement.
 *
 */
void Service_Car_Start(void)
{
	/*
	 * Initialize Motors
	 */
	Motor_Start();
}

/**
 * @brief Moves the car straight forward.
 *
 * Starts motor 1 in the clockwise direction and stops motor 2 for forward motion.
 *
 */
void Service_Car_MoveStraightForward(uint8_t copy_u8Speed)
{
	/*
	 * Motor 1 Start --> CW
	 * Motor 2 Stop
	 */
	Motor_SetSpeedFront(0);
	Motor_SetSpeedRear(copy_u8Speed);
	Motor_voidMoveForward();
}

/**
 * @brief Moves the car straight backward.
 *
 * Starts motor 1 in the counter-clockwise direction and stops motor 2 for backward motion.
 *
 */
void Service_Car_MoveStraightBackward(uint8_t copy_u8Speed)
{
	/*
	 * Motor 1 Start --> CCW
	 * Motor 2 Stop
	 */
	Motor_SetSpeedFront(0);
	Motor_SetSpeedRear(copy_u8Speed);
	Motor_voidMoveBackward();
}

/**
 * @brief Steers the car to the right.
 *
 * Starts motor 2 in the clockwise direction for right steering.
 *
 */
void Service_Car_MoveSteeringRightForward(uint8_t copy_u8Speed)
{
	/*
	 * Motor 2 Start --> CW
	 */
	Motor_SetSpeedFront(90);
	Motor_voidTurnRight();
	Motor_SetSpeedRear(copy_u8Speed);
	Motor_voidMoveForward();
}

void Service_Car_MoveSteeringLeftForward(uint8_t copy_u8Speed)
{
	/*
	 * Motor 2 Start --> CW
	 */
	Motor_SetSpeedFront(90);
	Motor_voidTurnLeft();
	Motor_SetSpeedRear(copy_u8Speed);
	Motor_voidMoveForward();
}

/**
 * @brief Steers the car to the left.
 *
 * Starts motor 2 in the counter-clockwise direction for left steering.
 *
 */
void Service_Car_MoveSteeringLeftBackward(uint8_t copy_u8Speed)
{
	/*
	 * Motor 2 Start --> CCW
	 */
	Motor_SetSpeedFront(90);
	Motor_voidTurnLeft();
	Motor_SetSpeedRear(copy_u8Speed);
	Motor_voidMoveBackward();

}

void Service_Car_MoveSteeringRigthBackward(uint8_t copy_u8Speed)
{
	/*
	 * Motor 2 Start --> CCW
	 */
	Motor_SetSpeedFront(90);
	Motor_voidTurnRight();
	Motor_SetSpeedRear(copy_u8Speed);
	Motor_voidMoveBackward();

}
