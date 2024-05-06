/*
 * Car_Program.c
 *
 *  Created on: May 1, 2024
 *      Author: Abdelrahman
 */

#include "Car_Interface.h"
static uint8_t ACC_Max_CAR_SPEED = 0;
static uint8_t AccpreviousEn = 0;
static uint8_t threshold_1 = 150;
static uint8_t threshold_2 = 50;
static uint8_t Speed_Ratio_1 = 15;
static uint8_t Speed_Ratio_2 = 5;
// 200CM ---------- 150CM threshold 1 --------------  50CM theshold 2 ------ 0cm //

/**
 * @brief Stops the car's movement.
 *
 * This function stops both motors to halt the car's movement.
 *
 */
void Service_Car_Stop() {
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
void Service_Car_Start() {
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
void Service_Car_MoveStraightForward() {
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
void Service_Car_MoveStraightBackward() {
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
void Service_Car_MoveSteeringRight() {
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
void Service_Car_MoveSteeringLeft() {
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
void Service_Car_SteerForward() {
	/*
	 * Motor 2 Stop
	 */
}

/*
 * @brief : Starts Adaptive Cruise Control  saving current vehicle speed to be the max speed  reached if decreaed
 * @param : cpy_u8Speed   Current vehicle speed
 * @param : *px_DataManager instance of DataManager
 * @returns : void
 * */
void Service_Car_ACC_Enable(Data_Manager_t *px_DataManager, uint8_t cpy_u8Speed) {
	if (AccpreviousEn == 0) { 				// first time to activate ACC
		ACC_Max_CAR_SPEED = cpy_u8Speed;
	} else { 								// ACC activated once before
		if (px_DataManager->FrontUltraReading > threshold_1)
		{   // increase speed
			if(cpy_u8Speed + Speed_Ratio_1 <= ACC_Max_CAR_SPEED ){
				// Service_Car_SteerForward(cpy_u8Speed + Speed_Ratio_1);
			}else{
				// Service_Car_SteerForward(cpy_u8Speed + Speed_Ratio_1);
			}
		}
		else if ((uint8_t) (px_DataManager->FrontUltraReading) <= threshold_1
				&& (uint8_t) (px_DataManager->FrontUltraReading) >= threshold_2)
		{	// stay in the same speed
			// Service_Car_SteerForward(cpy_u8Speed );
		}
		else if ((uint8_t) (px_DataManager->FrontUltraReading) < threshold_2)
		{   // decrease speed
			if((int8_t)(cpy_u8Speed - Speed_Ratio_1)<0 ){
				// Service_Car_SteerForward(cpy_u8Speed  - Speed_Ratio_2);
			}else if((int8_t)(cpy_u8Speed - Speed_Ratio_2)<0 ){
				// Service_Car_SteerForward(cpy_u8Speed  - 1);
			}else{
				// Service_Car_SteerForward(0);
			}
		}
	}
}

/* @breif :disables Adaptive Cruise control
 * @reutrns : void
 */
void Service_Car_ACC_Disable(void) {

}
