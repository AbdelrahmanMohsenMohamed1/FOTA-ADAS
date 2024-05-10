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
	DataManager->FrontUltraReading = FrontUltrasonic_voidGetDistance();
	DataManager->RearUltraReading = RearUltrasonic_voidGetDistance();
	DataManager->LeftSideUltraReading = LeftUltrasonic_voidGetDistance();
	DataManager->RightSideUltraReading = RightUltrasonic_voidGetDistance();

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
	DataManager->IR_LF_Left = IR_LF_Left_u8ObstacleDetect();
	DataManager->IR_LF_Mid = IR_LF_Mid_u8ObstacleDetect();
	DataManager->IR_LF_Right = IR_LF_Right_u8ObstacleDetect();
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

void Service_ConvertData(Data_Manager_t *pxDMObj, uint8_t *puRetString) {


	memset(puRetString, FRAME_DELIMITER, MAX_DATA_LENGTH - 1);

	puRetString[MAX_DATA_LENGTH - 1] = '\0';

	sprintf((char*)puRetString,
			"%04d,%04d,%04d,%04d,%01d,%01d,%01d,%01d,%04d,%04d,%04d,%04d,%04d,%04d,%s,%s",
			pxDMObj->FrontUltraReading
			,pxDMObj->RearUltraReading
			,pxDMObj->RightSideUltraReading
			,pxDMObj->LeftSideUltraReading
			,pxDMObj->FrontalLeftIR
			,pxDMObj->FrontalRightIR
			,pxDMObj->RearLeftIR
			,pxDMObj->RearRightIR
			,pxDMObj->IR_LF_Left
			,pxDMObj->IR_LF_Mid
			,pxDMObj->IR_LF_Right
			,pxDMObj->WaterSensorReading
			,pxDMObj->DHT_Humidity
			,pxDMObj->DHT_TempReading
			,pxDMObj->Lattitude
			,pxDMObj->Longitude
			);

}

