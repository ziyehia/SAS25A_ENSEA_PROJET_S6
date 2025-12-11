/*
 * task.c
 *
 *  Created on: Mar 31, 2025
 *      Author: nassch
 */

#include "task.h"
#include "emitter.h"
#include "receiver.h"
#include "greenLed.h"

#define EMITTER_PERIOD 50
#define EMITTER_DUTY 2

int static GREEN_LED_State;
int static EMITTER_State;
int static RECEIVER_Pressed;
int static searchSuccess;

void TASK_Init(){
	GREEN_LED_State = 0;
	setGreenLed(GREEN_LED_State);
	EMITTER_State = 0;
	RECEIVER_Pressed = 0;
	searchSuccess = 0;
}

void TASK_Emitter(){
	EMITTER_State = (((int)(HAL_GetTick()/EMITTER_PERIOD))%EMITTER_DUTY != 0) ? 0 : 1;
	setEmitter(EMITTER_State);
}

/*
 * if(searchSuccess == 1){
		GREEN_LED_State = 1 - GREEN_LED_State;
		setGreenLed(GREEN_LED_State);
		RECEIVER_Pressed = 0;
	}
	return;
 *
 * */

void TASK_Evolve(){
	if(searchSuccess == 1){
		GREEN_LED_State = 1 - GREEN_LED_State;
		setGreenLed(GREEN_LED_State);
		RECEIVER_Pressed = 0;
	}
	return;
}

void TASK_Receiver(){
	if(searchSuccess != 1){
		searchSuccess = RECEIVER_GetActivate();
	}
	return;
}
