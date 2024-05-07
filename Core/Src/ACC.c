/*
 * ACC.c
 *
 *  Created on: May 7, 2024
 *      Author: Om562
 */

#include "ACC.h"

ACC_ret_t ACC_Run(ACC_instance_t *px_ACCObj) {
	if (px_ACCObj->u8_isACC_Activaed == 0) { 	// first time to activate ACC
		px_ACCObj->u8_isACC_Activaed = 1;
	} else {
		// Nothing
	}

	// ACC activated once before
	if (px_ACCObj->pxDatamanger->FrontUltraReading > ACC_THRESHOLD_1_CM) { // increase speed
		if (cpy_u8Speed + Speed_Ratio_1 <= px_ACCObj->u8_Acc_max_Speed) {
			// Service_Car_SteerForward(cpy_u8Speed + Speed_Ratio_1);
		} else {
			// Service_Car_SteerForward(cpy_u8Speed + Speed_Ratio_1);
		}
	} else if ((uint8_t) (px_ACCObj->pxDatamanger->FrontUltraReading)
			<= ACC_THRESHOLD_1_CM
			&& (uint8_t) (px_ACCObj->pxDatamanger->FrontUltraReading)
					>= ACC_THRESHOLD_2_CM) {   // stay in the same speed
			// Service_Car_SteerForward(cpy_u8Speed );
	} else if ((uint8_t) (px_ACCObj->pxDatamanger->FrontUltraReading)
			< ACC_THRESHOLD_2_CM) { // decrease speed
		if ((int8_t) (cpy_u8Speed - Speed_Ratio_1) < 0) {
			// Service_Car_SteerForward(cpy_u8Speed  - Speed_Ratio_2);
		} else if ((int8_t) (cpy_u8Speed - Speed_Ratio_2) < 0) {
			// Service_Car_SteerForward(cpy_u8Speed  - 1);
		} else {
			// Service_Car_SteerForward(0);
		}
	}

}

ACC_ret_t ACC_Stop(ACC_instance_t *px_ACCObj) {

}
