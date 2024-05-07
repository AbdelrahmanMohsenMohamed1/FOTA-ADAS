/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define mot1_in1_Pin GPIO_PIN_4
#define mot1_in1_GPIO_Port GPIOA
#define mot1_in2_Pin GPIO_PIN_5
#define mot1_in2_GPIO_Port GPIOA
#define mot2_in1_Pin GPIO_PIN_6
#define mot2_in1_GPIO_Port GPIOA
#define mot2_in2_Pin GPIO_PIN_7
#define mot2_in2_GPIO_Port GPIOA
#define IR_leftfront_Pin GPIO_PIN_0
#define IR_leftfront_GPIO_Port GPIOB
#define IR_midfront_Pin GPIO_PIN_1
#define IR_midfront_GPIO_Port GPIOB
#define IR_rightfront_Pin GPIO_PIN_2
#define IR_rightfront_GPIO_Port GPIOB
#define Ultra_Trig4_Pin GPIO_PIN_10
#define Ultra_Trig4_GPIO_Port GPIOB
#define Ultra_Trig3_Pin GPIO_PIN_11
#define Ultra_Trig3_GPIO_Port GPIOB
#define Ultra_Trig2_Pin GPIO_PIN_12
#define Ultra_Trig2_GPIO_Port GPIOB
#define Ultra_Trig1_Pin GPIO_PIN_13
#define Ultra_Trig1_GPIO_Port GPIOB
#define IR1_Pin GPIO_PIN_14
#define IR1_GPIO_Port GPIOB
#define DHT_Pin GPIO_PIN_15
#define DHT_GPIO_Port GPIOB
#define IR2_Pin GPIO_PIN_15
#define IR2_GPIO_Port GPIOA
#define water_sensor_Pin GPIO_PIN_5
#define water_sensor_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
