/*
 * Data_Manager.h
 *
 *  Created on: May 1, 2024
 *      Author: Abdelrahman
 */

#ifndef INC_DATA_MANAGER_H_
#define INC_DATA_MANAGER_H_


#include "main.h"
#include "WaterSensor.h"
#include "IR.h"
#include "dht22.h"
#include "Ultrasonic.h"

#include <string.h>
#include <stdio.h>

#define MAX_DATA_LENGTH 64
#define FRAME_DELIMITER '*'
#define DATA_CONVERSION_BASE 10
#define DATA_4DIGITS_SIZE 4
#define DATA_LOCAL_BUFFER_SIZE  10

typedef struct
{
	// Ultrasonic sensor readings
	uint8_t FrontUltraReading;       // Reading from the front ultrasonic sensor
	uint8_t RearUltraReading;        // Reading from the rear ultrasonic sensor
	uint8_t RightSideUltraReading;   // Reading from the right side ultrasonic sensor
	uint8_t LeftSideUltraReading;    // Reading from the left side ultrasonic sensor

	// Infrared sensor readings
	uint8_t FrontalRightIR;                 // Reading from the front infrared sensor
	uint8_t RearRightIR;                  // Reading from the rear infrared sensor

	uint8_t FrontalLeftIR;                 // Reading from the right infrared sensor
	uint8_t RearLeftIR;                  // Reading from the left infrared sensor

	uint8_t IR_LF_Left;
	uint8_t IR_LF_Mid;
	uint8_t IR_LF_Right;

	// 3 line follower

	// Water sensor reading
	uint8_t WaterSensorReading;      // Reading from the water sensor

	// DHT sensor temperature reading
	uint8_t DHT_TempReading;        // Reading from the DHT temperature sensor
	uint8_t DHT_Humidity;

	// Location
	uint8_t Lattitude[10];
	uint8_t Longitude[10];

} Data_Manager_t;

/**
 * @brief Collects all types of data and updates the data manager.
 *
 * @param DataManager The data manager structure to update with collected data.
 */
void Service_DataCollectAll(Data_Manager_t* DataManager);

/**
 * @brief Collects ultrasonic sensor readings and updates the data manager.
 *
 * @param DataManager The data manager structure to update with ultrasonic readings.
 */
void Service_DataCollectUltraReading(Data_Manager_t* DataManager);

/**
 * @brief Collects infrared sensor readings and updates the data manager.
 *
 * @param DataManager The data manager structure to update with infrared readings.
 */
void Service_DataCollectIRReading(Data_Manager_t* DataManager);

/**
 * @brief Collects DHT sensor temperature reading and updates the data manager.
 *
 * @param DataManager The data manager structure to update with DHT temperature reading.
 */
void Service_DataCollectDHTReading(Data_Manager_t* DataManager);

/**
 * @brief Collects water sensor reading and updates the data manager.
 *
 * @param DataManager The data manager structure to update with water sensor reading.
 */
void Service_DataCollectWaterReading(Data_Manager_t* DataManager);

void Service_ConvertData(Data_Manager_t *pxDMObj , uint8_t *puRetString);

#endif /* INC_DATA_MANAGER_H_ */
