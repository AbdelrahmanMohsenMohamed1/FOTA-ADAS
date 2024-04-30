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
#define Motor1_INT2_Pin GPIO_PIN_4
#define Motor1_INT2_GPIO_Port GPIOA
#define Motor1_INT1_Pin GPIO_PIN_5
#define Motor1_INT1_GPIO_Port GPIOA
#define Motor2_INT1_Pin GPIO_PIN_6
#define Motor2_INT1_GPIO_Port GPIOA
#define Motor3_INT2_Pin GPIO_PIN_7
#define Motor3_INT2_GPIO_Port GPIOA
#define Ultra_Trigger4_Pin GPIO_PIN_10
#define Ultra_Trigger4_GPIO_Port GPIOB
#define Ultra_Trigger3_Pin GPIO_PIN_11
#define Ultra_Trigger3_GPIO_Port GPIOB
#define Ultra_Trigger2_Pin GPIO_PIN_12
#define Ultra_Trigger2_GPIO_Port GPIOB
#define Ulta_Trigger1_Pin GPIO_PIN_13
#define Ulta_Trigger1_GPIO_Port GPIOB
#define IR1_Pin GPIO_PIN_14
#define IR1_GPIO_Port GPIOB
#define DHT_Pin GPIO_PIN_15
#define DHT_GPIO_Port GPIOB
#define IR2_Pin GPIO_PIN_15
#define IR2_GPIO_Port GPIOA
#define IR3_Pin GPIO_PIN_3
#define IR3_GPIO_Port GPIOB
#define IR4_Pin GPIO_PIN_4
#define IR4_GPIO_Port GPIOB
#define WaterLevel_Pin GPIO_PIN_5
#define WaterLevel_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
