#define   F_CPU  16000000

#include "DIO.h"
#include "LCD.h"
#include "PushButton.h"
int main(void)
{
	INIT();
	LCD_Init();
	PushButton_INIT();
	u8 x=0;
	//u8 * ptr = "  Rapheal Mourad";
	//LCD_SendString(0, (u8*)"  Rapheal Mourad");
	/*SetPinDirection(PORTB,PIN0,OUTPUT);
	SetPinValue(PORTB,PIN0,HIGH);
	SetPinDirection(PORTB,PIN1,OUTPUT);
	SetPinValue(PORTB,PIN1,HIGH);
	*/
    while (1) 
    { x= PushButton_GET();
		if (x)
		{	LCD_GoTo(0,0);
			LCD_SendChar(x);
		}
		
		
    }
}

