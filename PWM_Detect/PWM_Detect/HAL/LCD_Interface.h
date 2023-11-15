

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "Std_Types.h"

void LCD_Init(void);
void LCD_SendChar(u8 ch);
void LCD_SendString(char * str);
void LCD_GoTo(u8 line, u8 column);
void LCD_CustomChar(u8 address,u8*pattern);
void LCD_Clear(void);
void LCD_writeNumber(s32 num);


#endif /* LCD_INTERFACE_H_ */