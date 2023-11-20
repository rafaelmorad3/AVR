/*
 * UDS.h
 *
 * Created: 11/18/2023 11:40:45 AM
 *  Author: Lenovo
 */ 


#ifndef UDS_H_
#define UDS_H_



#include "BitMath.h"
#include "Std_Types.h"
#include "MemMap.h"
#include "UART_Interface.h"
#include "LCD_Interface.h"
#include "DIO_Interface.h"
#define F_CPU    8000000ul
#include <stdlib.h> // for rand() function

#include <time.h>
#include <util/delay.h>

#define NEGATIVE_RESPONSE		      0x7F3133
#define TURN_ON_LED			          0x3101AA00
#define POSITIVE_RESPONSE_LED         0x7101AA00
#define SECURITY_ACCESS			      0x2701
#define CHECK_KEY				      0x2702
#define ENTER_SECURITY_KEY		      0x6701
#define NEGATIVE_KEY		          0x7F2735
#include <util/delay.h>


typedef enum {
	Unsecure_state= 0,
	Secure_state
	}Security_state;

void UDS_Init(void);
void UDS (void);



#endif /* UDS_H_ */