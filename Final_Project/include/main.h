/*
 * main.h
 *
 *  Created on: April 12, 2023
 *  Author: MariamTurkey
 *
 *  Name: Mariam Ahmed Fathy
 *  SEC:2
 *  BN:30
 *
 */

// GPIOB address
#define GPIOB_BASE_ADDR  0x40020400

//Get Moder register address
#define GPIOB_MODER                    (*(unsigned long *)(GPIOB_BASE_ADDR + 0x00))

//Get Output type register address

#define GPIOB_OTYPER                   (*(unsigned long *)(GPIOB_BASE_ADDR + 0x04))

//Get Input type register address

#define GPIOB_PUPDR                    (*(unsigned long *)(GPIOB_BASE_ADDR + 0x0C))

//Get Output data register address
#define GPIOB_ODR                      (*(unsigned long *)(GPIOB_BASE_ADDR + 0x14))

//Get Input data register address

#define GPIOB_IDR                      (*(unsigned long *)(GPIOB_BASE_ADDR + 0x10))

//Rcc base address
#define	RCC_BASE 0x40023800

// Get AHB1EN Register address
#define RCC_AHB1ENR                    (*(unsigned long *) (RCC_BASE + 0x30))
