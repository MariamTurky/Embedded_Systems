/*
 * Keypad.h
 *
 *  Created on: May 5, 2023
 *      Author: Mariam Turky
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "Gpio.h"
#include "Std_Types.h"

#define COL_PORT         GPIO_B
#define COL_START_INDEX     0
#define COL_END_INDEX       2

#define ROW_PORT         GPIO_B
#define ROW_START_INDEX     5
#define ROW_END_INDEX       8

#define KEYPAD_PRESSED   	0
#define KEYPAD_NOTPRESSED   1



void KEYPAD_Init(void);
void KEYPAD_Manage(void);
uint8  KEYPAD_GetKey(void);
void KEYPAD_Callout_KeyPressNotificaton(void);


#endif /* KEYPAD_H_ */
