/*#include "stm32l4xx_hal.h"

#include "FreeRTOS.h"
#include "task.h"

#include "led_driver.h"
#include "joy_driver.h"
 * LedTask.h
 *
 *  Created on: Oct 6, 2025
 *      Author: pinkyflowy
 */

#ifndef INC_LEDTASK_H_
#define INC_LEDTASK_H_

#include "stm32l4xx_hal.h"

#include "FreeRTOS.h"
#include "task.h"

#include "led_driver.h"
#include "joy_driver.h"

void LedToggleTask(void * pargs);
void CreateLedTask();


#endif /* INC_LEDTASK_H_ */
