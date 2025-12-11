/*
 * receiver.h
 *
 *  Created on: Mar 31, 2025
 *      Author: nassch
 */

#include "stm32l4xx_hal.h"

#ifndef INC_RECEIVER_H_
#define INC_RECEIVER_H_

#define RECEIVER_GPIO GPIOB
#define RECEIVER_PIN GPIO_PIN_5

int RECEIVER_GetLevel();
int RECEIVER_GetActivate();

//GPIO_PinState getLevel()

#endif /* INC_RECEIVER_H_ */
