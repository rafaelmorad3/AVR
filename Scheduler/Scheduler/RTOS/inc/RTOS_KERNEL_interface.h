/*
 * RTOS_KERNEL_interface.h
 *
 *  Created on: Nov 20, 2023
 *      Author: Kareem Hussein
 */

#ifndef RTOS_INC_RTOS_KERNEL_INTERFACE_H_
#define RTOS_INC_RTOS_KERNEL_INTERFACE_H_
#define RTOS_TASK_SUSPENDED	1
#define RTOS_TASK_RESUMED	2

void RTOS_KERNEL_voidStartScheduling(void);
u8 RTOS_KERNEL_voidCreateTask     (u8 copy_u8Priority,u16 copy_u16Periodicty,void(*ptrToFun)(void));
/* periodecity moda3fat al artos tick lazm w hnbase 3nwan al function y3ni da al schadular haysht8l 3leh*/

void RTOS_KERNEL_voidDeletTask(u8 copy_u8Priority);

//periodic function...htkhosh t3dl haga fl array hayshofha al schadular fa yl8eha
void RTOS_KERNEL_voidSuspendTask(u8 copy_u8Priority);

void RTOS_KERNEL_voidResumeTask(u8 copy_u8Priority);



#endif /* RTOS_INC_RTOS_KERNEL_INTERFACE_H_ */
