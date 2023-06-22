/*
 * Gpt.h
 *
 *  Created on: Jun 18, 2023
 *      Author: Mariam Turky
 */

#ifndef GPT_H_
#define GPT_H_

#include "Std_Types.h"



#define TIM2	((Gptim2_5_dtype*)(0x40000000))
#define TIM3	((Gptim2_5_dtype*)(0x40000400))
#define TIM4	((Gptim2_5_dtype*)(0x40000800))
#define TIM5	((Gptim2_5_dtype*)(0x40000C00))

void GPT_Init(void);

void GPT_StartTimer(uint32 OverFlowTicks);

uint8 GPT_CheckTimeIsElapsed(void);

uint32 GPT_GetElapsedTime(void);

uint32 GPT_GetRemainingTime(void);



#endif /* GPT_H_ */
