/**
 * Gpio.c
 *
 *  Created on: Tue Apr 11 2023
 *  Author    : Abdullah Darwish
 */

#include "Gpio.h"

#include "Gpio_Private.h"
#include "Utils.h"

void Gpio_ConfigPin(uint8 PortName, uint8 PinNum, uint8 PinMode,
                    uint8 DefaultState) {
  switch (PortName) {
    case GPIO_A:
      GPIOA_MODER &= ~(0x03 << (PinNum * 2));
      GPIOA_MODER |= (PinMode << (PinNum * 2));

      GPIOA_OTYPER &= ~(0x01 << PinNum);
      GPIOA_OTYPER |= (DefaultState << PinNum);

      break;
    case GPIO_B:
      GPIOB_MODER &= ~(0x03 << (PinNum * 2));
      GPIOB_MODER |= (PinMode << (PinNum * 2));

      GPIOB_OTYPER &= ~(0x01 << PinNum);
      GPIOB_OTYPER |= (DefaultState << PinNum);
      break;
    case GPIO_C:
      // TODO:
      GPIOC_MODER &= ~(0x03 << (PinNum * 2));
	  GPIOC_MODER |= (PinMode << (PinNum * 2));

	  GPIOC_OTYPER &= ~(0x01 << PinNum);
	  GPIOC_OTYPER |= (DefaultState << PinNum);
      break;
    case GPIO_D:
      // TODO:
      GPIOD_MODER &= ~(0x03 << (PinNum * 2));
	  GPIOD_MODER |= (PinMode << (PinNum * 2));

	  GPIOD_OTYPER &= ~(0x01 << PinNum);
	  GPIOD_OTYPER |= (DefaultState << PinNum);
      break;
//    default:
//      break;
  }
}

uint8 Gpio_WritePin(uint8 PortName, uint8 PinNum, uint8 Data) {

 //TODO: check if the pin is output
	uint8 result ;
  switch (PortName) {
    case GPIO_A:
    	if((GPIOA_MODER & (0x03 << 2*PinNum)) >> (2*PinNum) == 1)
    				    {
    			     	     if(Data)
    				         {
    			     	     GPIOA_ODR |= (Data << PinNum);
    			    	     }
    			    	     else
    			    	     {
    			    	    	 GPIOA_ODR &= ~(0x1 << PinNum);
    				         }
    				     	result = OK;
    		     		}
    			    	else
    			    	{
    				    	result = NOK;
    		    		}

//      GPIOA_ODR &= ~(0x1 << PinNum);
//      GPIOA_ODR |= (Data << PinNum);
      break;
    case GPIO_B:
    	if((GPIOB_MODER & (0x03 << 2*PinNum)) >> (2*PinNum) == 1)
    	    				    {
    	    			     	     if(Data)
    	    				         {
    	    			     	     GPIOB_ODR |= (Data << PinNum);
    	    			    	     }
    	    			    	     else
    	    			    	     {
    	    			    	    	 GPIOB_ODR &= ~(0x1 << PinNum);
    	    				         }
    	    				     	result = OK;
    	    		     		}
    	    			    	else
    	    			    	{
    	    				    	result = NOK;
    	    		    		}
//      GPIOB_ODR &= ~(0x1 << PinNum);
//      GPIOB_ODR |= (Data << PinNum);
      break;
    case GPIO_C:
      // TODO:
    	if((GPIOC_MODER & (0x03 << 2*PinNum)) >> (2*PinNum) == 1)
    	    				    {
    	    			     	     if(Data)
    	    				         {
    	    			     	     GPIOC_ODR |= (Data << PinNum);
    	    			    	     }
    	    			    	     else
    	    			    	     {
    	    			    	    	 GPIOC_ODR &= ~(0x1 << PinNum);
    	    				         }
    	    				     	result = OK;
    	    		     		}
    	    			    	else
    	    			    	{
    	    				    	result = NOK;
    	    		    		}
//      GPIOC_ODR &= ~(0x1 << PinNum);
//      GPIOC_ODR |= (Data << PinNum);
      break;
    case GPIO_D:
      // TODO:
    	if((GPIOD_MODER & (0x03 << 2*PinNum)) >> (2*PinNum) == 1)
    	    				    {
    	    			     	     if(Data)
    	    				         {
    	    			     	     GPIOD_ODR |= (Data << PinNum);
    	    			    	     }
    	    			    	     else
    	    			    	     {
    	    			    	    	 GPIOD_ODR &= ~(0x1 << PinNum);
    	    				         }
    	    				     	result = OK;
    	    		     		}
    	    			    	else
    	    			    	{
    	    				    	result = NOK;
    	    		    		}
//	  GPIOD_ODR &= ~(0x1 << PinNum);
//    GPIOD_ODR |= (Data << PinNum);
      break;
//    default:
//      break;
  }//end switch
  return result ;
}

uint8 Gpio_ReadPin(uint8 PortName, uint8 PinNum)
{
	uint8 result;

		switch(PortName)
		{
		case GPIO_A:
		      result = ((GPIOA_IDR >> PinNum) & 0x01);
		      break;
		    case GPIO_B:
		    	result = ((GPIOB_IDR >> PinNum) & 0x01);
		      break;
		    case GPIO_C:
		      // TODO:
		    	result = ((GPIOC_IDR >> PinNum) & 0x01);
		      break;
		    case GPIO_D:
		      // TODO:
		    	result = ((GPIOD_IDR >> PinNum) & 0x01);
		      break;
		}

		return result;
}

