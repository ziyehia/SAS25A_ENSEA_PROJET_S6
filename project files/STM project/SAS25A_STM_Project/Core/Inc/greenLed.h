/*
 * greenLed.h
 *
 *  Created on: Mar 31, 2025
 *      Author: nassch
 */

#include "stm32l4xx_hal.h"

#ifndef INC_GREENLED_H_
#define INC_GREENLED_H_

#define GREENLED_GPIO GPIOA
#define GREENLED_PIN GPIO_PIN_5

void greenLedBlink();
void setGreenLed(GPIO_PinState ledState);

#endif /* INC_GREENLED_H_ */
