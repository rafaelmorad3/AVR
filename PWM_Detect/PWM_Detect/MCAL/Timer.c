#include "Std_Types.h"
#include "MemMap.h"
#include "BitMath.h"
#include "Timer_Interface.h"

static void (*Timer0_OVF_Fptr) (void)=NULL_PTR;
static void (*Timer0_OC0_Fptr) (void)=NULL_PTR;
static void (*Timer1_OVF_Fptr) (void)=NULL_PTR;
static void (*Timer1_OCA_Fptr) (void)=NULL_PTR;
static void (*Timer1_OCB_Fptr) (void)=NULL_PTR;
static void (*Timer1_ICU_Fptr) (void)=NULL_PTR;
static void (*Timer2_OVF_Fptr) (void)=NULL_PTR;
static void (*Timer2_OC2_Fptr) (void)=NULL_PTR;

void Timer0_Init(Timer0Mode_type mode,Timer0Scaler_type scaler)
{
	switch(mode)
	{
		case TIMER0_NORMAL_MODE :
		CLRBIT(TCCR0,WGM00);
		CLRBIT(TCCR0,WGM01);
		break;
		case TIMER0_CTC_MODE :
		CLRBIT(TCCR0,WGM00);
		SETBIT(TCCR0,WGM01);
		break;
		case TIMER0_PHASECORRECT_MODE :
		SETBIT(TCCR0,WGM00);
		CLRBIT(TCCR0,WGM01);
		break;
		case TIMER0_FASTPWM_MODE :
		SETBIT(TCCR0,WGM00);
		SETBIT(TCCR0,WGM01);
		break;
	}
	
	TCCR0&=0xF8;
	scaler&=0x07;
	TCCR0|=scaler;
	
	CLRBIT(TIFR,TOV0);
	
}

void Timer0_OC0Mode(OC0Mode_type mode)
{
	switch(mode)
	{
		case OC0_DISCONNECTED :
		CLRBIT(TCCR0,COM00);
		CLRBIT(TCCR0,COM01);
		break;
		case OC0_TOGGLE :
		SETBIT(TCCR0,COM00);
		CLRBIT(TCCR0,COM01);
		break;
		case OC0_NON_INVERTING :
		CLRBIT(TCCR0,COM00);
		SETBIT(TCCR0,COM01);
		break;
		case OC0_INVERTING :
		SETBIT(TCCR0,COM00);
		SETBIT(TCCR0,COM01);
		break;
	}
}


void Timer0_OVF_InterruptEnable(void)
{
	SETBIT(TIMSK,TOIE0);
}

void Timer0_OVF_InterruptDisable(void)
{
	CLRBIT(TIMSK,TOIE0);
}

void Timer0_OC0_InterruptEnable(void)
{
	SETBIT(TIMSK,OCIE0);
}

void Timer0_OC0_InterruptDisable(void)
{
	CLRBIT(TIMSK,OCIE0);
}

void TIMER0_OVF_SetCallBack(void(*local_fptr)(void))
{
	Timer0_OVF_Fptr=local_fptr;
}

void TIMER0_OC0_SetCallBack(void(*local_fptr)(void))
{
	Timer0_OC0_Fptr=local_fptr;
}

ISR(TIMER0_OVF_vect)
{
	if (Timer0_OVF_Fptr!=NULL_PTR)
	{
		Timer0_OVF_Fptr();
	}
}

ISR(TIMER0_OC_vect)
{
	if (Timer0_OC0_Fptr!=NULL_PTR)
	{
		Timer0_OC0_Fptr();
	}
}


/*************************************************************************/
/*timer 1 functions*/
void Timer1_Init( Timer1Mode_type mode,Timer1Scaler_type scaler)
{
	switch (mode)
	{
		case TIMER1_NORMAL_MODE:
		CLRBIT(TCCR1A,WGM10);
		CLRBIT(TCCR1A,WGM11);
		CLRBIT(TCCR1B,WGM12);
		CLRBIT(TCCR1B,WGM13);
		break;
		case TIMER1_CTC_ICR_TOP_MODE:
		CLRBIT(TCCR1A,WGM10);
		CLRBIT(TCCR1A,WGM11);
		SETBIT(TCCR1B,WGM12);
		SETBIT(TCCR1B,WGM13);
		break;
		
		case TIMER1_CTC_OCRA_TOP_MODE:
		CLRBIT(TCCR1A,WGM10);
		CLRBIT(TCCR1A,WGM11);
		SETBIT(TCCR1B,WGM12);
		CLRBIT(TCCR1B,WGM13);
		break;
		
		case TIMER1_FASTPWM_ICR_TOP_MODE:
		CLRBIT(TCCR1A,WGM10);
		SETBIT(TCCR1A,WGM11);
		SETBIT(TCCR1B,WGM12);
		SETBIT(TCCR1B,WGM13);
		break;
		
		case TIMER1_FASTPWM_OCRA_TOP_MODE:
		SETBIT(TCCR1A,WGM10);
		SETBIT(TCCR1A,WGM11);
		SETBIT(TCCR1B,WGM12);
		SETBIT(TCCR1B,WGM13);
		break;
	}

	TCCR1B&=0XF8;
	TCCR1B|=scaler;

}
void Timer1_OCRA1Mode(OC1A_Mode_type oc1a_mode)
{
	switch (oc1a_mode)
	{
		case OCRA_DISCONNECTED:
		CLRBIT(TCCR1A,COM1A0);
		CLRBIT(TCCR1A,COM1A1);
		break;
		case OCRA_TOGGLE:
		SETBIT(TCCR1A,COM1A0);
		CLRBIT(TCCR1A,COM1A1);
		break;
		case OCRA_NON_INVERTING:
		CLRBIT(TCCR1A,COM1A0);
		SETBIT(TCCR1A,COM1A1);
		break;
		case OCRA_INVERTING:
		SETBIT(TCCR1A,COM1A0);
		SETBIT(TCCR1A,COM1A1);
		break;
	}
}
void Timer1_OCRB1Mode(OC1B_Mode_type oc1b_mode)
{
	switch (oc1b_mode)
	{
		case OCRB_DISCONNECTED:
		CLRBIT(TCCR1A,COM1B0);
		CLRBIT(TCCR1A,COM1B1);
		break;
		case OCRB_TOGGLE:
		SETBIT(TCCR1A,COM1B0);
		CLRBIT(TCCR1A,COM1B1);
		break;
		case OCRB_NON_INVERTING:
		CLRBIT(TCCR1A,COM1B0);
		SETBIT(TCCR1A,COM1B1);
		break;
		case OCRB_INVERTING:
		SETBIT(TCCR1A,COM1B0);
		SETBIT(TCCR1A,COM1B1);
		break;
	}
}
void Timer1_InputCaptureEdge(ICU_Edge_type edge)
{
	if(edge==RISING)
	SETBIT(TCCR1B,ICES1);
	
	else if(edge==FALLING)
	CLRBIT(TCCR1B,ICES1);
}


/****************************Timer 1 Interrupt functions**************************************/

void Timer1_ICU_InterruptEnable(void)
{
	SETBIT(TIMSK,TICIE1);
}
void Timer1_ICU_InterruptDisable(void)
{
	CLRBIT(TIMSK,TICIE1);
}
void Timer1_OVF_InterruptEnable(void)
{
	SETBIT(TIMSK,TOIE1);
}
void Timer1_OVF_InterruptDisable(void)
{
	CLRBIT(TIMSK,TOIE1);
}
void Timer1_OCA_InterruptEnable(void)
{
	SETBIT(TIMSK,OCIE1A);
}
void Timer1_OCA_InterruptDisable(void)
{
	CLRBIT(TIMSK,OCIE1A);
}
void Timer1_OCB_InterruptEnable(void)
{
	SETBIT(TIMSK,OCIE1B);
}
void Timer1_OCB_InterruptDisable(void)
{
	CLRBIT(TIMSK,OCIE1B);
}

/*********************************Timer 1 Call Back functions*****************************************/

void Timer1_OVF_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OVF_Fptr=LocalFptr;
}
void Timer1_OCA_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OCA_Fptr=LocalFptr;
}
void Timer1_OCB_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OCB_Fptr=LocalFptr;
}
void Timer1_ICU_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_ICU_Fptr=LocalFptr;
}

/*********************************Timer 1 ISR functions*********************************************/
ISR(TIMER1_OVF_vect)
{
	if(Timer1_OVF_Fptr!=NULL_PTR)
	{
		Timer1_OVF_Fptr();
	}
}
ISR(TIMER1_OCA_vect)
{
	if(Timer1_OCA_Fptr!=NULL_PTR)
	{
		Timer1_OCA_Fptr();
	}
}
ISR(TIMER1_OCB_vect)
{
	if(Timer1_OCB_Fptr!=NULL_PTR)
	{
		Timer1_OCB_Fptr();
	}
}
ISR(TIMER1_ICU_vect)
{
	if(Timer1_ICU_Fptr!=NULL_PTR)
	{
		Timer1_ICU_Fptr();
	}
}

/******************************************************************************************/
/*timer 2 functions*/
void TIMER2_Init(Timer2Mode_type mode,Timer2Scaler_type scaler)
{
	switch (mode)
	{
		case TIMER2_NORMAL_MODE:
		CLRBIT(TCCR2,WGM20);
		CLRBIT(TCCR2,WGM21);
		break;
		case TIMER2_PHASECORRECT_MODE:
		SETBIT(TCCR2,WGM20);
		CLRBIT(TCCR2,WGM21);
		break;
		case TIMER2_CTC_MODE:
		CLRBIT(TCCR2,WGM20);
		SETBIT(TCCR2,WGM21);
		break;
		case TIMER2_FASTPWM_MODE:
		SETBIT(TCCR2,WGM20);
		SETBIT(TCCR2,WGM21);
		break;
	}
	TCCR2&=0XF8;//0b11111000
	TCCR2|=scaler;
}

void TIMER2_OC2Mode(OC2Mode_type mode)
{
	switch (mode)
	{
		case OC2_DISCONNECTED:
		CLRBIT(TCCR2,COM20);
		CLRBIT(TCCR2,COM21);
		break;
		case OC2_TOGGLE:
		SETBIT(TCCR2,COM20);
		CLRBIT(TCCR2,COM21);
		break;
		case OC2_NON_INVERTING:
		CLRBIT(TCCR2,COM20);
		SETBIT(TCCR2,COM21);
		break;
		case OC2_INVERTING:
		SETBIT(TCCR2,COM20);
		SETBIT(TCCR2,COM21);
		break;
	}
}

void TIMER2_OV_InterruptEnable(void)
{
	SETBIT(TIMSK,TOIE2);
}
void TIMER2_OV_InterruptDisable(void)
{
	CLRBIT(TIMSK,TOIE2);
}
void TIMER2_OC_InterruptEnable(void)
{
	SETBIT(TIMSK,OCIE2);
}
void TIMER2_OC_InterruptDisable(void)
{
	CLRBIT(TIMSK,OCIE2);
}

/*********************************Timer 2 Call Back functions*****************************************/

void TIMER2_OVF_SetCallBack(void(*LocalFptr)(void))
{
	Timer2_OVF_Fptr=LocalFptr;
}
void TIMER2_OC2_SetCallBack(void(*LocalFptr)(void))
{
	Timer2_OC2_Fptr=LocalFptr;
}

/*********************************Timer 2 ISR functions*********************************************/

ISR(TIMER2_OVF_vect)
{
	if(Timer2_OVF_Fptr!=NULL_PTR)
	{
		Timer2_OVF_Fptr();
	}
}
ISR(TIMER2_OC_vect)
{
	if(Timer2_OC2_Fptr!=NULL_PTR)
	{
		Timer2_OC2_Fptr();
	}
}

