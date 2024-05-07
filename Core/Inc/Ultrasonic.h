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

void delay (uint16_t us);

void ultrasonic_voidInit(void);

float FrontUltrasonic_floatGetDistance(void);

float RearUltrasonic_floatGetDistance(void);

float RightUltrasonic_floatGetDistance(void);

float LeftUltrasonic_floatGetDistance(void);


#endif /* INC_ULTRASONIC_H_ */
