/*
 * RTOS_Timer_program.c
 *
 * Created: 11/19/2023 2:50:40 PM
 *  Author: Lenovo
 */ 
/*   Service */
#include "Std_Types.h"
#include "BitMath.h"
/*  RTOS */

#include "RTOS_Timer_Interface.h"
#include "RTOS_Timer_register.h"

static void (*prvivate_pCallBackCTC)(void)=NULL;
void RTOS_Timer_voidInit(void){
	
	/* select CTC mode   */
	CLRBIT(TCCR2,WGM20);
	SETBIT(TCCR2,WGM21);
	// Enable OC Interrupt
	SETBIT(TIMSK,OCIE2);
}
void RTOS_Timer_voidStart(void){
	
	CLRBIT(TCCR2,CS20);
	CLRBIT(TCCR2,CS21);
	SETBIT(TCCR2,CS22);
}
void RTOS_Timer_voidStop(void){
	
	CLRBIT(TCCR2,CS20);
	CLRBIT(TCCR2,CS21);
	CLRBIT(TCCR2,CS22);
}
void RTOS_Timer_voidSetCompareMatchValue(u8 copy_u8CompareValue){
	OCR2 =copy_u8CompareValue;
}
void RTOS_Timer_voidSetCallBackCTC(void(*ptrToFun)(void)){
	if(ptrToFun!=NULL){
	prvivate_pCallBackCTC=ptrToFun;
	}
}

void __vector_4(void) __attribute__((signal));
void __vector_4(void)
{
	if(prvivate_pCallBackCTC!=NULL){
		prvivate_pCallBackCTC();
	}
	
}