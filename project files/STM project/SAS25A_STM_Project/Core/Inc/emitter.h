/*
 * emitter.h
 *
 *  Created on: Mar 31, 2025
 *      Author: nassch
 */

#include "stm32l4xx_hal.h"

#ifndef INC_EMITTER_H_
#define INC_EMITTER_H_

// Port D2
#define EMITTER_GPIO GPIOA
#define EMITTER_PIN GPIO_PIN_10

void setEmitter(int emitterState);

#endif /* INC_EMITTER_H_ */
