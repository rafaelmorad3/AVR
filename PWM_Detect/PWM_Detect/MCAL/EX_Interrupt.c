#include "Std_Types.h"
#include "MemMap.h"
#include "BitMath.h"
#include "EX_Interrupt_Interface.h"

static void (*INT0_Fptr) (void)=NULL_PTR;
static void (*INT1_Fptr) (void)=NULL_PTR;
static void (*INT2_Fptr) (void)=NULL_PTR;


void EX_Interrpt_Init(void)
{
	ExInterrupt_TriggerEdge(EX_INT0,FALLING_EDGE);
	ExInterrupt_TriggerEdge(EX_INT1,FALLING_EDGE);
	ExInterrupt_TriggerEdge(EX_INT2,FALLING_EDGE);
}

void ExInterrupt_Enable(ExInterruptSource_type Interrupt)
{
	switch(Interrupt)
	{
		case EX_INT0:
		SETBIT(GICR,INT0);
		break;
		case EX_INT1:
		SETBIT(GICR,INT1);
		break;
		case EX_INT2:
		SETBIT(GICR,INT2);
		break;
	}
}

void ExInterrupt_Disable(ExInterruptSource_type Interrupt)
{
	switch(Interrupt)
	{
		case EX_INT0:
		CLRBIT(GICR,INT0);
		break;
		case EX_INT1:
		CLRBIT(GICR,INT1);
		break;
		case EX_INT2:
		CLRBIT(GICR,INT2);
		break;
	}
}

void ExInterrupt_TriggerEdge(ExInterruptSource_type Interrupt,TriggerEdge_type Edge)
{
	switch(Interrupt)
	{
		case EX_INT0:
		switch(Edge)
		{
			case LOW_LEVEL:
			CLRBIT(MCUCR,ISC00);
			CLRBIT(MCUCR,ISC01);
			break;
			case ANY_LOGICAL_CHANGE:
			SETBIT(MCUCR,ISC00);
			CLRBIT(MCUCR,ISC01);
			break;
			case FALLING_EDGE:
			CLRBIT(MCUCR,ISC00);
			SETBIT(MCUCR,ISC01);
			break;
			case RISING_EDGE:
			SETBIT(MCUCR,ISC00);
			SETBIT(MCUCR,ISC01);
			break;
		}
		break;
		case EX_INT1:
		switch(Edge)
		{
			case LOW_LEVEL:
			CLRBIT(MCUCR,ISC10);
			CLRBIT(MCUCR,ISC11);
			break;
			case ANY_LOGICAL_CHANGE:
			SETBIT(MCUCR,ISC10);
			CLRBIT(MCUCR,ISC11);
			break;
			case FALLING_EDGE:
			CLRBIT(MCUCR,ISC10);
			SETBIT(MCUCR,ISC11);
			break;
			case RISING_EDGE:
			SETBIT(MCUCR,ISC10);
			SETBIT(MCUCR,ISC11);
			break;
		}
		break;
		case EX_INT2:
		switch(Edge)
		{
			case FALLING_EDGE:
			CLRBIT(MCUCSR,ISC2);
			break;
			case RISING_EDGE:
			SETBIT(MCUCSR,ISC2);
			break;
			default:
			CLRBIT(MCUCSR,ISC2);
		}
		break;
	}
}

void ExInterrupt_SetCallBack(ExInterruptSource_type Interrupt,void(*LocalPtr)(void))
{
	switch(Interrupt)
	{
		case EX_INT0:
		INT0_Fptr=LocalPtr;
		break;
		case EX_INT1:
		INT1_Fptr=LocalPtr;
		break;
		case EX_INT2:
		INT2_Fptr=LocalPtr;
		break;
	}
}

ISR(INT0_vect)
{
	if (INT0_Fptr!=NULL_PTR)
	{
		INT0_Fptr();
	}
}

ISR(INT1_vect)
{
	if (INT1_Fptr!=NULL_PTR)
	{
		INT1_Fptr();
	}
}

ISR(INT2_vect)
{
	if (INT2_Fptr!=NULL_PTR)
	{
		INT2_Fptr();
	}
}

