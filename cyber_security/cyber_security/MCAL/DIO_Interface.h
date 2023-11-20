/*
 * DIO_Interface.h
 *
 * Created: 20/10/2023 02:06:42 م
 *  Author: dell
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#include "Std_Types.h"
#define PIN_OUTPUT 0x1
#define PIN_INPUT  0x0

#define PORT_OUTPUT 0xFF
#define PORT_INPUT 0x00

typedef enum{
		PINA0=0,
		PINA1=1,
		PINA2,
		PINA3,
		PINA4,
		PINA5,
		PINA6,
		PINA7,
		PINB0,
		PINB1,
		PINB2,
		PINB3,
		PINB4,
		PINB5,
		PINB6,
		PINB7,
		PINC0,
		PINC1,
		PINC2,
		PINC3,
		PINC4,
		PINC5,
		PINC6,
		PINC7,
		PIND0,
		PIND1,
		PIND2,
		PIND3,
		PIND4,
		PIND5,
		PIND6,
		PIND7,
		TOTAL_PINS
	}DIO_Pin_type;

typedef enum
{
	PIN0=0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}PINS;

typedef enum {
	PA = 0,
	PB,
	PC,
	PD
}DIO_Port_type;

typedef enum{
	OUTPUT,
	INFREE,
	INPULL
	}PIN_Status_type;
	
typedef enum{
	LOW,
	HIGH
	}PIN_Volt_status;	

//prototypes
void DIO_INIT(void); // ddrx input
ERROR_status setpinvalue(DIO_Pin_type PIN,PIN_Volt_status value);
ERROR_status getpinvalue(DIO_Pin_type PIN,PIN_Volt_status *value);
ERROR_status togglepinvalue(DIO_Pin_type PIN);
ERROR_status ControlPort(DIO_Port_type PORT,PIN_Status_type DIRECTION);
ERROR_status controlPortValue(DIO_Port_type PORT,u8 Value);





#endif /* DIO_INTERFACE_H_ */