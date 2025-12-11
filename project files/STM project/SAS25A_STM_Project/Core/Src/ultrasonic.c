/*
 * ultrasonic.c
 *
 *  Created on: May 12, 2025
 *      Author: nassch
 */

#include "ultrasonic.h"
#include "main.h"
#include "greenLed.h"

uint32_t time_start = 0;
uint32_t time_end = 0;
float distance_cm = 0.0f;
extern TIM_HandleTypeDef htim1;


//pour reperer les instants, nous utilisons le comptage du timer 1
void handle_rising_edge(void)
{
    time_start = __HAL_TIM_GET_COUNTER(&htim1);   //reperage de l'instant du front montant
}

void handle_falling_edge(void)
{
    time_end = __HAL_TIM_GET_COUNTER(&htim1);    //reperage de l'instant du front descendant

    uint32_t duration = (time_end >= time_start) ?
                        (time_end - time_start) :
                        ((0xFFFF - time_start) + time_end);  //expression ternaire assure le bon calcul de la distance, demander à Yehia pour l'explication détaillée

    // vitesse du son dans l'air ≈ 343 m/s = 0.0343 cm/µs
    // Le signal fait un aller-retour → division par 2
    distance_cm = ((float)duration * 0.0343f) / 2.0f;
}
