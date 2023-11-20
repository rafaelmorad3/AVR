

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#define ASYNCHRONOUS  0
#define SYNCHRONOUS  1

#define DOUBLE_SPEED_MODE			0
#define NORMAL_SPEED_MODE			1

#define ENABLE_EVEN   0
#define ENABLE_ODD  1
#define DISABLED  2

#define ONE_BIT  0
#define TWO_BIT  1



void USART_Init(void);
void USART_Transmit( u8 data );
u8 USART_Receive(void);


u8 UART_ReceivePerodic(u8*pdata);

void UART_SendNoBlock(u8 data);
u8 UART_ReceiveNoBlock(void);

void UART_RX_InterruptEnable(void);
void UART_RX_InterruptDisable(void);

void UART_TX_InterruptEnable(void);
void UART_TX_InterruptDisable(void);

void UART_RX_SetCallBack(void (*LocalFptr)(void));
void UART_TX_SetCallBack(void (*LocalFptr)(void));


#endif /* UART_INTERFACE_H_ */