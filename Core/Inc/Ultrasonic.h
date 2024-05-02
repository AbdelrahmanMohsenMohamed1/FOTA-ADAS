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

void Udelay_us (uint16_t us);
void ultrasonic_voidInit();
uint8_t UltraSonic1_Read (void);
uint8_t UltraSonic2_Read (void);
uint8_t UltraSonic3_Read (void);
uint8_t UltraSonic4_Read (void);


#endif /* INC_ULTRASONIC_H_ */
