/*
 * PWM_Detect.c
 *
 * Created: 11/12/2023 1:53:15 PM
 * Author : Lenovo
 */ 
#include "PWM_Detect.h"
#include <avr/io.h>


int main(void)
{
	PWM_Detect_Init();
    /* Replace with your application code */
    while (1) 
    {
		PWM_Detect();
    }
}

