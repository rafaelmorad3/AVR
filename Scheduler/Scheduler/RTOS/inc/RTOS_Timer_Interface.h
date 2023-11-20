/*
 * RTOS_Timer_Interface.h
 *
 * Created: 11/19/2023 2:49:59 PM
 *  Author: Lenovo
 */ 


#ifndef RTOS_TIMER_INTERFACE_H_
#define RTOS_TIMER_INTERFACE_H_


void RTOS_Timer_voidInit                   (void);
void RTOS_Timer_voidStart                  (void);
void RTOS_Timer_voidStop                   (void);
void RTOS_Timer_voidSetCompareMatchValue   (u8 copy_u8CompareValue);
void RTOS_Timer_voidSetCallBackCTC         (void(*ptrToFun)(void));




#endif /* RTOS_TIMER_INTERFACE_H_ */