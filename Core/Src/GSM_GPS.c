/*
 * GSM_GPS.C
 *
 *  Created on: Apr 30, 2024
 *      Author: Amr
 */
#include "GSM_GPS.h"

extern UART_HandleTypeDef huart1;

static const uint8_t EndLine[] = { 0x0D, 0x0A};

static const uint8_t ATD[] = "ATD+201115792888"; //Number to call


void GSM_send_message(void)
{

	static uint8_t CMGF[] = "AT+CMGF=1";
	static uint8_t CSMP[] = "AT+CSMP=17,167,0,0";
	static uint8_t CMGS[] = "AT+CMGS=+201115792888"; //Number to send SMS
	static uint8_t MSG[] = "I had an accident";
	static const uint8_t ENDSMS = 0x1a;

	//SET GSM in text mode
	HAL_UART_Transmit(&huart1,CMGF , sizeof(CMGF) ,HAL_MAX_DELAY);
	HAL_UART_Transmit(&huart1, EndLine, sizeof(EndLine) ,HAL_MAX_DELAY);

	//SET GSM paramters  to default
	HAL_UART_Transmit(&huart1,CSMP ,sizeof(CSMP) ,HAL_MAX_DELAY);
	HAL_UART_Transmit(&huart1, EndLine, sizeof(EndLine) ,HAL_MAX_DELAY);

	//SET GSM number to call
	HAL_UART_Transmit(&huart1,CMGS ,sizeof(CMGS) ,HAL_MAX_DELAY);
	HAL_UART_Transmit(&huart1, EndLine, sizeof(EndLine) ,HAL_MAX_DELAY);

	//send message
	HAL_UART_Transmit(&huart1,MSG ,sizeof(MSG) ,HAL_MAX_DELAY);
	HAL_UART_Transmit(&huart1,&ENDSMS,1 ,HAL_MAX_DELAY);
}

void GSM_make_call(void)
{
	//send message
	HAL_UART_Transmit(&huart1,ATD ,sizeof(ATD) ,HAL_MAX_DELAY);
	HAL_UART_Transmit(&huart1, EndLine, sizeof(EndLine) ,HAL_MAX_DELAY);
}

void GPS_take_location(uint8_t  pData[])
{
	uint8_t GPSEN[] = "AT+GPS=1";
	//uint8_t GPSRD[] = "AT+GPSRD=1";
	uint8_t LOC[] = "AT+LOCATION=2";
	uint8_t GPSDIS[] = "AT+GPS=0";
	//GPS EN
	HAL_UART_Transmit(&huart1,GPSEN ,sizeof(GPSEN) ,HAL_MAX_DELAY);
	HAL_UART_Transmit(&huart1, EndLine, sizeof(EndLine) ,HAL_MAX_DELAY);

//	//ASK location ever 1 second for NEMA FORMAT
//	HAL_UART_Transmit(&huart1,GPSRD ,sizeof(GPSRD) ,HAL_MAX_DELAY);
//	HAL_UART_Transmit(&huart1, EndLine, sizeof(EndLine) ,HAL_MAX_DELAY);

	//ASK FOR LOCATION FOR  CORDINATE AS 23.014947,72.639612
	HAL_UART_Transmit(&huart1,LOC ,sizeof(LOC) ,HAL_MAX_DELAY);
	HAL_UART_Transmit(&huart1, EndLine, sizeof(EndLine) ,HAL_MAX_DELAY);

	//RECIEVE LOCATION
	HAL_UART_Receive(&huart1, pData, 19 , HAL_MAX_DELAY);

	//GPS DIS
    HAL_UART_Transmit(&huart1,GPSDIS ,sizeof(GPSDIS) ,HAL_MAX_DELAY);
    HAL_UART_Transmit(&huart1, EndLine, sizeof(EndLine) ,HAL_MAX_DELAY);

}
