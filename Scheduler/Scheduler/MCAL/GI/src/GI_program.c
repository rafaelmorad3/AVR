/*
 * GI_program.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Kareem Hussein
 */

/* UTILES_LIB */
#include "Std_Types.h"
#include "BitMath.h"

/* MCAL */
#include "GI_interface.h"
#include "GI_register.h"

void GI_voidEnable(void)
{
	SETBIT(SREG,I);
}


void GI_voidDisable(void)
{
   CLRBIT(SREG,I);	
}
