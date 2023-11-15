

#ifndef EX_INTERRUPT_INTERFACE_H_
#define EX_INTERRUPT_INTERFACE_H_

typedef enum{
	EX_INT0,
	EX_INT1,
	EX_INT2
	}ExInterruptSource_type;
	
typedef enum{
	LOW_LEVEL=0,
	ANY_LOGICAL_CHANGE,
	FALLING_EDGE,
	RISING_EDGE
	}TriggerEdge_type;
	
void EX_Interrpt_Init(void);
void ExInterrupt_Enable(ExInterruptSource_type Interrupt);
void ExInterrupt_Disable(ExInterruptSource_type Interrupt);
void ExInterrupt_TriggerEdge(ExInterruptSource_type Interrupt,TriggerEdge_type Edge);
void ExInterrupt_SetCallBack(ExInterruptSource_type Interrupt,void(*LocalPtr)(void));		



#endif /* EX_INTERRUPT_INTERFACE_H_ */