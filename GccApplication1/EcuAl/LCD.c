/*
 * LCD.c
 *
 * Created: 23/10/22 10:54:14 AM
 *  Author: Raphael Mourad
 */ 
#include "LCD.h"

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
void send(u8 character);


void LCD_Init(void)
{
	/* Add your code here */
	/* Initialize Pins */
	SetPinDirection(Control_Port,EN,OUTPUT);
	SetPinDirection(Control_Port,RS,OUTPUT);
	SetPinDirection(PB,PIN0,OUTPUT);
	SetPinDirection(PB,PIN1,OUTPUT);
	SetPinDirection(PB,PIN2,OUTPUT);
	SetPinDirection(PB,PIN4,OUTPUT);
	/* Initialization sequence */
	Delay_ms(15);
	LCD_SendCommand(0x02);
	Delay_ms(2);
	LCD_SendCommand(0x28);
	Delay_ms(2);
	LCD_SendCommand(0x0c);
	LCD_SendCommand(0x06);
	LCD_Clear();
	Delay_ms(2);
	/* Initial LCD commands */
	/* Select data length = 8 bits, 2 lines LCD and small font */

	/* Turn display , cursor and blinking OFF */

	/* Clear LCD */
	

	/* Increment cursor and turn off display shift */

	/* Turn display ON */


	/* End of your code !*/
}
void LCD_SendChar(u8 character)
{
	/* Add your code here */
	/* Change position and send character */
	SetPinValue(Control_Port,RS,HIGH);
	LCD_SendData(character);
		
	/* End of your code !*/

}

void LCD_SendString(u8 * str)
{
	u8 i ;

	/* Add your code here */
	/* Clear screen *//*and send character by character to the LCD */
	LCD_SendCommand(LCD_CLR);
	/* set the line   */
	/*and send character by character to the LCD */
	for(i=0;str[i];i++)
	{
		LCD_SendChar(str[i]);
		
	}

	/* End of your code !*/
}

static void LCD_SendCommand(u8 command)
{
	/* Add your code here */
	SetPinValue(Control_Port,RS,LOW);
	LCD_SendData(command);
	
	/* End of your code !*/

}

static void LCD_SendData(u8 character)
{
	/* Add your code here */
	
	SetPinValue(PB,PIN0,GET_BIT(character,4));
	SetPinValue(PB,PIN1,GET_BIT(character,5));
	SetPinValue(PB,PIN2,GET_BIT(character,6));
	SetPinValue(PB,PIN4,GET_BIT(character,7));
	SetPinValue(Control_Port,EN,HIGH);
	Delay_ms(1);
	SetPinValue(Control_Port,EN,LOW);
	Delay_ms(1);
	SetPinValue(PB,PIN0,GET_BIT(character,0));
	SetPinValue(PB,PIN1,GET_BIT(character,1));
	SetPinValue(PB,PIN2,GET_BIT(character,2));
	SetPinValue(PB,PIN4,GET_BIT(character,3));
	SetPinValue(Control_Port,EN,HIGH);
	Delay_ms(1);
	SetPinValue(Control_Port,EN,LOW);
	Delay_ms(1);
	
	/* End of your code !*/
}

void LCD_GoTo(u8 line, u8 column)
{
	u8 address = 0;
	/* Calculate address in DDRAM */
	switch(line){
		case 0:address=(column);break;
		case 1:address=(column+0x40);break;
		case 2:address=(column+0x14);break;
		case 3:address=(column+0x54);break;		
	}
	/* Send address to LCD */
	LCD_SendCommand(address|LCD_SET_DDRAM_ADDRESS);
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
void LCD_Clear(void){
LCD_SendCommand(LCD_CLR);
}


