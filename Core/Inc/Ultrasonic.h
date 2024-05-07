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

#define   INDEX_0               0
#define   INDEX_1               1
#define   INDEX_2               2
#define   INDEX_3               3

#define   NO_ACK                0
#define   ACK                   1

#define   ZERO                  0
#define   DELAY_1MILLI          1

#define   RUN_TIME_OUT          5
#define   VELOCITY               (float)0.034
#define   DIVIDE_BY_TWO             2
#define   FLAG_CHECK                2


void delay(uint16_t us);
void ultrasonic_voidInit(void);
float FrontUltrasonic_voidGetDistance(void);
float RearUltrasonic_voidGetDistance(void);
float RightUltrasonic_voidGetDistance(void);
float LeftUltrasonic_voidGetDistance(void);

#endif /* INC_ULTRASONIC_H_ */
