#include "Std_Types.h"
#include "MemMap.h"
#include "BitMath.h"
#include "DIO_Interface.h"
#include "DIO_CFG.h"
#include "DIO_Private.h"

void DIO_INIT(void)
{
	DIO_Pin_type i;
	for (i=PINA0;i<TOTAL_PINS;i++)
	{
		SETPINDirection(i,Dio_PinsStatusArr[i]);
	}
}


static ERROR_status SETPINDirection(DIO_Pin_type PIN,PIN_Status_type STATE)
{
	DIO_Port_type PORT=PIN/8;
	u8 BIT=PIN%8;
	ERROR_status loc_variable = E_OK;
	if(PORT>=PA && PORT <=PD)
	{
		switch(PORT){
			
			case PA:
			switch(STATE)
			{
				case OUTPUT:
				SETBIT(DDRA,BIT);
				CLRBIT(PORTA,BIT);
				break;
				case INFREE:
				CLRBIT(DDRA,BIT);
				CLRBIT(PORTA,BIT);
				break;
				case INPULL:
				CLRBIT(DDRA,BIT);
				SETBIT(PORTA,BIT);
				break;
				default: loc_variable = E_NOK;
			}
			break;
			
			case PB:
			switch(STATE)
			{
				case OUTPUT:
				SETBIT(DDRB,BIT);
				CLRBIT(PORTB,BIT);
				break;
				case INFREE:
				CLRBIT(DDRB,BIT);
				CLRBIT(PORTB,BIT);
				break;
				case INPULL:
				CLRBIT(DDRB,BIT);
				SETBIT(PORTB,BIT);
				default: loc_variable = E_NOK;
			}
			break;
			case PC:
			switch(STATE)
			{
				case OUTPUT:
				SETBIT(DDRC,BIT);
				CLRBIT(PORTC,BIT);
				break;
				case INFREE:
				CLRBIT(DDRC,BIT);
				CLRBIT(PORTC,BIT);
				break;
				case INPULL:
				CLRBIT(DDRC,BIT);
				SETBIT(PORTC,BIT);
				default: loc_variable = E_NOK;
			}
			break;
			case PD:
			switch(STATE)
			{
				case OUTPUT:
				SETBIT(DDRD,BIT);
				CLRBIT(PORTD,BIT);
				break;
				case INFREE:
				CLRBIT(DDRD,BIT);
				CLRBIT(PORTD,BIT);
				break;
				case INPULL:
				CLRBIT(DDRD,BIT);
				SETBIT(PORTD,BIT);
				default: loc_variable = E_NOK;
			}
			break;
			default : loc_variable = E_NOK;
		}
	}
	else
	{
		loc_variable = E_NOK;
	}
	return loc_variable;
}

ERROR_status setpinvalue(DIO_Pin_type PIN,PIN_Volt_status value)
{
	DIO_Port_type PORT=PIN/8;
	u8 BIT=PIN%8;
	ERROR_status loc_variable = E_OK;
	if(PORT>=PA && PORT <=PD)
	{
		switch(PORT){
			
			case PA:
			switch(value)
			{
				case HIGH:
				SETBIT(PORTA,BIT);
				break;
				case LOW:
				CLRBIT(PORTA,BIT);
				break;
				default: loc_variable = E_NOK;
			}
			break;
			
			case PB:
			switch(value)
			{
				case HIGH:
				SETBIT(PORTB,BIT);
				break;
				case LOW:
				CLRBIT(PORTB,BIT);
				break;
				default: loc_variable = E_NOK;
			}
			break;
			case PC:
			switch(value)
			{
				case HIGH:
				SETBIT(PORTC,BIT);
				break;
				case LOW:
				CLRBIT(PORTC,BIT);
				break;
				default: loc_variable = E_NOK;
			}
			break;
			case PD:
			switch(value)
			{
				case HIGH:
				SETBIT(PORTD,BIT);
				break;
				case LOW:
				CLRBIT(PORTD,BIT);
				break;
				default: loc_variable = E_NOK;
			}
			break;
			default : loc_variable = E_NOK;
		}
	}
	else
	{
		loc_variable = E_NOK;
	}
	return loc_variable;
}

ERROR_status getpinvalue(DIO_Pin_type PIN,PIN_Volt_status*value)
{
	DIO_Port_type PORT=PIN/8;
	u8 BIT=PIN%8;
	ERROR_status loc_variable = E_OK;
	if(PORT>=PA && PORT <=PD)
	{
		switch(PORT){
			
			case PA:
			*value=READBIT(PINA,BIT);
			break;
			case PB:
			*value=READBIT(PINB,BIT);
			break;
			case PC:
			*value=READBIT(PINC,BIT);
			break;
			case PD:
			*value=READBIT(PIND,BIT);
			break;
			default : loc_variable = E_NOK;
		}
	}
	else
	{
		loc_variable = E_NOK;
	}
	return loc_variable;
}

ERROR_status togglepinvalue(DIO_Pin_type PIN)
{
	ERROR_status loc_variable = E_OK;
	DIO_Port_type port=PIN/8;
	u8 pin=PIN%8;
		switch(port){
			
			case PA:
			ToggleBIT(PORTA,pin);
			break;
			case PB:
			ToggleBIT(PORTB,pin);
			break;
			case PC:
			ToggleBIT(PORTC,pin);
			break;
			case PD:
			ToggleBIT(PORTD,pin);
			break;
		}
	return loc_variable;
}

ERROR_status ControlPortDIR(DIO_Port_type PORT,PIN_Status_type DIRECTION)
{
	ERROR_status loc_variable = E_OK;
	if(PORT>=PA && PORT <=PD)
	{
		switch(PORT){
			
			case PA:
			DDRA = DIRECTION;
			
			break;
			case PB:
			DDRA = DIRECTION;
			
			break;
			case PC:
			DDRA = DIRECTION;
			
			break;
			case PD:
			DDRA = DIRECTION;
			
			break;
			default : loc_variable = E_NOK;
		}
	}
	else
	{
		loc_variable = E_NOK;
	}
	return loc_variable;
}

ERROR_status controlPortValue(DIO_Port_type PORT,u8 Value)
{
	ERROR_status loc_variable = E_OK;
	if(PORT>=PA && PORT <=PD)
	{
		switch(PORT){
			
			case PA:
			PORTD = Value;
			
			break;
			case PB:
			PORTD = Value;
			
			break;
			case PC:
			PORTD = Value;
			
			break;
			case PD:
			PORTD = Value;
			
			break;
			default : loc_variable = E_NOK;
		}
	}
	else
	{
		loc_variable = E_NOK;
	}
	return loc_variable;
}
