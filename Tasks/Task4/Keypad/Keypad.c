/*
 * Keypad.c
 *
 *  Created on: May 5, 2023
 *      Author: Mariam Turky
 */
#include "Keypad.h"
uint8 key = 0 ;
uint8 KeypadState = KEYPAD_PRESSED;

uint8 buttons[(ROW_END_INDEX - ROW_START_INDEX) + 1][(COL_END_INDEX - COL_START_INDEX) + 1] = {{1,2,3},
                                                                {4,5,6},
                                                                {7,8,9},
                                                                {0,0,0}
                                                                };

void KEYPAD_Init(void){
	uint8 j;

	for(j = COL_START_INDEX; j <= COL_END_INDEX;j++){
		Gpio_ConfigPin(COL_PORT, j, GPIO_INPUT, GPIO_PULL_UP);
	    }

	for(j = ROW_START_INDEX;j <= ROW_END_INDEX;j++){
		Gpio_ConfigPin(COL_PORT, j, GPIO_OUTPUT, GPIO_PUSH_PULL);
		Gpio_WritePin(ROW_PORT, j,HIGH);
		}
}



void KEYPAD_Manage(void){

	uint8 row, col=0;
	if(KeypadState == KEYPAD_PRESSED){
		for(row =ROW_START_INDEX; row <= ROW_END_INDEX;row++){
			Gpio_WritePin(ROW_PORT, row,LOW);


			for(col = COL_START_INDEX; col <= COL_END_INDEX; col++){
				if(Gpio_ReadPin(COL_PORT, col) == KEYPAD_PRESSED ){
					delay_ms(30);

					if(Gpio_ReadPin(COL_PORT, col) == KEYPAD_PRESSED ){
						key = buttons[row-ROW_START_INDEX][col - COL_START_INDEX];
						KEYPAD_Callout_KeyPressNotificaton();
					}
				}
			}

			Gpio_WritePin(ROW_PORT, row, HIGH);
		}
	}
}
uint8  KEYPAD_GetKey(void){
	 KeypadState = KEYPAD_PRESSED;
	 return key;
}
