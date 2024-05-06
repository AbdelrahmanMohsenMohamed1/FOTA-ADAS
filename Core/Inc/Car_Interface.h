/*
 * Car_Interface.h
 *
 *  Created on: May 1, 2024
 *      Author: Abdelrahman
 */

#ifndef INC_CAR_INTERFACE_H_
#define INC_CAR_INTERFACE_H_

#include "main.h"
#include "Data_Manager.h"

/**
 * @brief Stops the car's movement.
 *
 * This function is responsible for stopping the car's movement.
 *
 */
void Service_Car_Stop();

/**
 * @brief Starts the car.
 *
 * Initiates the starting sequence for the car.
 *
 */
void Service_Car_Start();

/**
 * @brief Moves the car straight forward.
 *
 * Moves the car forward in a straight line.
 *
 */
void Service_Car_MoveStraightForward();

/**
 * @brief Moves the car straight backward.
 *
 * Moves the car backward in a straight line.
 *
 */
void Service_Car_MoveStraightBackward();

/**
 * @brief Steers the car to the right.
 *
 * Makes the car steer to the right.
 *
 */
void Service_Car_MoveSteeringRight();

/**
 * @brief Steers the car to the left.
 *
 * Makes the car steer to the left.
 *
 */
void Service_Car_MoveSteeringLeft();

/**
 * @brief Steers the car forward.
 *
 * Steers the car's wheels forward.
 *
 */
void Service_Car_SteerForward();

/*
 * @brief : Starts Adaptive Cruise Control  saving current vehicle speed to be the max speed  reached if decreaed
 * @param : cpy_u8Speed   Current vehicle speed
 * @param : *px_DataManager instance of DataManager
 * @returns : void
 * */
void Service_Car_ACC_Enable(Data_Manager_t *px_DataManager,uint8_t cpy_u8Speed);

/* @breif :disables Adaptive Cruise control
 * @reutrns : void
 */
void Service_Car_ACC_Disable(void);


#endif /* INC_CAR_INTERFACE_H_ */
