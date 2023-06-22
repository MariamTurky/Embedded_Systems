/*************************************************************************************************
 * File Name :Gpio.c
 **************************************************************************************************/

#include "Gpio.h"

#include "Gpio_Private.h"
#include "Utils.h"
/******************************************************************************************************
 *                                Functions Definitions                                               *
 ******************************************************************************************************/
void Gpio_ConfigPin(uint8 PortName, uint8 PinNum, uint8 PinMode,
                    uint8 DefaultState, uint8 pullState) {
  switch (PortName) {
    case GPIO_A:
      GPIOA_MODER &= ~(0x03 << (PinNum * 2));
      GPIOA_MODER |= (PinMode << (PinNum * 2));
        if (PinMode == GPIO_OUTPUT){
          GPIOA_OTYPER &= ~(0x01 << PinNum);
          GPIOA_OTYPER |= (DefaultState << PinNum);
        }
        else if (PinMode == GPIO_INPUT){
        	GPIOA_PUPDR &= ~(0x01 << PinNum*2);
        	GPIOA_PUPDR |= (DefaultState << PinNum*2);
        }

      break;

    case GPIO_B:
      GPIOB_MODER &= ~(0x03 << (PinNum * 2));
      GPIOB_MODER |= (PinMode << (PinNum * 2));

       if (PinMode == GPIO_OUTPUT)
       {
           GPIOB_OTYPER &= ~(0x01 << PinNum);
           GPIOB_OTYPER |= (DefaultState << PinNum);
       }
       else if (PinMode == GPIO_INPUT)
       {
            GPIOB_PUPDR &= ~(0x01 << PinNum*2);
            GPIOB_PUPDR |= (DefaultState << PinNum*2);
       }
      break;

    case GPIO_C:
      GPIOC_MODER &= ~(0x03 << (PinNum * 2));
      GPIOC_MODER |= (PinMode << (PinNum * 2));

       if (PinMode == GPIO_OUTPUT)
        {
    	      GPIOC_OTYPER &= ~(0x01 << PinNum);
    	      GPIOC_OTYPER |= (DefaultState << PinNum);
        }
       else if (PinMode == GPIO_INPUT)
    	{
    	      GPIOC_PUPDR &= ~(0x01 << PinNum*2);
    	      GPIOC_PUPDR |= (DefaultState << PinNum*2);
    	}
    	break;
    case GPIO_D:
      GPIOD_MODER &= ~(0x03 << (PinNum * 2));
      GPIOD_MODER |= (PinMode << (PinNum * 2));

        if (PinMode == GPIO_OUTPUT)
    	   {
    	       GPIOD_OTYPER &= ~(0x01 << PinNum);
    	       GPIOD_OTYPER |= (DefaultState << PinNum);
    	   }
    	 else if (PinMode == GPIO_INPUT)
    	   {
    	       	GPIOD_PUPDR &= ~(0x01 << PinNum);
    	       	GPIOD_PUPDR |= (DefaultState << PinNum);
    	   }
    	break;
    default:
      break;
  }
}

uint8 Gpio_WritePin(uint8 PortName, uint8 PinNum, uint8 Data) {

	 //TODO: check if the pin is output
		switch (PortName){
			case GPIO_A:
			if ((GPIOA_MODER & (1 << ( PinNum* 2))))
//				if((GPIOA_MODER &(0x03 << (PinNum * 2))) >> (PinNum*2) != GPIO_OUTPUT)
			{
					GPIOA_ODR &= ~(0x1 << PinNum);
					GPIOA_ODR |= (Data << PinNum);
					return OK;
					}
					else {
						return NOK;
					}
		      break;
		    case GPIO_B:
			if ((GPIOB_MODER & (1 << ( PinNum* 2)))){
					GPIOB_ODR &= ~(0x1 << PinNum);
					GPIOB_ODR |= (Data << PinNum);
					return OK;
					}
					else {
						return NOK ;
					}

		      break;
		    case GPIO_C:
			if ((GPIOC_MODER & (1 << ( PinNum* 2)))){
					GPIOC_ODR &= ~(0x1 << PinNum);
					GPIOC_ODR |= (Data << PinNum);
					return OK;
					}
					else {
						return NOK;
					}

		      break;
		    case GPIO_D:
			if ((GPIOD_MODER & (1 << ( PinNum* 2)))){
					GPIOD_ODR &= ~(0x1 << PinNum);
					GPIOD_ODR |= (Data << PinNum);
					return OK;
					}
					else {
						return NOK;
					}

		      break;

		    default:
		      break;

		}

	}

uint8 Gpio_ReadPin(uint8 PortName, uint8 PinNum){
  uint8 data;

  switch (PortName)
  {
  case GPIO_A:
    data = (GPIOA_IDR & (1 << PinNum))? 1 : 0;
    break;

  case GPIO_B:
    data = (GPIOB_IDR & (1 << PinNum))? 1 : 0;
    break;

  case GPIO_C:
    data = (GPIOC_IDR & (1 << PinNum))? 1 : 0;
    break;

  case GPIO_D:
    data = (GPIOD_IDR & (1 << PinNum))? 1 : 0;
    break;

  default:
    break;
  }

  return data;
}





