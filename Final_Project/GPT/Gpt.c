/*
 * Gpt.c
 *
 *  Created on: Jun 18, 2023
 *      Author: Mariam Turky
 */

#include "Bit_Operations.h"
#include "Gpt.h"
#include "Utils.h"
#include "Gpio.h"
#include "Rcc.h"
#include "stm32f401xe.h"
#include "STD_types.h"

volatile unsigned long int GPT_OverflowTicks = 0;
volatile unsigned char GPT_TimeIsElapsed = 0;
volatile unsigned long int GPT_ElapsedTime = 0;
typedef struct{
	uint32 CR1;
	uint32 CR2;
	uint32 SMCR;
	uint32 DIER;
	uint32 SR;
	uint32 EGR;
	uint32 CCMR1;
	uint32 CCMR2;
	uint32 CCER;
	uint32 CNT;
	uint32 PSC;
	uint32 ARR;
	uint32 RESERVED1;
	uint32 CCR1;
	uint32 CCR2;
	uint32 CCR3;
	uint32 CCR4;
	uint32 RESERVED2;
	uint32 DCR;
	uint32 DMAR;
}Gptim2_5_dtype;



void GPT_Init(void){

//	   CLEAR_BIT(TIM2->CR1, 4);
	   // enable the Update event generation
		CLEAR_BIT(TIM2->CR1, 1);
		// restrict the Update event generation to counter overflow/underflow events
//		SET_BIT(TIM2->CR1, 2);
		// enable the auto-reload preload (buffering)
		SET_BIT(TIM2->CR1, 7);
		// enable the Update event interrupt request
//		SET_BIT(TIM2->DIER, 0);
		// Set the prescaler value 16 M
		TIM2->PSC = 10999;

}

void GPT_StartTimer(uint32 OverFlowTicks){
	 // Set the number of overflow ticks before stopping
	    GPT_OverflowTicks = OverFlowTicks;
	    // Reset the time elapsed and overflow flags
	    GPT_ElapsedTime = 0;

	    TIM2->ARR = OverFlowTicks;
	    // Set the TIM2 counter to 0
	    TIM2->CNT = 0;
	    SET_BIT(TIM2->EGR, 0);
	    CLEAR_BIT(TIM2->SR, 0);
	    SET_BIT(TIM2->CR1, 0);

}

uint8 GPT_CheckTimeIsElapsed(void){
	if( READ_BIT( TIM2->SR, 0)){
				return 1;
			}
			return 0;

}

uint32 GPT_GetElapsedTime(void){

	if(GPT_CheckTimeIsElapsed()==1){
			return 0xffffffff;
		}
	else{
		if( READ_BIT( TIM2->CR1, 0)==1){
				// Return the time elapsed since the last call to GPT_StartTimer
				return TIM2->CNT ;
				}
				return 0;
		}
}

uint32 GPT_GetRemainingTime(void){
	if(GPT_CheckTimeIsElapsed()){
		return 0;
	}
	else{

		if (GPT_OverflowTicks == 0) {
				return 0xffffffff;
			}
		else {
				return (GPT_OverflowTicks - TIM2->CNT);
			}
	}
	}

