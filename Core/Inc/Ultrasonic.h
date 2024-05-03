/*
 * Ultrasonic.h
 *
 *  Created on: May 2, 2024
 *      Author: Abdelrahman
 */

#ifndef INC_ULTRASONIC_H_
#define INC_ULTRASONIC_H_

#include "main.h"

#define TRIG_PIN_1 GPIO_PIN_13
#define TRIG_PORT_1 GPIOB

#define TRIG_PIN_2 GPIO_PIN_12
#define TRIG_PORT_2 GPIOB

#define TRIG_PIN_3 GPIO_PIN_11
#define TRIG_PORT_3 GPIOB

#define TRIG_PIN_4 GPIO_PIN_10
#define TRIG_PORT_4 GPIOB

extern uint8_t UL_Distance1 ;
extern uint8_t UL_Distance2 ;
extern uint8_t UL_Distance3 ;
extern uint8_t UL_Distance4 ;

void delay (uint16_t time);
void HCSR04_Read1 (void);
void HCSR04_Read2 (void);
void HCSR04_Read3 (void);
void HCSR04_Read4 (void);

#endif /* INC_ULTRASONIC_H_ */
