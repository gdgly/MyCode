/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal.h"

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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define MAG_SCL_Pin GPIO_PIN_3
#define MAG_SCL_GPIO_Port GPIOE
#define MAG_SDA_Pin GPIO_PIN_4
#define MAG_SDA_GPIO_Port GPIOE
#define GPS_EN_Pin GPIO_PIN_2
#define GPS_EN_GPIO_Port GPIOC
#define RELAY_EN_Pin GPIO_PIN_4
#define RELAY_EN_GPIO_Port GPIOA
#define ADC_EN_Pin GPIO_PIN_6
#define ADC_EN_GPIO_Port GPIOA
#define EC25_DTR_Pin GPIO_PIN_4
#define EC25_DTR_GPIO_Port GPIOC
#define EC25_AP_READY_Pin GPIO_PIN_9
#define EC25_AP_READY_GPIO_Port GPIOE
#define LEVEL_EN_Pin GPIO_PIN_11
#define LEVEL_EN_GPIO_Port GPIOE
#define CAN2_STB_Pin GPIO_PIN_14
#define CAN2_STB_GPIO_Port GPIOB
#define EC25_STATUS_Pin GPIO_PIN_15
#define EC25_STATUS_GPIO_Port GPIOB
#define EC25_EN_Pin GPIO_PIN_8
#define EC25_EN_GPIO_Port GPIOD
#define FINGER_EN_Pin GPIO_PIN_9
#define FINGER_EN_GPIO_Port GPIOD
#define CAN1_STB_Pin GPIO_PIN_10
#define CAN1_STB_GPIO_Port GPIOD
#define CAN3_STB_Pin GPIO_PIN_11
#define CAN3_STB_GPIO_Port GPIOD
#define EC25_POWERKEY_Pin GPIO_PIN_0
#define EC25_POWERKEY_GPIO_Port GPIOD
#define IMU_CS_Pin GPIO_PIN_6
#define IMU_CS_GPIO_Port GPIOB
#define IMU_INT1_Pin GPIO_PIN_7
#define IMU_INT1_GPIO_Port GPIOB
#define IMU_INT2_Pin GPIO_PIN_8
#define IMU_INT2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
