/*
 * UDS.c
 *
 * Created: 11/18/2023 11:41:02 AM
 *  Author: Lenovo
 */ 
 #include "UDS.h"
 
 /*********************************global variable**********************************/

 
 Security_state Current = Unsecure_state ;

 u8 enc_arr[9];
 u8 input_arr[9];
 u8 ran_arr[9];
 
 //u8 req_arr[5];
 u8 encryptMessage(u8 message)
 {
	return message ^ message ;
 }
 void UDS_Init(void){
	 DIO_INIT();
	 
	 USART_Init();
	 LCD_Init();
 }

 void UDS_Receive(u8 * arr){
	 u8 i = 0;
	 for (i=0;; i++)
	 {
		 arr[i] = USART_Receive();
		 // if temp is not a valid hex character
		/* if (((temp >= '0' && temp <= '9') || (temp >= 'A' && temp <= 'F') || (temp >= 'a' && temp <= 'f')))
		 {
			 arr[i] =temp;
		 }*/
		 if (arr[i]==' ')
		 {
			 break;
		 }
		 _delay_ms(10);
	 }
	 arr[i] = '\0';
 }
 void UDS_Transmit(u8 * arr){
	 u8 i =0 ;
	 for(i = 0 ; i <10 ; i++){
		 if (arr[i]=='\n')
		 {
			 break;
		 }
		 USART_Transmit(arr[i]);
	 }	 
 }
 
void UDS(void){
	switch(Current){
		
		case Unsecure_state:
		LCD_Clear();
		LCD_GoTo(0, 0);
		LCD_SendString("Get Key: ");
		
		
		UDS_Receive(input_arr);
		if(!(strcmp(input_arr,"3101AA00")))
		{   
			
			LCD_Clear();
			LCD_GoTo(1,1);
			LCD_SendString("NRC 7F 31 33");
			UDS_Transmit("NRC7F3133");
		}
		//UDS_Receive(input_arr);
		else if(!strcmp(input_arr,"2701")){			
		LCD_Clear();
		LCD_GoTo(1, 1);
		LCD_SendString("67 01 ");
		UDS_Transmit("6701");

		for(u8 i=0;i<8;i++)
		{
			ran_arr[i]=(rand()%10);
			ran_arr[i]+=48;
		}
		for(u8 i=0;i<8;i++)
		{
			LCD_SendChar(ran_arr[i]);
			USART_Transmit(ran_arr[i]);
		}
		for(u8 i=0;i<8;i++)
		{
			enc_arr[i] =encryptMessage(ran_arr[i]);
			if (ran_arr[i]=='0')
			{
				ran_arr[i]='9';
				continue;
			}
			ran_arr[i]--;
		}
		ran_arr[8]='\0';

		for(u8 i=0;i<8;i++)
		{
			input_arr[i]=0;
		}
		//UDS_Receive(req_arr);
		UDS_Receive(input_arr);
		if(!strcmp(input_arr,"2702"))
		{
		UDS_Receive(input_arr);
		if(!strcmp(input_arr,ran_arr))
		{
			Current=Secure_state;
			LCD_Clear();
			LCD_GoTo(1,1);
			LCD_SendString("67 02 ");
			UDS_Transmit("6702");
			_delay_ms(1500);
		}
		else
		{
			
			LCD_Clear();
			LCD_GoTo(1,1);
			LCD_SendString("7F 27 35");
			UDS_Transmit("7F2735");
			_delay_ms(1500);
		}
		}
		else
		{
			
			LCD_Clear();
			LCD_GoTo(1,1);
			LCD_SendString("7F 27 35");
			UDS_Transmit("7F2735");
			_delay_ms(1500);
		}

	}
	else{
		LCD_Clear();
		LCD_GoTo(1,1);
		LCD_SendString("7F 27 35");
		UDS_Transmit("7F2735");
		_delay_ms(1500);
	}
		
		
		break;
		
		
		case Secure_state:
		UDS_Receive(input_arr);
		if(!(strcmp(input_arr,"3101AA00")))
		{
			
			LCD_Clear();
			LCD_GoTo(1,1);
			LCD_SendString("71 01 AA 00");
			UDS_Transmit("7101AA00");
			setpinvalue(PINA5, HIGH);
		}
		else
		{
			LCD_SendString("NRC 7F 31 33");
			UDS_Transmit("NRC7F3133");
		}
		break;
		
	
}
}