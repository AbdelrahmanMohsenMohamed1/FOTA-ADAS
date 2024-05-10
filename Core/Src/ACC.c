/*
 * ACC.c
 *
 *  Created on: May 7, 2024
 *      Author: Om562
 */

#include "ACC.h"

ACC_ret_t ACC_Run(ACC_instance_t *px_ACCObj) {
	ACC_ret_t retState = ACC_REQuest_FAILED;
	if (px_ACCObj->u8_isACC_Activated == ACC_INITIAL) { // first time to activate ACC
		px_ACCObj->u8_isACC_Activated = ACC_ACTIVATED;
		retState = ACC_REQuest_PASSED;
	} else {
		// Nothing
	}
	if (px_ACCObj->u8_isACC_Activated != ACC_DISABLED) {

		// ACC activated once before
		if (px_ACCObj->pxDatamanger->FrontUltraReading > ACC_THRESHOLD_1_CM) {
			// increase speed
			if (px_ACCObj->u8_vehicle_Currentspeed + ACC_SPEED_RATIO_1
					<= px_ACCObj->u8_Acc_max_Speed) {

				px_ACCObj->u8_vehicle_Lastspeed =
						px_ACCObj->u8_vehicle_Currentspeed;

				px_ACCObj->u8_vehicle_Currentspeed =
						px_ACCObj->u8_vehicle_Currentspeed + ACC_SPEED_RATIO_1;

				Service_Car_MoveStraightForward(
						px_ACCObj->u8_vehicle_Currentspeed);
				retState = ACC_REQuest_PASSED;

			} else {
				// vehicle reaches max speed
				px_ACCObj->u8_vehicle_Lastspeed =
						px_ACCObj->u8_vehicle_Currentspeed;

				px_ACCObj->u8_vehicle_Currentspeed = (
						px_ACCObj->u8_vehicle_Currentspeed + ACC_SPEED_RATIO_2
								<= px_ACCObj->u8_Acc_max_Speed ?
								px_ACCObj->u8_vehicle_Currentspeed
										+ ACC_SPEED_RATIO_2 :
								px_ACCObj->u8_vehicle_Currentspeed);
				Service_Car_MoveStraightForward(
						px_ACCObj->u8_vehicle_Currentspeed);
				retState = ACC_REQuest_NoAction;
			}

		} else if ((uint8_t) (px_ACCObj->pxDatamanger->FrontUltraReading)
				<= ACC_THRESHOLD_1_CM
				&& (uint8_t) (px_ACCObj->pxDatamanger->FrontUltraReading)
						>= ACC_THRESHOLD_2_CM) {
			// stay in the same speed
			px_ACCObj->u8_vehicle_Lastspeed =
					px_ACCObj->u8_vehicle_Currentspeed;
			Service_Car_MoveStraightForward(px_ACCObj->u8_vehicle_Currentspeed);
			retState = ACC_REQuest_PASSED;

		} else if ((uint8_t) (px_ACCObj->pxDatamanger->FrontUltraReading)
				< ACC_THRESHOLD_2_CM) {
			// decrease speed
			if ((int8_t) (px_ACCObj->u8_vehicle_Currentspeed - ACC_SPEED_RATIO_1)
					< 0) {
				// stay in current speed
				px_ACCObj->u8_vehicle_Lastspeed =
						px_ACCObj->u8_vehicle_Currentspeed;
				Service_Car_MoveStraightForward(
						px_ACCObj->u8_vehicle_Currentspeed);
			} else if ((int8_t) (px_ACCObj->u8_vehicle_Currentspeed
					- ACC_SPEED_RATIO_2) >= 0) {

				Service_Car_MoveStraightForward(0);
				retState = ACC_REQuest_FAILED;
			}
		}
		else {
			// ACC is disabled
			retState = ACC_REQuest_FAILED;
		}
	}
	return retState;
}

ACC_ret_t ACC_Stop(ACC_instance_t *px_ACCObj) {
	px_ACCObj->u8_isACC_Activated = ACC_DISABLED;
	return ACC_REQuest_PASSED;
}

ACC_ret_t ACC_Resume(ACC_instance_t *px_ACCObj) {
	px_ACCObj->u8_isACC_Activated = ACC_INITIAL;
	return ACC_REQuest_PASSED;
}
