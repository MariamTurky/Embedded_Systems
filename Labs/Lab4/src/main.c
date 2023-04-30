#include "Gpio.h"
#include "Rcc.h"
#include "Std_Types.h"

int main() {
  Rcc_Init();
  Rcc_Enable(RCC_GPIOA);

  uint32 i = 0;
  for (i = 0; i < 7; i++) {
    Gpio_ConfigPin(GPIO_A, i, GPIO_OUTPUT, GPIO_PUSH_PULL);
  }
  uint8 counter = 0;
  while (1) {
	switch (counter)
	{
	case 0:
		Gpio_WritePin(GPIO_A, 0, HIGH);
		Gpio_WritePin(GPIO_A, 1, HIGH);
		Gpio_WritePin(GPIO_A, 2, HIGH);
		Gpio_WritePin(GPIO_A, 3, HIGH);
		Gpio_WritePin(GPIO_A, 4, HIGH);
		Gpio_WritePin(GPIO_A, 5, HIGH);
		Gpio_WritePin(GPIO_A, 6, LOW);
		break;
	
	case 1:
		Gpio_WritePin(GPIO_A, 0, LOW);
		Gpio_WritePin(GPIO_A, 1, HIGH);
		Gpio_WritePin(GPIO_A, 2, HIGH);
		Gpio_WritePin(GPIO_A, 3, LOW);
		Gpio_WritePin(GPIO_A, 4, LOW);
		Gpio_WritePin(GPIO_A, 5, LOW);
		Gpio_WritePin(GPIO_A, 6, LOW);
	break;

	// TODO: complete the remaining numbers
	case 2:
		Gpio_WritePin(GPIO_A, 0, HIGH);
		Gpio_WritePin(GPIO_A, 1, HIGH);
		Gpio_WritePin(GPIO_A, 2, LOW);
		Gpio_WritePin(GPIO_A, 3, HIGH);
		Gpio_WritePin(GPIO_A, 4, HIGH);
		Gpio_WritePin(GPIO_A, 5, LOW);
		Gpio_WritePin(GPIO_A, 6, HIGH);

	 break;


	 case 3:
		Gpio_WritePin(GPIO_A, 0, HIGH);
		Gpio_WritePin(GPIO_A, 1, HIGH);
		Gpio_WritePin(GPIO_A, 2, HIGH);
		Gpio_WritePin(GPIO_A, 3, HIGH);
		Gpio_WritePin(GPIO_A, 4, LOW);
		Gpio_WritePin(GPIO_A, 5, LOW);
		Gpio_WritePin(GPIO_A, 6, HIGH);

	 break;


	 case 4:
	 		Gpio_WritePin(GPIO_A, 0, LOW);
	 		Gpio_WritePin(GPIO_A, 1, HIGH);
	 		Gpio_WritePin(GPIO_A, 2, HIGH);
	 		Gpio_WritePin(GPIO_A, 3, LOW);
	 		Gpio_WritePin(GPIO_A, 4, LOW);
	 		Gpio_WritePin(GPIO_A, 5, HIGH);
	 		Gpio_WritePin(GPIO_A, 6, HIGH);

	 	 break;

	 case 5:
	 		Gpio_WritePin(GPIO_A, 0, HIGH);
	 		Gpio_WritePin(GPIO_A, 1, LOW);
	 		Gpio_WritePin(GPIO_A, 2, HIGH);
	 		Gpio_WritePin(GPIO_A, 3, HIGH);
	 		Gpio_WritePin(GPIO_A, 4, LOW);
	 		Gpio_WritePin(GPIO_A, 5, HIGH);
	 		Gpio_WritePin(GPIO_A, 6, HIGH);

	 	 break;

	 case 6:
	 		Gpio_WritePin(GPIO_A, 0, HIGH);
	 		Gpio_WritePin(GPIO_A, 1, LOW);
	 		Gpio_WritePin(GPIO_A, 2, HIGH);
	 		Gpio_WritePin(GPIO_A, 3, HIGH);
	 		Gpio_WritePin(GPIO_A, 4, HIGH);
	 		Gpio_WritePin(GPIO_A, 5, HIGH);
	 		Gpio_WritePin(GPIO_A, 6, HIGH);

	 	 break;
	 case 7:
	 		Gpio_WritePin(GPIO_A, 0, HIGH);
	 		Gpio_WritePin(GPIO_A, 1, HIGH);
	 		Gpio_WritePin(GPIO_A, 2, HIGH);
	 		Gpio_WritePin(GPIO_A, 3, LOW);
	 		Gpio_WritePin(GPIO_A, 4, LOW);
	 		Gpio_WritePin(GPIO_A, 5, LOW);
	 		Gpio_WritePin(GPIO_A, 6, LOW);

	 	 break;
	 case 8:
	 		Gpio_WritePin(GPIO_A, 0, HIGH);
	 		Gpio_WritePin(GPIO_A, 1, HIGH);
	 		Gpio_WritePin(GPIO_A, 2, HIGH);
	 		Gpio_WritePin(GPIO_A, 3, HIGH);
	 		Gpio_WritePin(GPIO_A, 4, HIGH);
	 		Gpio_WritePin(GPIO_A, 5, HIGH);
	 		Gpio_WritePin(GPIO_A, 6, HIGH);

	 	 break;
	 case 9:
		Gpio_WritePin(GPIO_A, 0, HIGH);
		Gpio_WritePin(GPIO_A, 1, HIGH);
		Gpio_WritePin(GPIO_A, 2, HIGH);
		Gpio_WritePin(GPIO_A, 3, HIGH);
		Gpio_WritePin(GPIO_A, 4, LOW);
		Gpio_WritePin(GPIO_A, 5, HIGH);
		Gpio_WritePin(GPIO_A, 6, HIGH);
	 break;
	default:
		break;
	}


	for(i=0 ; i <1000000;i++ ){

	}
	counter++;
	if(counter == 10){
		counter =0;
	}

  }

  // display numbers on 7 seg
  return 0;
}