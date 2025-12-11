/*
 * motor.h
 *
 *  Created on: Apr 7, 2025
 *      Author: nassch
 */

#include "stm32l4xx_hal.h"

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_


// Right Motor
#define MOTOR_R_DIR_PORT GPIOC
#define MOTOR_R_DIR_PIN GPIO_PIN_0
#define MOTOR_R_STEPPER_PORT GPIOB
#define MOTOR_R_STEPPER_PIN GPIO_PIN_0

// Left Motor
#define MOTOR_L_DIR_PORT GPIOA
#define MOTOR_L_DIR_PIN GPIO_PIN_4
#define MOTOR_L_STEPPER_PORT GPIOA
#define MOTOR_L_STEPPER_PIN GPIO_PIN_1

void setDirectionMotor(GPIO_TypeDef* port, uint16_t pin, GPIO_PinState dir);
void setDirection(GPIO_PinState dir);
void turn(int step,int delay);
void setMotors(GPIO_PinState MotorsState);

#endif /* INC_MOTOR_H_ */
