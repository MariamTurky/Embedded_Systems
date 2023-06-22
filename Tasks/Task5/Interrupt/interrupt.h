/*
 * interrupt.h
 *
 *  Created on: May 21, 2023
 *      Author: Mariam
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "Std_Types.h"
#include "Utils.h"

void Exti_Init(uint8 PortName, uint8 PinNum);
void Exti_Enable(uint8 PinNum);
void Exti_Disable(uint8 PinNum);
void clear_Flag(uint8 PinNum);

#endif /* INTERRUPT_H_ */
