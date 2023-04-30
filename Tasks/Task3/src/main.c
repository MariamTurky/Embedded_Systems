#include "Gpio.h"
#include "Rcc.h"
#include "Std_Types.h"

int main() {
  Rcc_Init();
  Rcc_Enable(RCC_GPIOB);

  uint32 i = 0;
  for (i = 5; i < 8; i++) {
    Gpio_ConfigPin(GPIO_B, i, GPIO_OUTPUT, GPIO_PUSH_PULL);
  }
  Gpio_ConfigPin(GPIO_B, 3, GPIO_INPUT, GPIO_PULL_UP);
  uint8 counter = 0;
  while (1) {


  	  	  if (!(Gpio_ReadPin(GPIO_B, 3)))
  	  	  {

  	  	switch (counter)
  	  		  {
  	  		      case 0:

  	  		            	Gpio_WritePin(GPIO_B, 5, HIGH);
  	  		            	Gpio_WritePin(GPIO_B, 6, LOW);
  	  		            	Gpio_WritePin(GPIO_B, 7, LOW);

  	  		            break;

  	  		      case 1:

  	  		      	    Gpio_WritePin(GPIO_B, 5, LOW);
  	  		      	    Gpio_WritePin(GPIO_B, 6, HIGH);
  	  		      	    Gpio_WritePin(GPIO_B, 7, LOW);


  	  		      	    break;

  	  		      case 2:

  	  		      	    Gpio_WritePin(GPIO_B, 5,HIGH);
  	  		      	    Gpio_WritePin(GPIO_B, 6, HIGH);
  	  		      	    Gpio_WritePin(GPIO_B, 7, LOW);


  	  		      	    break;

  	  		      case 3:

  	  		      	    Gpio_WritePin(GPIO_B, 5, LOW);
  	  		      	    Gpio_WritePin(GPIO_B, 6, LOW);
  	  		      	    Gpio_WritePin(GPIO_B, 7,HIGH);


  	  		      	    break;

  	  		      case 4:

  	  		      	    Gpio_WritePin(GPIO_B, 5,HIGH);
  	  		        	Gpio_WritePin(GPIO_B, 6, LOW);
  	  		        	Gpio_WritePin(GPIO_B, 7,HIGH);


  	  		      	    break;

  	  		      case 5:

  	  		      	    Gpio_WritePin(GPIO_B, 5, LOW);
  	  		      	    Gpio_WritePin(GPIO_B, 6,HIGH);
  	  		      	    Gpio_WritePin(GPIO_B, 7,HIGH);


  	  		      	    break;

  	  		      case 6:

  	  		      	    Gpio_WritePin(GPIO_B, 5,HIGH);
  	  		      	    Gpio_WritePin(GPIO_B, 6,HIGH);
  	  		      	    Gpio_WritePin(GPIO_B, 7,HIGH);


  	  		      	    break;

  	  		      case 7:

  	  		      	    Gpio_WritePin(GPIO_B, 5, LOW);
  	  		      	    Gpio_WritePin(GPIO_B, 6, LOW);
  	  		      	    Gpio_WritePin(GPIO_B, 7, LOW);


  	  		      	    break;


  	  		  }
  	  		      	for(i=0 ; i <1000000;i++ ){}
  	  		      		counter++;
  	  		      		if(counter == 8){
  	  		      			counter =0;
  	  		      		}
  	  		      	while(!(Gpio_ReadPin(GPIO_B, 3))) {}
  	  	  }
  	  		      	  }

  	  		      	}
