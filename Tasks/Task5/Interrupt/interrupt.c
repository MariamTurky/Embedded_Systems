/*
 * interrupt.c
 *
 *  Created on: May 21, 2023
 *      Author: Mariam
 */
#include "Bit_Operations.h"
#include "interrupt.h"
#include "Utils.h"
#include "Gpio.h"
#include "Rcc.h"

#define NVIC_ISER0 (*(uint32 *)0xE000E100)

typedef struct {
    uint32 IMR;     // Interrupt mask register
    uint32 EMR;     // Event mask register
    uint32 RTSR;    // Rising trigger selection register
    uint32 FTSR;    // Falling trigger selection register
    uint32 SWIER;   // Software interrupt event register
    uint32 PR;      // Pending registerv
} ExtiType;

#define EXTI ((ExtiType *)0x40013C00)

void Exti_Init(uint8 PortName, uint8 PinNum){

	Rcc_Enable(RCC_SYSCFG);          // enable SYSCFG

	Gpio_ConfigPin(PortName, PinNum, GPIO_INPUT, GPIO_PULL_UP);

	SET_BIT(EXTI->IMR, PinNum);        // enable extix

	SET_BIT(NVIC_ISER0, 6+PinNum);   // enable linex on nvic

	SET_BIT(EXTI->FTSR, PinNum);    // falling edge dectection

}
void Exti_Enable(uint8 PinNum){
	SET_BIT(EXTI->IMR, PinNum);    // enable extix

}
void Exti_Disable(uint8 PinNum){
	CLEAR_BIT(EXTI->IMR ,PinNum);   // disable extix

}

void clear_Flag(uint8 PinNum){
	SET_BIT(EXTI->PR, PinNum);  //clear pending flag

}
