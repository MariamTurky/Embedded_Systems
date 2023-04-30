/*
 * main.c
 *
 *  Created on: April 12, 2023
 *  Author: MariamTurkey
 *
 *  Name: Mariam Ahmed Fathy
 *  SEC:2
 *  BN:30
 *
 */
#define GPIOA_BASE_ADDR  0x40020000


#define GPIOA_MODER      (*(unsigned long *)(GPIOA_BASE_ADDR + 0x00))
#define GPIOA_OTYPER     (*(unsigned long *)(GPIOA_BASE_ADDR + 0x04))
#define GPIOA_ODR        (*(unsigned long *)(GPIOA_BASE_ADDR + 0x14))

#define RCC_AHB1ENR      (*(unsigned long *) (0x40023800 + 0x30))
#define RCC_CR           (*(unsigned long *) (0x40023800 + 0x00))
int main(){

    RCC_CR |= (1 << 0);
	RCC_AHB1ENR  |= (1 << 0);  // enable clock on porta


	GPIOA_MODER &= ~(1 << 1 );
    GPIOA_MODER |= 1;

	GPIOA_OTYPER &= ~(1 << 0);

	GPIOA_ODR |= (1 << 0);
	unsigned long i = 0;
	while(1) {

		GPIOA_ODR |= (1 << 0);
		// wait 1s
		for(i = 0; i < 1000000; i++);

		GPIOA_ODR &= ~(1 << 0);
		// wait 1s
		for(i = 0; i < 1000000; i++);
	}

}