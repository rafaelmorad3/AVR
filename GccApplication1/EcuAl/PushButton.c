/*
 * PushButton.c
 *
 * Created: 23/10/23 10:24:37 AM
 *  Author: Shiko
 */ 
#include "PushButton.h"

static const u8 KPD_Au8Key[4][4]=KPD_u8_KEYS;

static const u8 KPD_Au8RowsPins[4]={KPD_u8_R1_PIN,KPD_u8_R2_PIN,KPD_u8_R3_PIN,KPD_u8_R4_PIN};

static const u8 KPD_Au8ColsPins[4]={KPD_u8_C1_PIN,KPD_u8_C2_PIN,KPD_u8_C3_PIN,KPD_u8_C4_PIN};

u8 KPD_u8GetKeyState(u8* Copy_pu8ReturnedKey)
{

	u8 Local_u8RowCounter;
	u8 Local_u8ColCounter;
	u8 Local_u8PinValue;
	u8 Local_u8Flag = 0;
	if(Copy_pu8ReturnedKey != NULL)
	{
		*Copy_pu8ReturnedKey =KPD_u8_KEY_NOT_PRESSED;
		for(Local_u8RowCounter=0 ;Local_u8RowCounter<=3 ;Local_u8RowCounter++)
		{
			SetPinValue(KPD_u8_ROW_PORT,KPD_Au8RowsPins[Local_u8RowCounter],LOW);
			for(Local_u8ColCounter=0 ;Local_u8ColCounter<=3 ;Local_u8ColCounter++)
			{
				Local_u8PinValue=GET_BIT(KPD_u8_COL_PORT,KPD_Au8ColsPins[Local_u8ColCounter]);
				if(Local_u8PinValue == LOW)
				{
					_delay_ms(20);

					Local_u8PinValue=GET_BIT(KPD_u8_COL_PORT,KPD_Au8ColsPins[Local_u8ColCounter]);
					while(Local_u8PinValue == LOW)
					{
						Local_u8PinValue=GET_BIT(KPD_u8_COL_PORT,KPD_Au8ColsPins[Local_u8ColCounter]);
					}
					*Copy_pu8ReturnedKey = KPD_Au8Key[Local_u8RowCounter][Local_u8ColCounter];
					Local_u8Flag = 1;
					break;
				}
			}
			SetPinValue(KPD_u8_ROW_PORT,KPD_Au8RowsPins[Local_u8RowCounter],HIGH);
			if(Local_u8Flag == 1)
			{
				break;
			}
		}
	}

	return ERROR_NOK;

}


/*static u8 CheckLoop (void);
void  PushButton_INIT(void){
	
	SetPinDirection(CP,COL1,INPUT);
	SetPinDirection(CP,COL2,INPUT);
	SetPinDirection(CP,COL3,INPUT);
	SetPinDirection(CP,COL4,INPUT);
	SetPinDirection(RP,ROW1,OUTPUT);
	SetPinDirection(RP,ROW2,OUTPUT);
	SetPinDirection(RP,ROW3,OUTPUT);
	SetPinDirection(RP,ROW4,OUTPUT);	
	SetPinValue(RP,ROW1,HIGH);
	SetPinValue(RP,ROW2,HIGH);
	SetPinValue(RP,ROW3,HIGH);
	SetPinValue(RP,ROW4,HIGH);

}
u8  PushButton_GET(void){
		u8 num=0;
		for(u8 i = 0;i<4;i++){
		switch(i)
		{
		case 0:
		SetPinValue(RP,ROW1,LOW);
		Delay_ms(1);
		if(5>CheckLoop()){
			num =CheckLoop()+i*4;
		}
		SetPinValue(RP,ROW1,HIGH);
		break;
		case 1:
		SetPinValue(RP,ROW2,LOW);
		Delay_ms(1);
		if(5>CheckLoop()){
			num =CheckLoop()+i*4;
		}
		SetPinValue(RP,ROW2,HIGH);
		break;
		case 2:
		SetPinValue(RP,ROW3,LOW);
		Delay_ms(1);
		if(5>CheckLoop()){
			num =CheckLoop()+i*4;
		}
		SetPinValue(RP,ROW3,HIGH);
		break;
		case 3:
		SetPinValue(RP,ROW3,LOW);
		Delay_ms(1);
		if(5>CheckLoop()){
			num =CheckLoop()+i*4;
		}
		SetPinValue(RP,ROW4,HIGH);
		break;
		}
		}
		return num;
}

static u8 CheckLoop (void){
	u8 temp=0xFF;
	if (LOW==GET_BIT(CP,COL1))
	{
		temp=1;
	
	}
	else if(LOW==GET_BIT(CP,COL2)){
		temp=2;
		}
	else if(LOW==GET_BIT(CP,COL3)){
			temp=3;
		}
	else if(LOW==GET_BIT(CP,COL4)){
			temp = 4;
		}
	return temp;
	}
	*/