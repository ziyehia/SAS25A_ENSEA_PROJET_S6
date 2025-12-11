/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#define MOTOT_R_DIR_PIN_Pin GPIO_PIN_0
#define MOTOT_R_DIR_PIN_GPIO_Port GPIOC
#define ECHO_PIN_Pin GPIO_PIN_1
#define ECHO_PIN_GPIO_Port GPIOC
#define ECHO_PIN_EXTI_IRQn EXTI1_IRQn
#define LEFT_MOTOR_PIN1_Pin GPIO_PIN_2
#define LEFT_MOTOR_PIN1_GPIO_Port GPIOC
#define LEFT_MOTOR_PIN2_Pin GPIO_PIN_3
#define LEFT_MOTOR_PIN2_GPIO_Port GPIOC
#define TRIGGER_PIN_Pin GPIO_PIN_0
#define TRIGGER_PIN_GPIO_Port GPIOA
#define MOTOR_L_DIR_PIN_Pin GPIO_PIN_4
#define MOTOR_L_DIR_PIN_GPIO_Port GPIOA
#define GREEN_LED_Pin GPIO_PIN_5
#define GREEN_LED_GPIO_Port GPIOA
#define MOTOR_R_STEPPER_PIN_Pin GPIO_PIN_0
#define MOTOR_R_STEPPER_PIN_GPIO_Port GPIOB
#define RIGHT_MOTOR_PIN1_Pin GPIO_PIN_7
#define RIGHT_MOTOR_PIN1_GPIO_Port GPIOC
#define RIGHT_MOTOR_PIN2_Pin GPIO_PIN_9
#define RIGHT_MOTOR_PIN2_GPIO_Port GPIOA
#define EMITTER_PIN_Pin GPIO_PIN_10
#define EMITTER_PIN_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define RECEIVER_PIN_Pin GPIO_PIN_5
#define RECEIVER_PIN_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
