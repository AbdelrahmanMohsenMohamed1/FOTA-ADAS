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
 * @param DataManager The data manager structure to update with collected data.
 */
void Service_DataCollectAll(Data_Manager_t *DataManager) {
	// Implementation goes here
	Service_DataCollectUltraReading(DataManager);
	Service_DataCollectIRReading(DataManager);
	Service_DataCollectDHTReading(DataManager);
	Service_DataCollectWaterReading(DataManager);

}

/**
 * @brief Collects ultrasonic sensor readings and updates the data manager.
 *
 * @param DataManager The data manager structure to update with ultrasonic readings.
 */
void Service_DataCollectUltraReading(Data_Manager_t *DataManager) {
	// Implementation goes here
	DataManager->FrontUltraReading = FrontUltrasonic_floatGetDistance();
	DataManager->RearUltraReading = RearUltrasonic_floatGetDistance();
	DataManager->LeftSideUltraReading = LeftUltrasonic_floatGetDistance();
	DataManager->RightSideUltraReading = RightUltrasonic_floatGetDistance();

}

/**
 * @brief Collects infrared sensor readings and updates the data manager.
 *
 * @param DataManager The data manager structure to update with infrared readings.
 */
void Service_DataCollectIRReading(Data_Manager_t *DataManager) {
	// Implementation goes here

	DataManager->FrontalLeftIR = IR1_u8ObstacleDetect();
	DataManager->FrontalRightIR = IR2_u8ObstacleDetect();
	DataManager->RearLeftIR = IR3_u8ObstacleDetect();
	DataManager->RearRightIR = IR4_u8ObstacleDetect();
	DataManager->MidFrontIR = IR5_u8ObstacleDetect();
}

/**
 * @brief Collects DHT sensor temperature reading and updates the data manager.
 *
 * @param DataManager The data manager structure to update with DHT temperature reading.
 */
void Service_DataCollectDHTReading(Data_Manager_t *DataManager) {
	// Implementation goes here
	DataManager->DHT_TempReading = DHT22_GetTemperature();
}

/**
 * @brief Collects water sensor reading and updates the data manager.
 *
 * @param DataManager The data manager structure to update with water sensor reading.
 */
void Service_DataCollectWaterReading(Data_Manager_t *DataManager) {
	// Implementation goes here
	DataManager->WaterSensorReading = Water_Sensor_u8WaterDetect();
}
