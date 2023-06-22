/*
 * main.c
 *
 *  Created on: Jun 18, 2023
 *
 */

#include "Bit_Operations.h"
#include "Gpio.h"
#include "Rcc.h"
#include "Std_Types.h"
#include "Gpt.h"

#define door_locked  1       // Set the initial state to locked
#define door_unlocked  	0     // Set the initial state to closed
#define door_opened  	1
#define door_closed  	0
int pressed_button = 	0 ;
int state1 = door_locked;
int state2 = door_closed;
int start_time = 1;
int hazard_led =1;
int count = 0;
int thift_locking_function=1;
int do_locking_door=0;
int start_10_seconds=1;
void door_unlock(void);
void door_is_open(void);
void anti_theft_vehicle_lock(void);
void closing_door(void);
void Locking_the_door(void);
int main() {
	Rcc_Init();
	Rcc_Enable(RCC_GPIOA);
	Rcc_Enable(RCC_GPIOB);
	Rcc_Enable(RCC_SYSCFG);
	Rcc_Enable(RCC_TIM2);


    Gpio_ConfigPin(GPIO_A, 0, GPIO_INPUT, GPIO_OPEN_DRAIN,0);
	Gpio_ConfigPin(GPIO_A, 4, GPIO_INPUT, GPIO_OPEN_DRAIN,0);

	Gpio_ConfigPin(GPIO_B, 0, GPIO_OUTPUT, GPIO_PUSH_PULL,0); //vehicle led
	Gpio_ConfigPin(GPIO_B, 5, GPIO_OUTPUT, GPIO_PUSH_PULL,0); //hazard led
	Gpio_ConfigPin(GPIO_B, 10, GPIO_OUTPUT, GPIO_PUSH_PULL,0); // ambient led
	Gpio_ConfigPin(GPIO_B, 1, GPIO_OUTPUT, GPIO_PUSH_PULL,0);

	GPT_Init();

	while(1){
	 int doorUnlock_button = Gpio_ReadPin(GPIO_A, 0);
	 int handle_button = Gpio_ReadPin(GPIO_A, 4);
	 if(state1== door_locked){
		if(handle_button == LOW && !pressed_button){ //handle button is pressed
			  GPT_StartTimer(500);
			  Gpio_WritePin(GPIO_B, 0, HIGH);
			  Gpio_WritePin(GPIO_B, 5, HIGH);
			  Gpio_WritePin(GPIO_B, 10, HIGH);
			  hazard_led =1;
			  pressed_button =1; //vehicle door unlocked but still closed
		}
		if(pressed_button == 1)
		door_unlock();
      }

		if( state1 == door_unlocked){
			if(state2 == door_closed){
				if(start_10_seconds){
					GPT_StartTimer(10000);
					start_10_seconds=0;
				}

				if(doorUnlock_button == LOW ){ //unlock button is pressed
					state2 = door_opened; //vehicle door unlocked & opened
					door_is_open();
					pressed_button=1;
				}

		else if(handle_button == LOW){ //handle button is pressed
			if(!pressed_button){
			Gpio_WritePin(GPIO_B, 0, LOW);
			Gpio_WritePin(GPIO_B, 5, HIGH);
			Gpio_WritePin(GPIO_B, 10, LOW);
			hazard_led=1;
			pressed_button=1;
			do_locking_door=1;
			start_time=1;
			}
		}


		else if(handle_button == HIGH && doorUnlock_button == HIGH&&thift_locking_function){ //No buttons is pressed
			pressed_button=0;
				if(GPT_CheckTimeIsElapsed()){
					Gpio_WritePin(GPIO_B, 0, LOW);
					Gpio_WritePin(GPIO_B, 5, HIGH);
					Gpio_WritePin(GPIO_B, 10, LOW);
					start_time = 1;
					do_locking_door=1;
					hazard_led=1;
					thift_locking_function=0;
				}
				}

		if(do_locking_door){
					Locking_the_door();
				}
			}

			else if(state2 == door_opened ){
				if(doorUnlock_button == LOW){
				if(!pressed_button){ //handle button is pressed
					Gpio_WritePin(GPIO_B, 0, LOW);
					Gpio_WritePin(GPIO_B, 5, LOW);
					Gpio_WritePin(GPIO_B, 10, HIGH);
					GPT_StartTimer(1000);
					pressed_button=1;
					closing_door();

				}
				}else{
					pressed_button=0;
					closing_door();
				}

			}

}

	}
}

void door_unlock(void){

	if(hazard_led == 1){
	   if(GPT_CheckTimeIsElapsed()){
		  hazard_led = 0;
		  Gpio_WritePin(GPIO_B, 5, LOW);
		  GPT_StartTimer(1500);
		}
	}
	else{
		if(GPT_CheckTimeIsElapsed()){
			Gpio_WritePin(GPIO_B, 10, LOW);
			state1 = door_unlocked;
			pressed_button = 0;
			hazard_led=1;
		}
	}

}

void door_is_open(void){
	Gpio_WritePin(GPIO_B, 0, LOW);
	Gpio_WritePin(GPIO_B, 5, LOW);
	Gpio_WritePin(GPIO_B, 10, HIGH);
	start_10_seconds=1;
}

void closing_door(void){
	if(GPT_CheckTimeIsElapsed()){
		Gpio_WritePin(GPIO_B, 10, LOW);
		pressed_button=0;
		state2 = door_closed; //door is unlocked but closed
				}
}

void Locking_the_door(void){
	if(count<3){
			if(start_time){
			  GPT_StartTimer(500);
			  start_time=0;
			}
			if(GPT_CheckTimeIsElapsed()){
				start_time = 1;
				count++ ;
				hazard_led=!hazard_led;
				Gpio_WritePin(GPIO_B, 5, hazard_led);

			}

	}
	else {
		count=0;
		do_locking_door=0;
		thift_locking_function=1;
		state1 = door_locked; //door is locked & closed
		start_10_seconds=1;
	}

}
