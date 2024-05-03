/*
 * Data_Manager.c
 *
 *  Created on: May 1, 2024
 *      Author: Abdelrahman
 */
#include "Data_Manager.h"

/**
 * @brief Collects all types of data and updates the data manager.
 *
 * @param DataManager pointer To data manager structure to update with collected data.
 */
Srvc_Data_state_t Service_DataCollectAll(Data_Manager_t *px_DataManager) {

	Srvc_Data_state_t retState = DataCollection_Fail;

	if (NULL == px_DataManager) {
		retState = NullPointerObj;
	} else {

		// Ultrasonic Readings
		retState |= Service_DataCollectUltraReading(px_DataManager);
		// IR Readings
		retState |= Service_DataCollectIRReading(px_DataManager);
		// Water sensor reading
		retState |= Service_DataCollectWaterReading(px_DataManager);
		// DHT sensor temperature reading
		retState |= Service_DataCollectDHTReading(px_DataManager);
		// GPS Location
		retState |= Service_DataCollectLocationReading(px_DataManager);

	}
	return retState;
}

/**
 * @brief Collects ultrasonic sensor readings and updates the data manager.
 *
 * @param DataManager pointer To data manager structure to update with ultrasonic readings.
 */
Srvc_Data_state_t Service_DataCollectUltraReading(Data_Manager_t *px_DataManager) {
	// Implementation goes here
	Srvc_Data_state_t retState = DataCollection_Fail;
	if (NULL == px_DataManager) {
		retState = NullPointerObj;
	} else {
		px_DataManager->FrontUltraReading = UL_Distance1;
		px_DataManager->RearUltraReading = UL_Distance2;
		px_DataManager->RightSideUltraReading = UL_Distance3;
		px_DataManager->LeftSideUltraReading = UL_Distance4;
		retState = DataCollection_Pass;
	}
	return retState;
}

/**
 * @brief Collects infrared sensor readings and updates the data manager.
 *
 * @param DataManager pointer To data manager structure to update with infrared readings.
 */
Srvc_Data_state_t Service_DataCollectIRReading(Data_Manager_t *px_DataManager) {
	// Implementation goes here
	Srvc_Data_state_t retState = DataCollection_Fail;

	if (NULL == px_DataManager) {
		retState = NullPointerObj;
	} else {
		px_DataManager->FrontIR = IR1_u8ObstacleDetect();
		px_DataManager->RearIR = IR2_u8ObstacleDetect();
		px_DataManager->LeftIR = IR3_u8ObstacleDetect();
		px_DataManager->RightIR = IR4_u8ObstacleDetect();
		retState = DataCollection_Pass;
	}
	return retState;
}
//TODO: UPDATE Function for Humidity
/**
 * @brief Collects DHT sensor temperature reading and updates the data manager.
 *
 * @param DataManager pointer To data manager structure to update with DHT temperature reading.
 */
Srvc_Data_state_t Service_DataCollectDHTReading(Data_Manager_t *px_DataManager) {
	// Implementation goes here
	Srvc_Data_state_t retState = DataCollection_Fail;
	if (NULL == px_DataManager) {
		retState = NullPointerObj;
	} else {
		px_DataManager->DHT_TempReading = DHT22_GetTemperature();
		px_DataManager->DHT_HumidityReading = 55; //TODO: Function for Humidity
		retState = DataCollection_Pass;
	}
	return retState;
}

/**
 * @brief Collects water sensor reading and updates the data manager.
 *
 * @param DataManager pointer To data manager structure to update with water sensor reading.
 */
Srvc_Data_state_t Service_DataCollectWaterReading(Data_Manager_t *px_DataManager) {
	// Implementation goes here
	Srvc_Data_state_t retState = DataCollection_Fail;
	if (NULL == px_DataManager) {
		retState = NullPointerObj;
	} else {
		px_DataManager->WaterSensorReading = Water_Sensor_u8WaterDetect();
		retState = DataCollection_Pass;
	}
	return retState;
}

/**
 * @brief Collects Location reading and updates the data manager.
 *
 * @param DataManager pointer To data manager structure to update with Location reading.
 */
Srvc_Data_state_t Service_DataCollectLocationReading(
		Data_Manager_t *px_DataManager) {
	// Implementation goes here
	Srvc_Data_state_t retState = DataCollection_Fail;
	if (NULL == px_DataManager) {
		retState = NullPointerObj;

	} else {
		GPS_take_location(px_DataManager->u8Location);
		retState = DataCollection_Pass;
	}
	return retState;
}
