/*
 * GSM_GPS.h
 *
 *  Created on: Apr 30, 2024
 *      Author: Amr
 */

#ifndef INC_GSM_GPS_H_
#define INC_GSM_GPS_H_

#include "stm32f1xx_hal.h"
#include "stdint.h"


void GSM_send_message(void);
void GSM_make_call(void);
void GSM_CHECK(void);
void GPS_take_location(uint8_t  pData[]);



#endif /* INC_GSM_GPS_H_ */
