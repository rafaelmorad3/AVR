/*
 * cyber_security.c
 *
 * Created: 11/18/2023 9:48:19 AM
 * Author : Lenovo
 */ /*
#include "Std_Types.h"
#include "BitMath.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "UDS.h"
#include <avr/io.h>
*/

 #include "UDS.h"

//u8 ran_arr[9];
//u8 in_arr[9];
//u8 req_arr[5];
////u16 readval;
//u8  key=35;
//u16 ran=0;
////u8  encrypted_msg=0;
//u8 sec_flag=0;
//void UART_receiveString(u8 *Str);
//void Have_Security();
int main(void)
{
	
	UDS_Init();
	
	while(1)
	{
		UDS();
		}
	return 0 ;
}