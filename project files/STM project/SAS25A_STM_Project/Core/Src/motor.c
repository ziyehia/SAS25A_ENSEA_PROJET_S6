/*
 * motor.c
 *
 *  Created on: Apr 7, 2025
 *      Author: nassch
 */

#include "motor.h"
#include "main.h"

void setDirectionMotor(GPIO_TypeDef* port, uint16_t pin, GPIO_PinState dir){
	HAL_GPIO_WritePin(port, pin, dir);
	return;
}

void setDirection(GPIO_PinState dir){
	setDirectionMotor(MOTOR_R_DIR_PORT,MOTOR_R_DIR_PIN, dir);
	setDirectionMotor(MOTOR_L_DIR_PORT,MOTOR_L_DIR_PIN, dir);
}

void setMotors(GPIO_PinState MotorsState){
	HAL_GPIO_WritePin(MOTOR_R_STEPPER_PORT, MOTOR_R_STEPPER_PIN, MotorsState);
	HAL_GPIO_WritePin(MOTOR_L_STEPPER_PORT, MOTOR_L_STEPPER_PIN, MotorsState);
}

void turn(int steps,int delay){
	for(int i = 0;i<steps;i++){
		HAL_GPIO_WritePin(MOTOR_R_STEPPER_PORT, MOTOR_R_STEPPER_PIN, GPIO_PIN_SET);
		HAL_Delay(delay / 1000);
		HAL_GPIO_WritePin(MOTOR_R_STEPPER_PORT, MOTOR_R_STEPPER_PIN, GPIO_PIN_RESET);
		HAL_Delay(delay / 1000);
		return;
	}
}
