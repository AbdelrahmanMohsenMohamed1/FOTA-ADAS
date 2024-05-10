/*
 * ACC.h
 *
 *  Created on: May 7, 2024
 *      Author: Om562
 */


#ifndef INC_ACC_H_
#define INC_ACC_H_

#include "Data_Manager.h"
#include "Car_Interface.h"

#define ACC_THRESHOLD_1_CM		150
#define ACC_THRESHOLD_2_CM		50
#define ACC_SPEED_RATIO_1		15
#define ACC_SPEED_RATIO_2 		2
#define ACC_INITIAL				1
#define ACC_ACTIVATED           2
#define ACC_DISABLED  			3
typedef struct{
	uint8_t u8_vehicle_Currentspeed;
	uint8_t u8_vehicle_Lastspeed;
	uint8_t u8_Acc_max_Speed;
	uint8_t u8_isACC_Activated;
	Data_Manager_t *pxDatamanger;

}ACC_instance_t;

typedef enum {

	ACC_REQuest_FAILED,
	ACC_REQuest_PASSED,
	ACC_REQuest_NoAction
}ACC_ret_t;

ACC_ret_t ACC_Run(ACC_instance_t * px_ACCObj);
ACC_ret_t ACC_Stop(ACC_instance_t * px_ACCObj);
ACC_ret_t ACC_Resume(ACC_instance_t * px_ACCObj);
#endif /* INC_ACC_H_ */
