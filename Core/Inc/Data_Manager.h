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
#include "GSM_GPS.h"

typedef struct {
	// Ultrasonic sensor readings
	uint8_t FrontUltraReading;       // Reading from the front ultrasonic sensor
	uint8_t RearUltraReading;        // Reading from the rear ultrasonic sensor
	uint8_t RightSideUltraReading; // Reading from the right side ultrasonic sensor
	uint8_t LeftSideUltraReading; // Reading from the left side ultrasonic sensor

	// Infrared sensor readings
	uint8_t FrontIR;                 // Reading from the front infrared sensor
	uint8_t RearIR;                  // Reading from the rear infrared sensor
	uint8_t RightIR;                 // Reading from the right infrared sensor
	uint8_t LeftIR;                  // Reading from the left infrared sensor

	// Water sensor reading
	uint8_t WaterSensorReading;      // Reading from the water sensor

	// DHT sensor temperature reading
	uint8_t DHT_TempReading;        // Reading from the DHT temperature sensor
	uint8_t DHT_HumidityReading;
	// Array of the location
	uint8_t u8Location[50];

} Data_Manager_t;

typedef enum {
	DataCollection_Pass = 0,
	DataCollection_Fail,
	NullPointerObj
} Srvc_Data_state_t;

/**
 * @brief Collects all types of data and updates the data manager.
 *
 * @param DataManager The data manager structure to update with collected data.
 */
Srvc_Data_state_t Service_DataCollectAll(Data_Manager_t *px_DataManager);

/**
 * @brief Collects ultrasonic sensor readings and updates the data manager.
 *
 * @param DataManager The data manager structure to update with ultrasonic readings.
 */
Srvc_Data_state_t Service_DataCollectUltraReading(Data_Manager_t *px_DataManager);

/**
 * @brief Collects infrared sensor readings and updates the data manager.
 *
 * @param DataManager The data manager structure to update with infrared readings.
 */
Srvc_Data_state_t Service_DataCollectIRReading(Data_Manager_t *px_DataManager);

/**
 * @brief Collects DHT sensor temperature reading and updates the data manager.
 *
 * @param DataManager The data manager structure to update with DHT temperature reading.
 */
Srvc_Data_state_t Service_DataCollectDHTReading(Data_Manager_t *px_DataManager);

/**
 * @brief Collects water sensor reading and updates the data manager.
 *
 * @param DataManager The data manager structure to update with water sensor reading.
 */
Srvc_Data_state_t Service_DataCollectWaterReading(Data_Manager_t *px_DataManager);

/**
 * @brief Collects Location reading and updates the data manager.
 *
 * @param DataManager The data manager structure to update with Location reading.
 */
Srvc_Data_state_t Service_DataCollectLocationReading(Data_Manager_t *px_DataManager);

#endif /* INC_DATA_MANAGER_H_ */
