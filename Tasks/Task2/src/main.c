/*
 * main.c
 *
 *  Created on: April 12, 2023
 *  Author: MariamTurkey
 *
 *  Name: Mariam Ahmed Fathy
 *  SEC:2
 *  BN:30
 *
 */
#include "main.h"

#include<stdint.h>

int main(void)
{
	unsigned long count = 0;
	unsigned long i = 0;
	//Enable clock to GBIOB
	RCC_AHB1ENR |=(1<<1);

	// Set Mode to output of pins 5,6,7 GPIOB
	GPIOB_MODER |=(1<<10)|(1<<12)|(1<<14);
	GPIOB_MODER &=~((1<<11)|(1<<13)|(1<<15));

	//Set output Mode to (push-pull mode)  of pins 5,6,7 GPIOB
	GPIOB_OTYPER  &=~((1<<5)|(1<<6)|(1<<7));

    // Set Mode to input of pin 3 GPIOB
	GPIOB_MODER &=~((1<<6)|(1<<7));

    //Set input Mode to (pull-up mode)  of pin 3 GPIOB
	GPIOB_PUPDR |=(1<<6);
	GPIOB_PUPDR &=~(1<<7);

	// loop
	while(1)
	{
		for(i = 0; i < 100000; i++){} // delay

	    if(!(GPIOB_IDR & (1<<3))){
	    	count++;

	    	GPIOB_ODR  = (count<<5);

		    while(!(GPIOB_IDR & (1<<3)));

	    }

	}
	return 0;

}
