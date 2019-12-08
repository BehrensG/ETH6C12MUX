/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
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
#include "stm32f7xx_hal.h"

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
#define RELAY1_nRST_Pin GPIO_PIN_0
#define RELAY1_nRST_GPIO_Port GPIOB
#define MCU_FLASH1_CS_Pin GPIO_PIN_13
#define MCU_FLASH1_CS_GPIO_Port GPIOF
#define MCU_FLASH2_CS_Pin GPIO_PIN_14
#define MCU_FLASH2_CS_GPIO_Port GPIOF
#define RELAY1_nCS4_Pin GPIO_PIN_15
#define RELAY1_nCS4_GPIO_Port GPIOF
#define RELAY1_nCS3_Pin GPIO_PIN_0
#define RELAY1_nCS3_GPIO_Port GPIOG
#define RELAY1_nCS2_Pin GPIO_PIN_1
#define RELAY1_nCS2_GPIO_Port GPIOG
#define RELAY1_nCS1_Pin GPIO_PIN_7
#define RELAY1_nCS1_GPIO_Port GPIOE
#define RELAY1_nCS0_Pin GPIO_PIN_8
#define RELAY1_nCS0_GPIO_Port GPIOE
#define RELAY2_nRST_Pin GPIO_PIN_10
#define RELAY2_nRST_GPIO_Port GPIOE
#define RELAY2_nCS0_Pin GPIO_PIN_11
#define RELAY2_nCS0_GPIO_Port GPIOE
#define RELAY2_nCS1_Pin GPIO_PIN_12
#define RELAY2_nCS1_GPIO_Port GPIOE
#define RELAY2_nCS2_Pin GPIO_PIN_13
#define RELAY2_nCS2_GPIO_Port GPIOE
#define RELAY2_nCS3_Pin GPIO_PIN_14
#define RELAY2_nCS3_GPIO_Port GPIOE
#define RELAY2_nCS4_Pin GPIO_PIN_15
#define RELAY2_nCS4_GPIO_Port GPIOE
#define MODULE_DETECT1_Pin GPIO_PIN_10
#define MODULE_DETECT1_GPIO_Port GPIOB
#define MODULE_DETECT0_Pin GPIO_PIN_11
#define MODULE_DETECT0_GPIO_Port GPIOB
#define MCU_DEFAULT_Pin GPIO_PIN_12
#define MCU_DEFAULT_GPIO_Port GPIOB



typedef struct _ip4_lan ip4_lan_t;
typedef struct _spi_module spi_module_t;
typedef struct _scpi_info scpi_info_t;
typedef struct _security security_t;

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
