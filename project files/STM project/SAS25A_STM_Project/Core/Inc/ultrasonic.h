#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include "stdint.h"

#define ECHO_GPIO GPIOC
#define ECHO_PIN GPIO_PIN_1

#define TRIGGER_GPIO GPIOA
#define TRIGGER_PIN GPIO_PIN_0

#define TRIGGER_PERIOD 20000 // = 200 ms

extern float distance_cm;

void handle_rising_edge(void);
void handle_falling_edge(void);

#endif
