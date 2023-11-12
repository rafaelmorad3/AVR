/*
 * DIO.c
 *
 * Created: 23/10/21 10:45:40 AM
 *  Author: Raphael Mourad
 */ 

#include "DIO.h"
void INIT(void)
{
	DDRA = PORT_INPUT;
	DDRB = PORT_INPUT;
	DDRC = PORT_INPUT;
	DDRD = PORT_INPUT;
}

ErrorStatus SetPinDirection(u8 u8Port,u8 u8Pin,u8 u8State)
{
	ErrorStatus loc_variable = ERROR_OK;
	if(u8Port>=PA && u8Port <=PD)
	{
		switch(u8Port){
			
			case PA:
			switch(u8State)
			{
				case OUTPUT:
				SET_BIT(DDRA,u8Pin);
				break;
				case INPUT:
				CLR_BIT(DDRA,u8Pin);
				break;
				default: loc_variable = ERROR_NOK;
			}
			break;
			case PB:
			switch(u8State)
			{
				case OUTPUT:
				SET_BIT(DDRB,u8Pin);
				break;
				case INPUT:
				CLR_BIT(DDRB,u8Pin);
				break;
				default: loc_variable = ERROR_NOK;
			}
			break;
			case PC:
			switch(u8State)
			{
				case OUTPUT:
				SET_BIT(DDRC,u8Pin);
				break;
				case INPUT:
				CLR_BIT(DDRC,u8Pin);
				break;
				default: loc_variable = ERROR_NOK;
			}
			break;
			case PD:
			switch(u8State)
			{
				case OUTPUT:
				SET_BIT(DDRD,u8Pin);
				break;
				case INPUT:
				CLR_BIT(DDRD,u8Pin);
				break;
				default: loc_variable = ERROR_NOK;
			}
			break;
			default : loc_variable = ERROR_NOK;
		}
	}
	else
	{
		loc_variable = ERROR_NOK;
	}
	return loc_variable;
}

ErrorStatus SetPinValue(u8 u8Port,u8 u8Pin,u8 u8Value)
{
	ErrorStatus loc_variable = ERROR_OK;
	if(u8Port>=PA && u8Port <=PD)
	{
		switch(u8Port)
		{
			case PA:
			switch(u8Value)
			{
				case HIGH:
				SET_BIT(PORTA,u8Pin);
				break;
				case LOW:
				CLR_BIT(PORTA,u8Pin);
				break;
				default: loc_variable = ERROR_NOK;
			}
			break;

			case PB:
			switch(u8Value)
			{
				case HIGH:
				SET_BIT(PORTB,u8Pin);
				break;
				case LOW:
				CLR_BIT(PORTB,u8Pin);
				break;
				default: loc_variable = ERROR_NOK;
			}
			break;
			case PC:
			switch(u8Value)
			{
				case HIGH:
				SET_BIT(PORTC,u8Pin);
				break;
				case LOW:
				CLR_BIT(PORTC,u8Pin);
				break;
				default: loc_variable = ERROR_NOK;
			}
			break;
			case PD:
			switch(u8Value)
			{
				case OUTPUT:
				SET_BIT(PORTD,u8Pin);
				break;
				case INPUT:
				CLR_BIT(PORTD,u8Pin);
				break;
				default: loc_variable = ERROR_NOK;
			}
			break;
			default : loc_variable = ERROR_NOK;
		}
	}
	else
	{
		loc_variable = ERROR_NOK;
	}
	return loc_variable;

}


ErrorStatus GetPinValue(u8 u8Port,u8 u8Pin,u8* u8Value)
{
	ErrorStatus loc_variable = ERROR_OK;
	if(u8Port>=PA && u8Port <=PD)
	{
		switch(u8Port){
			
			case PA:
			*u8Value=GET_BIT(PINA,u8Pin);
			break;
			case PB:
			*u8Value=GET_BIT(PINB,u8Pin);
			break;
			case PC:
			*u8Value=GET_BIT(PINC,u8Pin);
			break;
			case PD:
			*u8Value=GET_BIT(PIND,u8Pin);
			break;
			default : loc_variable = ERROR_NOK;
		}
	}
	else
	{
		loc_variable = ERROR_NOK;
	}
	return loc_variable;
}


ErrorStatus TogglePinValue(u8 u8port,u8 u8pin)
{
	ErrorStatus loc_variable = ERROR_OK;
	if(u8port>=PA && u8port <=PD)
	{
		switch(u8port){
			
			case PA:
			TOGGLE_BIT(u8port,u8pin);
			break;
			case PB:
			TOGGLE_BIT(u8port,u8pin);
			break;
			case PC:
			TOGGLE_BIT(u8port,u8pin);
			break;
			case PD:
			TOGGLE_BIT(u8port,u8pin);
			break;
			default : loc_variable = ERROR_NOK;

		}
	}
	else
	{
		loc_variable = ERROR_NOK;
	}
	return loc_variable;
}

ErrorStatus ControlPortDIR(u8 u8Port,u8 u8Direction)
{
	ErrorStatus loc_variable = ERROR_OK;
	if(u8Port>=PA && u8Port <=PD)
	{
		switch(u8Port){
			
			case PA:
			DDRA = u8Direction;
			
			break;
			case PB:
			DDRB = u8Direction;
			
			break;
			case PC:
			DDRC = u8Direction;
			
			break;
			case PD:
			DDRD = u8Direction;
			
			break;
			default : loc_variable = ERROR_NOK;
		}
	}
	else
	{
		loc_variable = ERROR_NOK;
	}
	return loc_variable;
}
ErrorStatus ControlPortValue(u8 u8Port,u8 u8Value)
{
	ErrorStatus loc_variable = ERROR_OK;
	if(u8Port>=PA && u8Port <=PD)
	{
		switch(u8Port){
			
			case PA:
			PORTA = u8Value;
			
			break;
			case PB:
			PORTB = u8Value;
			
			break;
			case PC:
			PORTC = u8Value;
			
			break;
			case PD:
			PORTD = u8Value;
			
			break;
			default : loc_variable = ERROR_NOK;
		}
	}
	else
	{
		loc_variable = ERROR_NOK;
	}
	return loc_variable;
}
