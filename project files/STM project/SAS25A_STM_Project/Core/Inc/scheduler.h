/*
 * scheduler.h
 *
 *  Created on: Mar 31, 2025
 *      Author: nassch
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

void schedulerStep();
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

#endif /* INC_SCHEDULER_H_ */
