/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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

/* Includes ------------------------------------------------------------------*/
#include <scpi_def.h>
#include <tcp_raw.h>
#include "main.h"
#include "lwip.h"

#include "scpi/scpi.h"
#include "scpi_def.h"
#include "stm32f7xx_hal_spi.h"
#include "defines.h"
#include "spi_flash.h"
#include "matrix.h"



/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

SPI_HandleTypeDef hspi3;
SPI_HandleTypeDef hspi4;
SPI_HandleTypeDef hspi5;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI5_Init(void);
static void MX_SPI3_Init(void);
static void MX_SPI4_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */

void BOARD_CreateDefaultData()
{
	default_board.scpi_info.manufacturer = (int8_t)malloc(SCPI_MANUFACTURER_STRING_LENGTH*sizeof(int8_t));
	default_board.scpi_info.device = (int8_t)malloc(SCPI_DEVICE_STRING_LENGTH*sizeof(int8_t));
	default_board.scpi_info.serial_number = (int8_t)malloc(SCPI_SERIALNUMBER_STRING_LENGTH*sizeof(int8_t));
	default_board.scpi_info.software_version = (int8_t)malloc(SCPI_SOFTWAREVERSION_STRING_LENGTH*sizeof(int8_t));
	default_board.security.password = (int8_t)malloc(PASSWORD_LENGTH*sizeof(int8_t));
	default_board.ip4_current.hostname = (int8_t)malloc(NET_HOSTNAME*sizeof(int8_t));
	default_board.ip4_static.hostname = (int8_t)malloc(NET_HOSTNAME*sizeof(int8_t));

	default_board.scpi_info.manufacturer = SCPI_IDN1;
	default_board.scpi_info.device = SCPI_IDN2;
	default_board.scpi_info.serial_number = SCPI_IDN3;
	default_board.scpi_info.software_version = SCPI_IDN4;

	default_board.security.on = SECURITY_ON;
	default_board.security.password = PASSWORD;

	default_board.module.detected = FALSE;

	default_board.ip4_static.hostname = default_board.ip4_current.hostname = SCPI_IDN2;
	default_board.ip4_static.ip[0] = default_board.ip4_current.ip[0] = IP_ADDRESS0;
	default_board.ip4_static.ip[1] = default_board.ip4_current.ip[1] = IP_ADDRESS1;
	default_board.ip4_static.ip[2] = default_board.ip4_current.ip[2] = IP_ADDRESS2;
	default_board.ip4_static.ip[3] = default_board.ip4_current.ip[3] = IP_ADDRESS3;

	default_board.ip4_static.netmask[0] = default_board.ip4_current.netmask[0] = NETMASK_ADDRESS0;
	default_board.ip4_static.netmask[1] = default_board.ip4_current.netmask[1] = NETMASK_ADDRESS1;
	default_board.ip4_static.netmask[2] = default_board.ip4_current.netmask[2] = NETMASK_ADDRESS2;
	default_board.ip4_static.netmask[3] = default_board.ip4_current.netmask[3] = NETMASK_ADDRESS3;

	default_board.ip4_static.gateway[0] = default_board.ip4_current.gateway[0] = GATEWAY_ADDRESS0;
	default_board.ip4_static.gateway[1] = default_board.ip4_current.gateway[1] = GATEWAY_ADDRESS1;
	default_board.ip4_static.gateway[2] = default_board.ip4_current.gateway[2] = GATEWAY_ADDRESS2;
	default_board.ip4_static.gateway[3] = default_board.ip4_current.gateway[3] = GATEWAY_ADDRESS3;

	default_board.ip4_static.port = default_board.ip4_current.port = TCPIP_PORT;

	default_board.ip4_static.MAC[0] = default_board.ip4_current.MAC[0] = MAC0;
	default_board.ip4_static.MAC[1] = default_board.ip4_current.MAC[1] = MAC1;
	default_board.ip4_static.MAC[2] = default_board.ip4_current.MAC[2] = MAC2;
	default_board.ip4_static.MAC[3] = default_board.ip4_current.MAC[3] = MAC3;
	default_board.ip4_static.MAC[4] = default_board.ip4_current.MAC[4] = MAC4;
	default_board.ip4_static.MAC[5] = default_board.ip4_current.MAC[5] = MAC5;

	default_board.default_config = DEFAULT_OFF;
	default_board.dhcp = OFF;

	board = default_board;

}

void BOARD_DetectDefaultConfig()
{
	board.default_config = HAL_GPIO_ReadPin(MCU_DEFAULT_GPIO_Port, MCU_DEFAULT_Pin);
}

int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */
  

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */

	HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */

  MX_GPIO_Init();
  MX_SPI5_Init();
  MX_LWIP_Init();
  MX_SPI3_Init();
  MX_SPI4_Init();
  tcp_raw_init();


  BOARD_CreateDefaultData();
  BOARD_DetectDefaultConfig();
  MATRIX_InitMain();

  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  SCPI_Init(&scpi_context,
           scpi_commands,
           &scpi_interface,
           scpi_units_def,
           SCPI_IDN1, SCPI_IDN2, SCPI_IDN3, SCPI_IDN4,
           scpi_input_buffer, SCPI_INPUT_BUFFER_LENGTH,
           scpi_error_queue_data, SCPI_ERROR_QUEUE_SIZE);

  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  MX_LWIP_Process();
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 216;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Activate the Over-Drive mode 
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI3_Init(void)
{

  /* USER CODE BEGIN SPI3_Init 0 */

  /* USER CODE END SPI3_Init 0 */

  /* USER CODE BEGIN SPI3_Init 1 */

  /* USER CODE END SPI3_Init 1 */
  /* SPI3 parameter configuration*/
  hspi3.Instance = SPI3;
  hspi3.Init.Mode = SPI_MODE_MASTER;
  hspi3.Init.Direction = SPI_DIRECTION_2LINES;
  hspi3.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi3.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi3.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi3.Init.NSS = SPI_NSS_SOFT;
  hspi3.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi3.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi3.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi3.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi3.Init.CRCPolynomial = 7;
  hspi3.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi3.Init.NSSPMode = SPI_NSS_PULSE_DISABLE;
  if (HAL_SPI_Init(&hspi3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI3_Init 2 */

  /* USER CODE END SPI3_Init 2 */

}

/**
  * @brief SPI4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI4_Init(void)
{

  /* USER CODE BEGIN SPI4_Init 0 */

  /* USER CODE END SPI4_Init 0 */

  /* USER CODE BEGIN SPI4_Init 1 */

  /* USER CODE END SPI4_Init 1 */
  /* SPI4 parameter configuration*/
  hspi4.Instance = SPI4;
  hspi4.Init.Mode = SPI_MODE_MASTER;
  hspi4.Init.Direction = SPI_DIRECTION_2LINES;
  hspi4.Init.DataSize = SPI_DATASIZE_4BIT;
  hspi4.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi4.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi4.Init.NSS = SPI_NSS_SOFT;
  hspi4.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
  hspi4.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi4.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi4.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi4.Init.CRCPolynomial = 7;
  hspi4.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi4.Init.NSSPMode = SPI_NSS_PULSE_ENABLE;
  if (HAL_SPI_Init(&hspi4) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI4_Init 2 */

  /* USER CODE END SPI4_Init 2 */

}

/**
  * @brief SPI5 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI5_Init(void)
{

  /* USER CODE BEGIN SPI5_Init 0 */

  /* USER CODE END SPI5_Init 0 */

  /* USER CODE BEGIN SPI5_Init 1 */

  /* USER CODE END SPI5_Init 1 */
  /* SPI5 parameter configuration*/
  hspi5.Instance = SPI5;
  hspi5.Init.Mode = SPI_MODE_MASTER;
  hspi5.Init.Direction = SPI_DIRECTION_2LINES;
  hspi5.Init.DataSize = SPI_DATASIZE_4BIT;
  hspi5.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi5.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi5.Init.NSS = SPI_NSS_SOFT;
  hspi5.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
  hspi5.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi5.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi5.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi5.Init.CRCPolynomial = 7;
  hspi5.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi5.Init.NSSPMode = SPI_NSS_PULSE_ENABLE;
  if (HAL_SPI_Init(&hspi5) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI5_Init 2 */

  /* USER CODE END SPI5_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(RELAY1_nRST_GPIO_Port, RELAY1_nRST_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOF, MCU_FLASH1_CS_Pin|MCU_FLASH2_CS_Pin|RELAY1_nCS4_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOG, RELAY1_nCS3_Pin|RELAY1_nCS2_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, RELAY1_nCS1_Pin|RELAY1_nCS0_Pin|RELAY2_nRST_Pin|RELAY2_nCS0_Pin 
                          |RELAY2_nCS1_Pin|RELAY2_nCS2_Pin|RELAY2_nCS3_Pin|RELAY2_nCS4_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin : RELAY1_nRST_Pin */
  GPIO_InitStruct.Pin = RELAY1_nRST_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(RELAY1_nRST_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : MCU_FLASH1_CS_Pin MCU_FLASH2_CS_Pin RELAY1_nCS4_Pin */
  GPIO_InitStruct.Pin = MCU_FLASH1_CS_Pin|MCU_FLASH2_CS_Pin|RELAY1_nCS4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /*Configure GPIO pins : RELAY1_nCS3_Pin RELAY1_nCS2_Pin */
  GPIO_InitStruct.Pin = RELAY1_nCS3_Pin|RELAY1_nCS2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /*Configure GPIO pins : RELAY1_nCS1_Pin RELAY1_nCS0_Pin RELAY2_nRST_Pin RELAY2_nCS0_Pin 
                           RELAY2_nCS1_Pin RELAY2_nCS3_Pin RELAY2_nCS4_Pin */
  GPIO_InitStruct.Pin = RELAY1_nCS1_Pin|RELAY1_nCS0_Pin|RELAY2_nRST_Pin|RELAY2_nCS0_Pin 
                          |RELAY2_nCS1_Pin|RELAY2_nCS3_Pin|RELAY2_nCS4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pin : RELAY2_nCS2_Pin */
  GPIO_InitStruct.Pin = RELAY2_nCS2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(RELAY2_nCS2_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : MODULE_DETECT1_Pin MODULE_DETECT0_Pin */
  GPIO_InitStruct.Pin = MODULE_DETECT1_Pin|MODULE_DETECT0_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : MCU_DEFAULT_Pin */
  GPIO_InitStruct.Pin = MCU_DEFAULT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(MCU_DEFAULT_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
