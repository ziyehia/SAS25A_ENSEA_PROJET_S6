/*
 * sheduler.c
 *
 *  Created on: Mar 31, 2025
 *      Author: nassch
 */

#include "main.h"
#include "scheduler.h"
#include "task.h"
#include "greenLed.h"
#include "emitter.h"
#include "receiver.h"
#include "ultrasonic.h"

typedef enum TASK_IR{
	TASK_EMITTER,
	TASK_EVOLVE,
	TASK_RECEIVER,
	TASK_RAW
}task_IR_t;

static task_IR_t currentTask = TASK_EMITTER;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim2;

static int trigger_counter = 0;
volatile uint32_t duration = 0;
volatile uint8_t edge_state = 0;  // 0: waiting for rising edge, 1: waiting for falling edge

// tim 1 -> echo
// tim 2 -> trigger
// tim 4 -> IR#define ECHO_GPIO GPIOC

void schedulerStep_IR(){
	currentTask = (currentTask + 1) % TASK_RAW;
	switch (currentTask){
		case TASK_EMITTER:
			TASK_Emitter();
			break;
		case TASK_EVOLVE:
			TASK_Evolve();
			break;
		case TASK_RECEIVER:
			TASK_Receiver();
			break;
		default :
			break;
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if (htim==&htim2){
		if (trigger_counter == TRIGGER_PERIOD - 1) { //500ms - 10 micro-secondes
			HAL_GPIO_WritePin(TRIGGER_GPIO, TRIGGER_PIN, GPIO_PIN_SET);
		}
		else if (trigger_counter == TRIGGER_PERIOD){
			HAL_GPIO_WritePin(TRIGGER_GPIO, TRIGGER_PIN, GPIO_PIN_RESET);
			trigger_counter = 0;
		}
		trigger_counter += 1;
	}
	if (htim==&htim4) {
		schedulerStep_IR();
	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	 if (GPIO_Pin == ECHO_PIN)
	    {
	        if (HAL_GPIO_ReadPin(ECHO_GPIO, ECHO_PIN) == GPIO_PIN_SET)
	        {
	            handle_rising_edge();

	        }

	        else
	        {
	            handle_falling_edge();
	        }
	    }
}
