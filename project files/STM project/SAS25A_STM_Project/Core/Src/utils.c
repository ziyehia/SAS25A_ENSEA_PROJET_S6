/*
 * utils.c
 *
 *  Created on: Mar 31, 2025
 *      Author: nassch
 */

#include "utils.h"
#include "emitter.h"
#include "receiver.h"
#include "greenLed.h"
#include "task.h"
#include "motor.h"
#include "main.h"
extern TIM_HandleTypeDef htim5;
extern float distance_cm;


void setup(){
	setEmitter(1);

	//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, 1);
	HAL_GPIO_WritePin(LEFT_MOTOR_PIN1_PORT, LEFT_MOTOR_PIN1_Pin, 1);
	HAL_GPIO_WritePin(GPIOC, LEFT_MOTOR_PIN2_Pin, 0);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 1);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);
	//TASK_Init();
	/*
	setDirection(GPIO_PIN_SET);
	uint32_t arr = 29999;      // Start at ~33 Hz
	uint32_t min_arr = 999;    // Target: 5 kHz

	while (arr > min_arr)
			{
				__HAL_TIM_SET_AUTORELOAD(&htim5, arr);
				__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_2, arr / 2);

				HAL_Delay(30);      // Give time to accelerate
				arr -= 500;         // Decrease step size if jump is too hard
			}
	__HAL_TIM_SET_AUTORELOAD(&htim5, min_arr);
	__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_2, min_arr / 2);

*/
	return;
}

void loop(){
	  if (distance_cm<10){
		  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, 0);
		  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, 0);
	  }
	  else{
		  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, 1);
		  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, 0);
	  }

	/*
	if(distance_cm < 10 ){
		setGreenLed(1);
		return;
	}
	else{
		setGreenLed(0);
		setMotors(GPIO_PIN_SET);
		HAL_Delay(1 / 1000);
		setMotors(GPIO_PIN_RESET);
		HAL_Delay(1 / 1000);
	}*/
}
