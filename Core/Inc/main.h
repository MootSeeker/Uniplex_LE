/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "stm32l4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

// CubeMx includes ............................................................
#include "crc.h"
#include "i2c.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "usb_device.h"
#include "gpio.h"

// Private includes ...........................................................
#include "debug.h"



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
#define BTN1_Pin GPIO_PIN_13
#define BTN1_GPIO_Port GPIOC
#define BTN1_EXTI_IRQn EXTI15_10_IRQn
#define LED_RED_Pin GPIO_PIN_14
#define LED_RED_GPIO_Port GPIOC
#define LED_GRN_Pin GPIO_PIN_15
#define LED_GRN_GPIO_Port GPIOC
#define NFC_EN_Pin GPIO_PIN_0
#define NFC_EN_GPIO_Port GPIOH
#define NFC_GPO_Pin GPIO_PIN_1
#define NFC_GPO_GPIO_Port GPIOH
#define NFC_GPO_EXTI_IRQn EXTI1_IRQn
#define NFC_SCL_Pin GPIO_PIN_0
#define NFC_SCL_GPIO_Port GPIOC
#define NFC_SDA_Pin GPIO_PIN_1
#define NFC_SDA_GPIO_Port GPIOC
#define PROBE1_EN_Pin GPIO_PIN_2
#define PROBE1_EN_GPIO_Port GPIOC
#define PROBE2_EN_Pin GPIO_PIN_3
#define PROBE2_EN_GPIO_Port GPIOC
#define RTC_INT_Pin GPIO_PIN_0
#define RTC_INT_GPIO_Port GPIOA
#define PROBE_SW_Pin GPIO_PIN_1
#define PROBE_SW_GPIO_Port GPIOA
#define PROBE_TX_Pin GPIO_PIN_2
#define PROBE_TX_GPIO_Port GPIOA
#define PROBE_RX_Pin GPIO_PIN_3
#define PROBE_RX_GPIO_Port GPIOA
#define FLASH_CS_Pin GPIO_PIN_4
#define FLASH_CS_GPIO_Port GPIOA
#define FLASH_SCK_Pin GPIO_PIN_5
#define FLASH_SCK_GPIO_Port GPIOA
#define FLASH_MISO_Pin GPIO_PIN_6
#define FLASH_MISO_GPIO_Port GPIOA
#define DLASH_MOSI_Pin GPIO_PIN_7
#define DLASH_MOSI_GPIO_Port GPIOA
#define FLASH_WP_Pin GPIO_PIN_4
#define FLASH_WP_GPIO_Port GPIOC
#define FLASH_PW_Pin GPIO_PIN_5
#define FLASH_PW_GPIO_Port GPIOC
#define LCD_BL_Pin GPIO_PIN_0
#define LCD_BL_GPIO_Port GPIOB
#define BLE_TX_Pin GPIO_PIN_10
#define BLE_TX_GPIO_Port GPIOB
#define BLE_RX_Pin GPIO_PIN_11
#define BLE_RX_GPIO_Port GPIOB
#define BLE_CTS_Pin GPIO_PIN_13
#define BLE_CTS_GPIO_Port GPIOB
#define BLE_RTS_Pin GPIO_PIN_14
#define BLE_RTS_GPIO_Port GPIOB
#define _5V_EN_Pin GPIO_PIN_15
#define _5V_EN_GPIO_Port GPIOB
#define CHARG_EN_Pin GPIO_PIN_6
#define CHARG_EN_GPIO_Port GPIOC
#define CHARG_DCT_Pin GPIO_PIN_7
#define CHARG_DCT_GPIO_Port GPIOC
#define SPL_DCT_Pin GPIO_PIN_8
#define SPL_DCT_GPIO_Port GPIOC
#define DEBUG_TX_Pin GPIO_PIN_9
#define DEBUG_TX_GPIO_Port GPIOA
#define DEBUG_RX_Pin GPIO_PIN_10
#define DEBUG_RX_GPIO_Port GPIOA
#define LCD_EN_Pin GPIO_PIN_10
#define LCD_EN_GPIO_Port GPIOC
#define LCD_RST_Pin GPIO_PIN_11
#define LCD_RST_GPIO_Port GPIOC
#define LCD_DC_Pin GPIO_PIN_12
#define LCD_DC_GPIO_Port GPIOC
#define LCD_CS_Pin GPIO_PIN_2
#define LCD_CS_GPIO_Port GPIOD
#define LCD_SCK_Pin GPIO_PIN_3
#define LCD_SCK_GPIO_Port GPIOB
#define LCD_MISO_Pin GPIO_PIN_4
#define LCD_MISO_GPIO_Port GPIOB
#define LCD_MOSI_Pin GPIO_PIN_5
#define LCD_MOSI_GPIO_Port GPIOB
#define TOUCH_INT_Pin GPIO_PIN_6
#define TOUCH_INT_GPIO_Port GPIOB
#define TOUCH_INT_EXTI_IRQn EXTI9_5_IRQn
#define TOUCH_RST_Pin GPIO_PIN_7
#define TOUCH_RST_GPIO_Port GPIOB
#define TOUCH_SCL_Pin GPIO_PIN_8
#define TOUCH_SCL_GPIO_Port GPIOB
#define TOUCH_SDA_Pin GPIO_PIN_9
#define TOUCH_SDA_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
