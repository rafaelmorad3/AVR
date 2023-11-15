/*
 * PWM_Detect.h
 *
 * Created: 11/12/2023 1:57:46 PM
 *  Author: Lenovo
 */ 


#ifndef PWM_DETECT_H_
#define PWM_DETECT_H_

#include "MemMap.h"
#include "DIO_Interface.h"
#include "Timer_Interface.h"
#include "LCD_Interface.h"
#include "KeyPad_Interface.h"

typedef enum{
	Stop,
	speed_1,
	speed_2,
	speed_3,
	speed_4,
	speed_5
	}speed;
void PWM_Detect_Init(void);
void PWM_Detect(void);




#endif /* PWM_DETECT_H_ */