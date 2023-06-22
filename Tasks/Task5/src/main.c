#include "Bit_Operations.h"
#include "Std_Types.h"
#include "Rcc.h"
#include "Gpio.h"
#include "interrupt.h"
uint32 counter = 0;
unsigned char sevenSegHex[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,0x6D, 0x7D, 0x07, 0x7F, 0x6F};
int main() {
	Rcc_Init();
	Rcc_Enable(RCC_GPIOA);
	Rcc_Enable(RCC_GPIOB);

	Exti_Init(GPIO_A, 0);
	Exti_Init(GPIO_A, 1);

    uint32 i = 0;
    for (i = 0; i < 7; i++) {
	  Gpio_ConfigPin(GPIO_B, i, GPIO_OUTPUT, GPIO_PUSH_PULL);
    }


	while (1) {
	}
	return 0;
}

void EXTI0_IR(void) {

	Exti_Disable(1);
	for (int i = 0; i < 7; i++) {
		Gpio_WritePin(GPIO_B, i, (sevenSegHex[counter] & (1 << i))>> i);
		}
	counter = (counter == 9) ? 9 : counter +1;

	for (int i = 0; i < 1000000; i++) {
	}

	//clear pending flag
	clear_Flag(0);
	Exti_Enable(1);
}

void EXTI1_IR(void) {

	Exti_Disable(0);
	counter = (counter == 0) ? 0 : counter - 1;
	for (int i = 0; i < 7; i++) {
		Gpio_WritePin(GPIO_B, i, (sevenSegHex[counter] & (1 << i))>> i);
		}

	for (int i = 0; i < 1000000; i++) {
	}

	clear_Flag(1);

	Exti_Enable(0);

}
