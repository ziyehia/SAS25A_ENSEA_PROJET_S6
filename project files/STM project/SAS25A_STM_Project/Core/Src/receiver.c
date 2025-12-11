/*
 * receiver.c
 *
 *  Created on: Mar 31, 2025
 *      Author: nassch
 */

#include "receiver.h"

int RECEIVER_PreviousValue = 1;

int RECEIVER_GetLevel(){
	int level = HAL_GPIO_ReadPin(RECEIVER_GPIO,RECEIVER_PIN);
	return level;
}

int RECEIVER_GetActivate(){
	int level = RECEIVER_GetLevel();
	if(level == 0 && RECEIVER_PreviousValue == 1 ){
		RECEIVER_PreviousValue = level;
		return 1;
	}
	RECEIVER_PreviousValue = level;
	return 0;
}
