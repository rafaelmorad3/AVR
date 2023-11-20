﻿#include "Std_Types.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "LCD_CFG.h"
#include "BitMath.h"

#define  F_CPU  8000000
#include <util/delay.h>


#define LCD_CONFIG_WORD             (0x30)

#define LCD_CLR                     (0x01)

#define LCD_CURSOR_HOME             (0x02)

#define LCD_SET_ENTRY_MODE          (0x40)
#define LCD_INCREMENT_CURSOR        (0x02)
#define LCD_DECREMENT_CURSOR        (0x00)
#define LCD_DISPLAY_SHIFT_ON        (0x01)
#define LCD_DISPLAY_SHIFT_OFF       (0x00)

#define LCD_DISPLAY_CONTROL         (0x08)
#define LCD_DISPLAY_ON              (0x04)
#define LCD_DISPLAY_OFF             (0x00)
#define LCD_CURSOR_ON               (0x02)
#define LCD_CURSOR_OFF              (0x00)
#define LCD_CURSOR_BLINK_ON         (0x01)
#define LCD_CURSOR_BLINK_OFF        (0x00)

#define LCD_CURSOR_DISPLAY_CONTROL  (0x10)
#define LCD_SHIFT_CURSOR            (0x00)
#define LCD_SHIFT_DISPLAY           (0x08)
#define LCD_SHIFT_LEFT              (0x00)
#define LCD_SHIFT_RIGHT             (0x04)

#define LCD_FUNCTION_SET            (0x20)
#define LCD_DATA_LENGTH_4           (0x00)
#define LCD_DATA_LENGTH_8           (0x10)
#define LCD_ONE_LINE                (0x00)
#define LCD_TWO_LINES               (0x08)
#define LCD_SMALL_FONT              (0x00)
#define LCD_LARGE_FONT              (0x04)

#define LCD_SET_CGRAM_ADDRESS       (0x40)

#define LCD_SET_DDRAM_ADDRESS       (0x80)

#define LCD_DDRAM_LINE_SIZE         (0x28)
#define LCD_DDRAM_LINE_2_ADDRESS    (0x40)

static void LCD_SendCommand(u8 command);
static void LCD_SendData(u8 character);

void LCD_Init(void)
{
	/* Add your code here */
	/* Initialize Pins */
	
	
	_delay_ms(15);
	LCD_SendCommand(0x02);
	_delay_ms(2);
	LCD_SendCommand(0x28);
	_delay_ms(2);
	LCD_SendCommand(0x0c);
	LCD_SendCommand(0x06);
	LCD_SendCommand(0x01);
	_delay_ms(2);
	
	
	/* Initialization sequence */

	/* Initial LCD commands */
	/* Select data length = 8 bits, 2 lines LCD and small font */

	/* Turn display , cursor and blinking OFF */

	/* Clear LCD */

	/* Increment cursor and turn off display shift */

	/* Turn display ON */


	/* End of your code !*/
}
void LCD_SendChar(u8 ch)
{
	/* Add your code here */
	/* Change position and send character */
	LCD_SendData(ch);
	/* End of your code !*/

}

void LCD_SendString(char * str)
{
	u8 i;
	/* Add your code here */
	for (i=0;str[i];i++)
	{
		LCD_SendData(str[i]);
	}
	_delay_ms(10);
	/* Clear screen and send character by character to the LCD */

	/* End of your code !*/
}

static void LCD_SendCommand(u8 command)
{
	/* Add your code here */
	setpinvalue(RS,LOW);
	setpinvalue(D4,READBIT(command,4));
	setpinvalue(D5,READBIT(command,5));
	setpinvalue(D6,READBIT(command,6));
	setpinvalue(D7,READBIT(command,7));
	setpinvalue(EN,HIGH);
	_delay_ms(1);
	setpinvalue(EN,LOW);
	_delay_ms(1);
	setpinvalue(D4,READBIT(command,0));
	setpinvalue(D5,READBIT(command,1));
	setpinvalue(D6,READBIT(command,2));
	setpinvalue(D7,READBIT(command,3));
	setpinvalue(EN,HIGH);
	_delay_ms(1);
	setpinvalue(EN,LOW);
	_delay_ms(1);
	/* End of your code !*/

}

static void LCD_SendData(u8 character)
{
	/* Add your code here */
	setpinvalue(RS,HIGH);
	setpinvalue(D4,READBIT(character,4));
	setpinvalue(D5,READBIT(character,5));
	setpinvalue(D6,READBIT(character,6));
	setpinvalue(D7,READBIT(character,7));
	setpinvalue(EN,HIGH);
	_delay_ms(1);
	setpinvalue(EN,LOW);
	_delay_ms(1);
	setpinvalue(D4,READBIT(character,0));
	setpinvalue(D5,READBIT(character,1));
	setpinvalue(D6,READBIT(character,2));
	setpinvalue(D7,READBIT(character,3));
	setpinvalue(EN,HIGH);
	_delay_ms(1);
	setpinvalue(EN,LOW);
	_delay_ms(1);
	/* End of your code !*/
}

void LCD_GoTo(u8 line, u8 column)
{
	u8 address = 0;
	/* Calculate address in DDRAM */
	switch(line){
		case 0: address = (column); break;;
		case 1: address = (column+0x40); break;;
		case 2: address = (column+0x14); break;;
		case 3: address = (column+0x54); break;;
	}
	LCD_SendCommand(address|(0x80));
	/* Send address to LCD */

	/* End of your code !*/

}

void LCD_CustomChar(u8 address,u8*pattern)
{
	u8 i;
	LCD_SendCommand(0x40+(address*8));
	for(i=0;i<8;i++){
		LCD_SendData(pattern[i]);
	}
	LCD_SendCommand(0x80);
}

void LCD_Clear(void)
{
	LCD_SendCommand(0x01);
}


void LCD_writeNumber(s32 num)
{
	u32 n=0;
	u8 flag=0,rem=0;
	if(num<0){
		LCD_SendChar('-');
		num=num*(-1);
	}
	if(num==0){
		LCD_SendChar('0');
	}
	else{
		while(num){
			rem=num%10;
			if(n==0 && rem==0){
				flag++;
			}
			n=(n*10)+rem;
			num=num/10;
		}
		while(n){
			rem=n%10;
			LCD_SendChar('0'+rem);
			n=n/10;
		}
		while(flag){
			LCD_SendChar('0');
			flag--;
		}
	}
}