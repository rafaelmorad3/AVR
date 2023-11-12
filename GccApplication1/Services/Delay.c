/*
 * Delay.c
 *
 * Created: 23/10/21 11:37:28 AM
 *  Author: Raphael Mourad
 */ 
#include "std_types.h"
#include "Delay.h"

void Delay_ms(u32 Value)
{
	u32 i;
	u32 count=(u32)(float)(Value-TM)/T1;
	
	for(i=0;i<count;i++)
	{
		
		asm("NOP");
		
	}
	
}