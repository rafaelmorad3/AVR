/*
 * main.c
 *
 *  Created on: Nov 19, 2023
 *      Author: Kareem Hussein
 */


/* UTILES_LIB */
#include "Std_Types.h"
#include "BitMath.h"
#include "DIO_interface.h"

/* MCAL */
#include "RTOS_KERNEL_interface.h"

/* Tasks protoTypes */
void rLed(void);
void gLed(void);
void bLed(void);
void yLed(void);

int main()
{
	DIO_voidInit();
	RTOS_KERNEL_voidCreateTask(0,500 ,&rLed);
	RTOS_KERNEL_voidCreateTask(1,1000,&gLed);
	RTOS_KERNEL_voidCreateTask(2,2000,&bLed);
	RTOS_KERNEL_voidCreateTask(3,3000,&yLed);

	RTOS_KERNEL_voidStartScheduling();


	while(1)
	{

	}

	return 0;
}


/* Tasks implementation */
// task 0
void rLed(void)
{
	DIO_voidTogglePinValue(DIO_PORTB,DIO_PIN7);
}

// task 1
void gLed(void)
{
	DIO_voidTogglePinValue(DIO_PORTA,DIO_PIN4);
	RTOS_KERNEL_voidSuspendTask(0);
}

// task 2
void bLed(void)
{
	DIO_voidTogglePinValue(DIO_PORTA,DIO_PIN5);
	RTOS_KERNEL_voidDeletTask(2);
}

// task 3
void yLed(void)
{
	DIO_voidTogglePinValue(DIO_PORTA,DIO_PIN6);
	RTOS_KERNEL_voidResumeTask(0);
}
