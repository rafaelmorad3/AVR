/*
 * LCD.h
 *
 * Created: 23/10/22 10:53:52 AM
 *  Author: Raphael Mourad
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "BitMath.h"
#include "DIO.h"
#include "Std_types.h"
#define LCD_LINE_1          (0)
#define LCD_LINE_2          (1)
#define LCD_LINE_WIDTH      (16)
#define Control_Port PA
#define EN PIN2
#define RS PIN3
void LCD_Init(void);
void LCD_SendChar(u8 character);
void LCD_SendString( u8 * str);
void LCD_GoTo(u8 line, u8 column);
void LCD_Clear(void);
void LCD_CustomChar(u8 address,u8*pattern);


#endif /* LCD_H_ */