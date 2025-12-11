/*
 * greenLed.c
 *
 *  Created on: Mar 31, 2025
 *      Author: nassch
 */
#include "greenLed.h"

void greenLedBlink(){
	HAL_GPIO_WritePin(GREENLED_GPIO, GREENLED_PIN, GPIO_PIN_SET);
	HAL_Delay(200);
	HAL_GPIO_WritePin(GREENLED_GPIO, GREENLED_PIN, GPIO_PIN_RESET);
	HAL_Delay(200);
}

void setGreenLed(GPIO_PinState ledState){
	HAL_GPIO_WritePin(GREENLED_GPIO, GREENLED_PIN,ledState );
}
