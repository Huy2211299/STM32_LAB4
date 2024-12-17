/*
 * tasks.h
 *
 *  Created on: Dec 12, 2024
 *      Author: VO HOANG HUY
 */

#ifndef INC_TASKS_H_
#define INC_TASKS_H_

#include "main.h"

void testRedLed();
void testGreenLed();
void testYellowLed();

void blink_led4();//tasks running periodically in 2 second

void blink_led5();// one-shot task

#endif /* INC_TASKS_H_ */
