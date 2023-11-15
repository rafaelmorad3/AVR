#define KEYPAD_PRG   1

#include "Std_Types.h"
#include "DIO_Interface.h"
#include "KeyPad_Interface.h"
#include "KeyPad_CFG.h"

#define  F_CPU  16000000
#include <util/delay.h>


void KeyPad_Init(void)
{
	u8 r;
	for (r=0;r<ROWS;r++)
	{
		setpinvalue(FIRST_OUTPUT-r,HIGH);
	}
}

u8 KeyPad_GetKey(void)
{
	u8 r,c,key=NO_KEY,NUM=NO_KEY;
	for (r=0;r<ROWS;r++)
	{
		setpinvalue(FIRST_OUTPUT-r,LOW);
		for (c=0;c<COLS;c++)
		{
			getpinvalue(Col_ARR[c],&NUM);
			if (NUM==LOW)
			{
				key=KeysARR[r][c];
				_delay_ms(10);
				while(NUM==LOW){
					getpinvalue(Col_ARR[c],&NUM);
				}
			}
		}
		setpinvalue(FIRST_OUTPUT-r,HIGH);
	}
	return key;
}

