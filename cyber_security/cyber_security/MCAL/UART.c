#include "Std_Types.h"
#include "MemMap.h"
#include "BitMath.h"
#include "UART_CFG.h"
#include "UART_Interface.h"

static void(*UART_RX_Fptr)(void)=NULL_PTR;
static void(*UART_TX_Fptr)(void)=NULL_PTR;


void USART_Init(void)
{
	/* SYNCH vs ASYNCH BIT */
	//  	#if MODE_OF_OPERATION==ASYNCHRONOUS
	// 	SETBIT(UCSRC,7);
	//  	CLRBIT(UCSRC,UMSEL);
	//  	#elif MODE_OF_OPERATION==SYNCHRONOUS
	// 	SETBIT(UCSRC,7);
	//  	SETBIT(UCSRC,UMSEL);
	//  #endif

	/*	Speed mode normal or Double		*/
	
	#if SPEED_OPERATION==NORMAL_SPEED_MODE
	/* Set baud rate */
	UBRRL=(((u32)F_CPU/((u32)16*BAUD_RATE))-1);
	CLRBIT(UCSRA,U2X);
	
	#elif SPEED_OPERATION==DOUBLE_SPEED_MODE
	SETBIT(UCSRA,U2X);
	/* Set baud rate */
	UBRRL=(((u32)F_CPU/((u32)8*BAUD_RATE))-1);
	
	#endif

	/*	 Character Size N-Bits			*/
	
	#if FRAME_SIZE==5
	CLRBIT(UCSRC,UCSZ0);
	CLRBIT(UCSRC,UCSZ1);
	CLRBIT(UCSRB,UCSZ2);
	#elif FRAME_SIZE==6
	SETBIT(UCSRC,UCSZ0);
	CLRBIT(UCSRC,UCSZ1);
	CLRBIT(UCSRB,UCSZ2);
	#elif FRAME_SIZE==7
	CLRBIT(UCSRC,UCSZ0);
	SETBIT(UCSRC,UCSZ1);
	CLRBIT(UCSRB,UCSZ2);
	// 	#elif FRAME_SIZE==8
	// 	SETBIT(UCSRC,UCSZ0);
	// 	SETBIT(UCSRC,UCSZ1);
	// 	CLRBIT(UCSRB,UCSZ2);
	#elif FRAME_SIZE==9
	SETBIT(UCSRC,UCSZ0);
	SETBIT(UCSRC,UCSZ1);
	SETBIT(UCSRB,UCSZ2);
	#endif

	/* PARITY EVEN OR ODD OR DISABLED */
	
	#if PARITY_MODE==DISABLED
	CLRBIT(UCSRC,UPM0);
	CLRBIT(UCSRC,UPM1);
	#elif PARITY_MODE==ENABLE_EVEN
	CLRBIT(UCSRC,UPM0);
	SETBIT(UCSRC,UPM1);
	#elif PARITY_MODE==ENABLE_ODD
	SETBIT(UCSRC,UPM0);
	SETBIT(UCSRC,UPM1);
	#endif

	/*	Stop bit select number One or Two Bits */
	
	#if STOP_BIT_SELECT==ONE_BIT
	CLRBIT(UCSRC,USBS);
	#elif STOP_BIT_SELECT==TWO_BIT
	SETBIT(UCSRC,USBS);
	#endif

	/* Enable receiver and transmitter 			*/
	
	SETBIT(UCSRB,RXEN);
	SETBIT(UCSRB,TXEN);


}

void USART_Transmit( u8 data )
{
	while(!READBIT(UCSRA,UDRE));
	UDR=data;
}

u8 USART_Receive(void)
{
	while(!READBIT(UCSRA,RXC));
	return UDR;
}

u8 UART_ReceivePerodic(u8*pdata)
{
	if (READBIT(UCSRA,RXC))
	{
		*pdata=UDR;
		return 1;
	}
	return 0;
}

void UART_SendNoBlock(u8 data)
{
	UDR=data;
}

u8 UART_ReceiveNoBlock(void)
{
	return UDR;
}

void UART_RX_InterruptEnable(void)
{
	SETBIT(UCSRB,RXCIE);
}

void UART_RX_InterruptDisable(void)
{
	CLRBIT(UCSRB,RXCIE);
}

void UART_TX_InterruptEnable(void)
{
	SETBIT(UCSRB,TXCIE);
}

void UART_TX_InterruptDisable(void)
{
	CLRBIT(UCSRB,TXCIE);
}

void UART_RX_SetCallBack(void (*LocalFptr)(void))
{
	UART_RX_Fptr = LocalFptr;
}

void UART_TX_SetCallBack(void (*LocalFptr)(void))
{
	UART_TX_Fptr = LocalFptr;
}

ISR(USART_RXC_vect)
{
	if(UART_RX_Fptr!=NULL_PTR){
		UART_RX_Fptr();
	}
}

ISR(USART_TXC_vect)
{
	if(UART_TX_Fptr!=NULL_PTR){
		UART_TX_Fptr();
	}
}

