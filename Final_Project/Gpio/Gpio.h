/*************************************************************************************************
 * File Name :Gpio.h
 **************************************************************************************************/

#ifndef GPIO_H
#define GPIO_H
#include "Std_Types.h"

/*PortName*/
#define GPIO_A 'A'
#define GPIO_B 'B'
#define GPIO_C 'C'
#define GPIO_D 'D'

/*PinNum*/
#define PIN_0 		0
#define PIN_1 		1
#define PIN_2 		2
#define PIN_3 		3
#define PIN_4 		4
#define PIN_5 		5
#define PIN_6 		6
#define PIN_7 		7

/*PinMode*/
#define GPIO_INPUT  0x00
#define GPIO_OUTPUT 0x01
#define GPIO_AF     0x02
#define GPIO_ANALOG 0x03

/*DefaultState*/
#define GPIO_PUSH_PULL  0x00
#define GPIO_OPEN_DRAIN 0x01


/*Data*/
#define LOW  0x00
#define HIGH 0x01

#define OK 0
#define NOK 1

void Gpio_ConfigPin(uint8 PortName, uint8 PinNum, uint8 PinMode, uint8 DefaultState, uint8 pullState);

uint8 Gpio_ReadPin(uint8 PortName, uint8 PinNum);

uint8 Gpio_WritePin(uint8 PortName, uint8 PinNum, uint8 Data);

#endif /* GPIO_H */
