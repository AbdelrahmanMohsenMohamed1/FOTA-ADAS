#include <stdint.h>
#include <stdbool.h>
#include "Ultrasonic.h"
#include "stm32f1xx_hal_tim.h"

extern TIM_HandleTypeDef htim2;

/*
bool AutoparkStart(void)
{
	uint32_t Timer_timeout_flag = 0;
	uint32_t Deadtime = 10; //sec
	uint32_t thresholdOfWidth_in_Cm =  30;  //width
	uint32_t thresholdOfLength_in_Cm = 35;  //Length
	bool PossibleSpot_acuainted;
	bool FoundSpot = false;
	uint32_t distance1 ;
	uint32_t Speed = 100 ; //max speed cm/s
	uint32_t count1, count2;
	//Scan For possible Space take  readings from ultrasonic
	// start tim
	while (!Timer_timeout_flag && !FoundSpot)
	{
		//car move
		Service_Car_MoveStraightForward(Speed);
		// read rigth ultrasonic
		distance1 = RightUltrasonic_voidGetDistance();
		PossibleSpot_acuainted = false;
		if (distance1 >= thresholdOfWidth_in_Cm)
		{
			// possible spot
			PossibleSpot_acuainted = true;
			count1 = __HAL_TIM_GET_COUNTER(&htim2);

		}
		while( distance1 >= thresholdOfWidth_in_Cm  && PossibleSpot_acuainted == true)
		{
			count2 = __HAL_TIM_GET_COUNTER(&htim2);

			distance1 = RightUltrasonic_voidGetDistance();
			if (((count2-count1)*ticktimeSec) == (thresholdOfLength_in_Cm/Speed) )
			{
				FoundSpot= true;
				//stop timer
				break;
			}
			if (((count2-count1)*ticktimeSec) >= Deadtime )
			{
				Timer_timeout_flag= 1;
				break;
			}
		}
	}

	if (FoundSpot)
	{        // Suitable Spot for parking detected

		// move vehicle forward for 0.5 seconds
		// reverse with angle 45 if possible
		// move backwards while having the same angle
		// stop
		// rotate within the same place

		return true;
	}
	else
	{        // Task Time-out or didn't find suitable spot

		return false;

	}

}

*/
