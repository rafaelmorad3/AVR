/*
 * PWM_Detect.c
 *
 * Created: 11/12/2023 1:57:19 PM
 *  Author: Lenovo
 */ 
#include "PWM_Detect.h"







speed Speed;

void PWM_Detect_Init(void){
	DIO_INIT();
	Timer0_Init(TIMER0_FASTPWM_MODE,TIMER0_SCALER_1024);
	Timer0_OC0Mode(OC0_NON_INVERTING);
	OCR0=0;
	Timer1_Init(TIMER1_CTC_ICR_TOP_MODE,TIMER1_SCALER_256);
	Timer1_InputCaptureEdge(RISING);
	LCD_Init();
	KeyPad_Init();	
}
void PWM_Detect(void){
	u8 k = KeyPad_GetKey();
	u16 icu=0;
	if (k!='N')
	{
		if (k=='+')
		{
			if (Speed!=5)
			{
				Speed++;
				LCD_Clear();
				LCD_GoTo(0,0);
				LCD_SendString("update the speed & increment :");
				LCD_SendChar(Speed);
				OCR0= Speed*(1024/5);
			}
			
		}
		if (k=='-')
		{
			if (Speed!=0)
			{
				Speed--;
				LCD_Clear();
				LCD_GoTo(0,0);
				LCD_SendString("update the speed & decrement :");
				LCD_SendChar(Speed);
				OCR0= Speed*(1024/5);
			}
		}
	}
	icu = (ICR1H<<8)+ ICR1L;
	LCD_GoTo(2,0);
	LCD_SendString("update the ICU Number :");
	LCD_SendChar(icu);
	
}