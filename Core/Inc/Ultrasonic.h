/*
 * Ultrasonic.h
 *
 *  Created on: Apr 29, 2024
 *      Author: Amira
 */

#ifndef INC_ULTRASONIC_H_
#define INC_ULTRASONIC_H_

#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_tim.h"

void delay(uint16_t us);
void ultrasonic_voidInit(void);
float ultrasonic1_voidGetDistance(void);
float ultrasonic2_voidGetDistance(void);
float ultrasonic3_voidGetDistance(void);
float ultrasonic4_voidGetDistance(void);


#endif /* INC_ULTRASONIC_H_ */
