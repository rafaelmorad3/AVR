/*
 * Snake.c
 *
 * Created: 23/10/23 10:02:43 AM
 *  Author: Shiko
 */ 
#include "Std_Types.h"
#include "DIO.h"
#include "LCD.h"
#include "Snake.h"

#define  F_CPU  16000000
#include <util/delay.h>


static u8 customChar[8]={0x00,
	0x1F,
	0x1F,
	0x1F,
	0x1F,
	0x1F,
	0x1F,
0x00};
static u8 Places[5][2]={{0,4},{0,3},{0,2},{0,1},{0,0}};
static u8 i,flag=1;
Directions_t D=RIGHT,PAST_D=RIGHT;

void PushButton_Func(PINS PIN)
{
	u8 volt=HIGH;
	volt =GET_BIT(Button_Port,PIN);
	if (volt==LOW)
	{
		if (PIN==P0)
		{
			if (D!=DOWN)
			{
				D=UP;
			}
		}
		else if(PIN==P1){
			if (D!=UP)
			{
				D=DOWN;
			}
		}
		else if(PIN==P2){
			if (D!=RIGHT)
			{
				D=LEFT;
			}
		}
		else if(PIN==P3){
			if (D!=LEFT)
			{
				D=RIGHT;
			}
		}
	}
}

void SnakeDirection_Check(void)
{
	if (D==UP){
		for (i=4;i>0;i--)
		{
			Places[i][0]=Places[i-1][0];
			Places[i][1]=Places[i-1][1];
		}
		Places[i][0]=Places[1][0]-1;
		Places[i][1]=Places[1][1];
		if (Places[i][0]<0||Places[i][0]>3)
		{
			flag=0;
		}
	}
	else if(D==DOWN){
		for (i=4;i>0;i--)
		{
			Places[i][0]=Places[i-1][0];
			Places[i][1]=Places[i-1][1];
		}
		Places[i][0]=Places[1][0]+1;
		Places[i][1]=Places[1][1];
		if (Places[i][0]>3)
		{
			flag=0;
		}
	}
	else if(D==LEFT){
		for (i=4;i>0;i--)
		{
			Places[i][0]=Places[i-1][0];
			Places[i][1]=Places[i-1][1];
		}
		Places[i][0]=Places[1][0];
		Places[i][1]=Places[1][1]-1;
		if (Places[i][1]<0||Places[i][1]>19)
		{
			flag=0;
		}
	}
	else if(D==RIGHT){
		for (i=4;i>0;i--)
		{
			Places[i][0]=Places[i-1][0];
			Places[i][1]=Places[i-1][1];
		}
		Places[i][0]=Places[1][0];
		Places[i][1]=Places[1][1]+1;
		if (Places[i][1]>19)
		{
			flag=0;
		}
	}
}



void Snake_Init(void)
{
	LCD_CustomChar(0,customChar);
	Places[0][0]=0;
	Places[0][1]=4;
	Places[1][0]=0;
	Places[1][1]=3;
	Places[2][0]=0;
	Places[2][1]=2;
	Places[3][0]=0;
	Places[3][1]=1;
	Places[4][0]=0;
	Places[4][1]=0;
	for (s8 j=4;j>=0;j--)
	{
		LCD_GoTo(Places[j][0],Places[j][1]);
		LCD_SendChar(0);
		Delay_ms(250);
		
	}

}

void Snake_Runnable(void)
{
	LCD_GoTo(Places[4][0],Places[4][1]);
	LCD_SendChar(' ');
	
	SnakeDirection_Check();
	
	if (Places[0][0]==Places[4][0]&&Places[0][1]==Places[4][1])
	{
		flag=0;
	}
	if (!flag)
	{
		D=UP;
		while(D!=RIGHT){
			if (!flag)
			{
				LCD_Clear();
				LCD_GoTo(0,4);
				LCD_SendString((u8*)"Hello Loser");
				LCD_GoTo(2,0);
				LCD_SendString((u8*)"Press Right to play");
				flag=1;
			}
			PushButton_Func(P3);
		}
		LCD_Clear();
		Snake_Init();
	}
	for (i=0;i<5;i++)
	{
		LCD_GoTo(Places[i][0],Places[i][1]);
		LCD_SendChar(0);
	}
	PAST_D=D;
	for (i=0;i<250;i++)
	{
		Delay_ms(1);
		PushButton_Func(P0);
		PushButton_Func(P1);
		PushButton_Func(P2);
		PushButton_Func(P3);
		if (PAST_D!=D)
		{
			break;
		}
	}
}