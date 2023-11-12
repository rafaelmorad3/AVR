/*
 * PORT.h
 *
 * Created: 23/10/23 2:13:36 PM
 *  Author: Shiko
 */ 


#ifndef PORT_H_
#define PORT_H_


#ifndef PORT_H_
#define PORT_H_

#include "MEGA.h"
/* LCD */
///FOR DATA
#define LCD_DATA_PORT_DR         (PORTB)
#define LCD_DATA_PORT_CR         (DDRB)
#define LCD_DATABIN_D4           (PIN0)
#define LCD_DATABIN_D5           PIN1
#define LCD_DATABIN_D6           (PIN2)
#define LCD_DATABIN_D7           (PIN3)

///////FOR ENABLE
#define LCD_ENABLE_DR       (PORTA)
#define LCD_ENABLE_CR       (PORTA)
#define LCD_ENABLE_PIN      (PIN2)
///////FOR REGISTER SELECTION
#define LCD_RS_DR            (PORTA)
#define LCD_RS_CR            (PORTA)
#define LCD_RS_PIN           (PIN3)

/////////////////////////////////////////////////////////////


#define KPD_u8_ROW_PORT      PC
#define KPD_u8_COL_PORT      PD

#define KPD_u8_R1_PIN     PIN5
#define KPD_u8_R2_PIN     PIN4
#define KPD_u8_R3_PIN     PIN3
#define KPD_u8_R4_PIN     PIN2

#define KPD_u8_C1_PIN     PIN7
#define KPD_u8_C2_PIN     PIN6
#define KPD_u8_C3_PIN     PIN5
#define KPD_u8_C4_PIN     PIN3

/////////////////////////////////////////////////////////////
//ports for SW

#define SW_1_PORT_DINR   (PORTD)
#define SW_1_PORT_CR     (GPIO_PORTD_CONTROL)
#define SW_1_PIN         (GPIO_PIN_0)


#define SW_2_PORT_DINR   (PORTD)
#define SW_2_PORT_CR     (GPIO_PORTD_CONTROL)
#define SW_2_PIN         (GPIO_PIN_1)


#define SW_3_PORT_DINR   PORTD
#define SW_3_PORT_CR     (GPIO_PORTD_CONTROL)
#define SW_3_PIN         (GPIO_PIN_2

#define SW_4_PORT_DINR   PORTD
#define SW_4_PORT_CR     DDRD
#define SW_4_PIN         PIN3





#endif /* PORT_H_ */