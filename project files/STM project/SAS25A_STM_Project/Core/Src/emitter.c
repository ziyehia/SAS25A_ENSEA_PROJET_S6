/*
 * emitter.c
 *
 *  Created on: Mar 31, 2025
 *      Author: nassch
 */

#include "emitter.h"


void emitterBlink(){
	HAL_GPIO_WritePin(EMITTER_GPIO, EMITTER_PIN, GPIO_PIN_SET);
	HAL_Delay(50);
	HAL_GPIO_WritePin(EMITTER_GPIO, EMITTER_PIN, GPIO_PIN_RESET);
	HAL_Delay(50);
}

void setEmitter(int emitterState){
	HAL_GPIO_WritePin(EMITTER_GPIO, EMITTER_PIN, emitterState);
}
