/*
 * tasks.c
 *
 *  Created on: Dec 12, 2024
 *      Author: VO HOANG HUY
 */
#include "tasks.h"

void testRedLed() {
	HAL_GPIO_TogglePin(RED_LED_GPIO_Port, RED_LED_Pin);
}

void testGreenLed() {
	HAL_GPIO_TogglePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin);
}

void testYellowLed() {
	HAL_GPIO_TogglePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin);
}

void blink_led4(){//tasks running periodically in 2 second
	HAL_GPIO_TogglePin(LED4_GPIO_Port,LED4_Pin);
}

//one-shot task
void blink_led5(){
	HAL_GPIO_TogglePin(LED5_GPIO_Port,LED5_Pin);
}
