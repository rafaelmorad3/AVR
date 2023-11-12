/*
 * DIO.h
 *
 * Created: 23/10/21 10:46:37 AM
 *  Author: Raphael Mourad
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "M_Map.h"
#include "BitMath.h"
#include "DIO_Confg.h"
#include "DIO_Private.h"
#include "Std_types.h"
#include "Delay.h"


#define OUTPUT 0x1
#define INPUT  0x0

#define PORT_OUTPUT 0xFF
#define PORT_INPUT 0x00

#define LOW  0 
#define HIGH 1 

typedef enum
{
PIN0,
PIN1,
PIN2,
PIN3,
PIN4,
PIN5,
PIN6,
PIN7
}PINS;

typedef enum {
PA = 1,
PB,
PC,
PD
}PORTS;
/*
 *
 */
void INIT(void);
ErrorStatus SetPinDirection(u8 u8Port,u8 u8Pin,u8 u8State);
ErrorStatus SetPinValue(u8 u8Port,u8 u8Pin,u8 u8Value);
ErrorStatus GetPinValue(u8 u8Port,u8 u8Pin,u8* u8Value);
ErrorStatus TogglePinValue(u8 u8port,u8 u8pin);
ErrorStatus ControlPortDIR(u8 u8Port,u8 u8Direction);
ErrorStatus ControlPortValue(u8 u8Port,u8 u8Value);





#endif /* DIO_H_ */