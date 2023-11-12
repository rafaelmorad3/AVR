/*
 * PushButton.h
 *
 * Created: 23/10/23 10:24:10 AM
 *  Author: Shiko
 */ 


#ifndef PUSHBUTTON_H_
#define PUSHBUTTON_H_
#include "DIO.h"
#include "PORT.h"
#include "STD_TYPES.h"
#include <stdio.h>
#include <stdlib.h>
#include<util/delay.h>

#define KPD_u8_KEYS      {{'7','8','9','/'},\
{'4','5','6','*'},\
{'1','2','3','-'},\
{'E','0','=','+'}}

#define KPD_u8_KEY_NOT_PRESSED   ('q')
u8 KPD_u8GetKeyState(u8 * Copy_pu8ReturnedKey);
/*
void  PushButton_INIT(void);
u8  PushButton_GET(void);


#define RP PC
#define ROW1 PIN5
#define ROW2 PIN4
#define ROW3 PIN3
#define ROW4 PIN2

#define CP PD
#define COL1 PIN7
#define COL2 PIN6 
#define COL3 PIN5 
#define COL4 PIN3
*/
#endif /* PUSHBUTTON_H_ */