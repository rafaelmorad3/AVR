///*
 //* Service.h
 //*
 //* Created: 11/19/2023 2:14:19 PM
 //*  Author: Lenovo
 //*/ 
//
//
//#ifndef SERVICE_H_
//#define SERVICE_H_
//
//
//
//
//void UART_Send_2_Bytes(u16 a_data)
//{
	//u8 i;
	//for (i = 0; i < 2; i++)
	//{
		//USART_Transmit((u8)(a_data >> (i * 8)));
		//_delay_ms(10);
	//}
//}
//
//void UART_Send_4_Bytes(u32 a_data)
//{
	//u8 i;
	//for (i = 0; i < 4; i++)
	//{
		//USART_Transmit((u8)(a_data >> (i * 8)));
		//_delay_ms(10);
	//}
//}
//
//
//u8 Random_Key(void)
//{
	 //Seed the random number generator with the current time
	//srand((u32)time(NULL));
//
	 //Generate a random number in the range 255
	//return (rand() % 255);
//}
//unsigned int hexStringToUInt(const char* hexString) {
	//unsigned int result = 0;
//
	 //Iterate through each character in the string
	//for (int i = 0; hexString[i] != '\0'; ++i) {
		//char currentChar = hexString[i];
//
		 //Convert the character to its hexadecimal value
		//int hexValue;
		//if (currentChar >= '0' && currentChar <= '9') {
			//hexValue = currentChar - '0';
			//} else if (currentChar >= 'A' && currentChar <= 'F') {
			//hexValue = 10 + (currentChar - 'A');
			//} else if (currentChar >= 'a' && currentChar <= 'f') {
			//hexValue = 10 + (currentChar - 'a');
			//} else {
			 //Invalid character in the hexadecimal string
			//fprintf(stderr, "Error: Invalid character in hexadecimal string.\n");
			//return 0; // Or handle the error as needed
		//}
//
		 //Update the result by shifting and adding the new hex value
		//result = (result << 4) | hexValue;
	//}
//
	//return result;
//}
//u32 stringToHex(const u8* str)
//{
	//u8* endptr;
	//return strtoul(str, NULL, 16);
//}
//
//u8 convert(u8 ch){
	//u8 hex;
	//if (ch >= '0' && ch <= '9' )
	//{
		//hex=ch -'0';
	//}
	//else if ((ch >= 'A' && ch <= 'F') || (ch >= 'a' && ch <= 'f'))
	//{
		//switch (ch)
		//{
			//case 'A': case 'a': hex = 0x0A; break;
			//case 'B': case 'b': hex = 0x0B; break;
			//case 'C': case 'c': hex = 0x0C; break;
			//case 'D': case 'd': hex = 0x0D; break;
			//case 'E': case 'e': hex = 0x0E; break;
			//case 'F': case 'f': hex = 0x0F; break;
			//default: break;
		//}
	//}
	//else{
		 //Misra
	//}
	//return hex;
//}
//
//void UDS_Send(u32 Sent_Hex, u8 len)
//{
	//u8 hexLookup[] = "0123456789ABCDEF";
	//u8 size = 0;
//
	//for (u8 shift = 28; shift >= 0; shift -= 4)
	//{
		//size++;
//
		//u8 hex = (Sent_Hex >> shift) & 0x0F;
		//USART_Transmit(hexLookup[hex]);
//
		//if (size == len)
		//{
			//break;
		//}
	//}
//}
 //void UDS_SendPositiveResponse (u8 *Str, u8 c)
 //{
	 //Str[0]+=0x4;
	 //
	 //for (u8 i = 0; i < c/2 ;i++)
	 //{
		 //
		 //USART_Transmit( Str[i]*16+Str[i+1]);
	 //}
	 //
	 //
 //}
 //void UDS_SendNegativeResponse (u8 ServiceID,u8 NRC)
 //{
	 //USART_Transmit( NEGATIVE_RESPONSE_ID );
	 //USART_Transmit( ServiceID );
	 //USART_Transmit( NRC );
	 //
 //}
 //*/
 //void UART_receiveString(u8 *Str)
 //{
 //u8 i = 0,temp;
 //Str[i] = USART_Receive();
 //for (i=0;i < 8 ; i++)
 //{
 //temp = USART_Receive();
  //if temp is not a valid hex character
 //if (((temp >= '0' && temp <= '9') || (temp >= 'A' && temp <= 'F') || (temp >= 'a' && temp <= 'f')))
 //{
  //ignore it
  //continue;
 //Str[i] =temp;
 //
 //i++;
 //Str[i] = USART_Receive();
 //}
 //Str[i] = '\0';
 //if (Str[i]==20)
 //{
 //break;
 //}
 //}
 //}
 //u32 UDS_Receive(u8 Len)
 //{
 //u8  Str[8];
 //u8  i = 0;
 //u8  temp;
 //u32 Hex_num=0,test=0,test_1;
 //LCD_GoTo(1,0);
 //for (i=0;i < 8 ; i++)
 //{
 //temp = USART_Receive();
  //if temp is not a valid hex character
 //if (((temp >= '0' && temp <= '9') || (temp >= 'A' && temp <= 'F') || (temp >= 'a' && temp <= 'f')))
 //{
  //ignore it
  //continue;
 //Str[i] =convert(temp);
 //LCD_GoTo(2,i);
 //
 //LCD_SendChar(Str[i]);
 //test = test *16 + Str[i];
 //}
 //
 //
 //
 //
 //}
 //Str[i] = '\0';
 //Hex_num = stringToHex(Str);
 //LCD_Clear();
 //LCD_GoTo(3,0);
 //LCD_writeNumber(Hex_num);
 //_delay_ms(500);
 //LCD_Clear();
 //LCD_writeNumber(test);
 //_delay_ms(500);
 //test_1 =hexStringToUInt(Str);
 //LCD_Clear();
 //LCD_writeNumber(test_1);
 //_delay_ms(500);
 //return Hex_num;
 //
 //}
 //
 //
 //void UDS (void){
	 //u32 Servise ,received_Key;
	 //
	 //u32 Key = Random_Key();
	 //_delay_ms(500);
	 //switch(Current){
		 //
		 //case Unsecure_state:
		 //LCD_Clear();
		 //LCD_GoTo(0, 0);
		 //LCD_SendString("Get Key: ");
		 //Servise= UDS_Receive(4);
		 //u8 Str[8];
		 //
		 //UART_receiveString(*Str);
		 //if(strcmp(Str,"2701")){
			 //if (Servise==SECURITY_ACCESS)
			 //
			  //Send the security access key through UART
			 //UDS_Send(ENTER_SECURITY_KEY, 8);
			 //
			 //UART_Send_4_Bytes(Key);
			 //
			  //Encrypt the random key
			 //encrypted_key = encryptMessage(Key);
			 //Flag = True;
//
			 //LCD_Clear();
			 //LCD_GoTo(2, 0);
			 //LCD_SendString("67 01");
			 //_delay_ms(1000);
			 //LCD_GoTo(3, 0);
			 //LCD_SendString(" Rand:");
			 //LCD_writeNumber(Key);
			 //while (Current != Secure_state)
			 //{
				 //LCD_GoTo(0, 0);
				 //LCD_SendString("Enter MSG: ");
				 //_delay_ms(1000);
//
				 //LCD_displayInteger(encrypted_key); // FOR TESTING
				 //Servise = UDS_Receive(4);
//
				 //if (Servise==ENTER_SECURITY_KEY)
				 //{
					 //LCD_GoTo(1, 0);
					 //LCD_SendString("Encrypted KEY:");
					 //LCD_GoTo(2, 0);
					 //LCD_SendString("KEY:");
					 //LCD_writeNumber(encrypted_key);
					 //LCD_GoTo(3, 0);
					 //received_Key=UDS_Receive(8);
//
					 //if (received_Key == encrypted_key)
					 //{
						 //Current = Secure_state;
						 //LCD_SendString( " 67 02");
					 //}
					 //else
					 //{
						 //LCD_Clear();
						 //LCD_SendString( " $  Wrong Key  $");
						 //UDS_Send(NEGATIVE_KEY, 8);
						 //_delay_ms(1000);
						 //_delay_ms(1000);
//
					 //}
					 //
				 //}
				 //else
				 //{
					 ///*  Do nothing  */
				 //}
				 //
			 //}
		 //}
		 //else
		 //{
			 //UDS_Send(NEGATIVE_RESPONSE, 8);
		 //}
		 //break;
		 //
		 //
		 //case Secure_state:
		 //LCD_Clear();
		 //LCD_GoTo(0, 0);
		 //LCD_SendString("ur are secure: ");
		 //LCD_GoTo(1, 0);
		 //LCD_SendString("enter the Service: ");
		 //Servise= UDS_Receive(8);
		 //
//
		 //if (Servise==TURN_ON_LED)
		 //{
			 //UDS_Send(POSITIVE_RESPONSE_LED, 8);
			 //setpinvalue(PINA5,HIGH);
		 //}
		 //else{
			 //UDS_Send(NEGATIVE_RESPONSE, 8);
			 //LCD_SendString("7F 31 33");
		 //}
		 //break;
		 //
	 //}
 //}
 //
 //
 //
 //
 //
 //}
 //
 //
 //
//
 //u8 Str[];
 //while (Flag != True)
 //{
	 //
 //}
 //switch(Str[0]){
	 //
	 //case 0x31:
	 //if (Str[1]==0x11&&Flag)
	 //{
		 //UDS_SendPositiveResponse (Str);
		 //setpinvalue(PINA5,HIGH);
	 //}
	 //else
	 //UDS_SendNegativeResponse (Str[0],33);
	 //
	 //
	 //break;
	 //case 0x27:
	 //if (Str[1]==0x01)
	 //{
		 //UDS_SendPositiveResponse (Str);
		 //UART_Send_2_Bytes(Key);
		 //encrypted_key = encryptMessage(Key);
	 //}
	 //
	 //
	 //else if  (Str[1]==0x02)
	 //{
		 //if (Str[2]==((encrypted_key>>8) &0x0f))
		 //{
			 //if (Str[2]==((encrypted_key) &0xf0)){
				 //UDS_SendPositiveResponse (Str);
				 //Flag=1;
			 //}
		 //}
		 //
		 //
	 //}
	 //else
	 //UDS_SendNegativeResponse (Str[0],35);
	 //
	 //
	 //break;
	 //default:
	 //UDS_SendNegativeResponse (Str[0],33);
	 //break;
	 //
	 //
 //}
//
 //
 //
 //
 //USART_Transmit( u8 data );
 //
 //u8 UART_ReceivePerodic(u8*pdata);
 //
 //}
 //
//
//
//
 //void GetAccessKey()
 //{
	 //u32 Key = Random_Key();
	 //u8  rand_str[5];
	 //u16 security_access_key;
//
	 //u8 security_access_flag = False;
//
	 //u8 Str[4];
	 //while (Flag != True)
	 //{
		 //LCD_Clear();
		 //LCD_GoTo(0, 0);
		 //LCD_SendString("Get Key: ");
		 //UDS_Receive(2,Str);
		 //Str[2]='\0';
//
		 //if (Str[0] == 27&&Str[1]==01)
		 //{
			  //Send the security access key through UART
			 //UDS_SendPositiveResponse(Str,2);
//
			 //UART_Send_4_Bytes(Key);
//
			  //Encrypt the random key
			 //encrypted_key = encryptMessage((Key << 16));
			 //Flag = True;
//
			 //LCD_Clear();
			 //LCD_GoTo(2, 0);
			 //LCD_SendString("67 01");
			 //LCD_GoTo(3, 0);
			 //LCD_SendString(" Rand:");
			 //LCD_displayInteger(Key);
		 //}
		 //else
		 //{
			 //Do nothing
		 //}
	 //}
 //}
//
 //void CheckencryptMessage(void)
 //{
	 //u32 received_Key;
	 //u32 received_data;
	 //u8  received_data_flag = False;
//
	 //while (received_data_flag != True)
	 //{
		 //LCD_GoTo(0, 0);
		 //LCD_SendString("Enter MSG: ");
		 //LCD_displayInteger(encrypted_key); // FOR TESTING
		 //received_data = UART_UDSReceive(4);
//
		 //if (received_data == UDS_CHECK_KEY)
		 //{
			 //LCD_GotTo(1, 0);
			 //LCD_SendString("Encrypted KEY:");
			 //LCD_GoTo(2, 0);
			 //received_Key = UART_UDSReceive(8);
//
			 //if (received_Key == encrypted_key)
			 //{
				 //AccessKey_flag = True;
				 //received_data_flag = True;
			 //}
			 //else
			 //{
				 //LCD_Clear();
				 //LCD_SendString(  " ###  Wrong Key  ###");
			 //}
		 //}
		 //else
		 //{
			 //Do nothing
		 //}
		 //LCD_clearScreen();
	 //}
 //}
//
 //void UDS()
 //{
//
	 //uint32 UDS_RoutineControl;
//
	 //LCD_GoTo(0, 0);
	 //LCD_SendString("ENTER MASSAGE");
//
	 //LCD_GoTo(1, 0);
	 //UDS_RoutineControl = UART_UDSReceive(8);
	 //if (UDS_RoutineControl == UDS_TURN_ON_BUZZER)
	 //{
		 //if (AccessKey_flag == False)
		 //{
			 //LCD_Clear();
			 //LCD_SendString( "  ACCESS DENIED");
			 //_delay_ms(500);
//
			 //
//
			 //GetAccessKey();
//
			 //CheckencryptMessage();
		 //}
		 //else
		 //{
			 //Buzzer_Alarm();
			 //LCD_clearScreen();
			 //LCD_displayStringCenter(0, "ACCESS GRANTED");
			 //LCD_displayStringCenter(1, "BUZZER ON");
//
			 //UART_UDSSend(UDS_POSITIVE_RESPONSE_BUZZER, UDS_LARGE_MESSAGE);
//
			 //AccessKey_flag = FALSE; // Reset the flag
		 //}
	 //}
	 //else
	 //{
		 //LCD_Clear();
	 //}
 //}
 //}
 //DIO_INIT();
 //UDS_Init();
 //USART_Init();
 //LCD_Init();
 //UART_receiveString(in_arr);
 //
 //if(!strcmp(in_arr,"3101AA00"))
 //{
 //if(sec_flag==0)
 //{
 //LCD_Clear();
 //LCD_GoTo(1,1);
 //LCD_SendString("NRC 7F 31 35");
 //_delay_ms(5000);
 //Have_Security();
 //}
 //else if(sec_flag==1)
 //{
 //LCD_Clear();
 //LCD_GoTo(1,1);
 //LCD_SendString("7101AA00");
 //setpinvalue(PINC4, HIGH);
 //}
 //
 //}
 //}
 //return 0;
 //}
 //
 //void Have_Security()
 //{
 //
 //UART_receiveString(in_arr);
 //
 //if(!strcmp(in_arr,"2701"))
 //{
 //LCD_Clear();
 //LCD_GoTo(1, 1);
 //LCD_SendString("6701 ");
 //
 //for(u8 i=0;i<8;i++)
 //{
 //ran_arr[i]=(rand()%10);
 //ran_arr[i]+=48;
 //}
 //
 //for(u8 i=0;i<8;i++)
 //{
 //LCD_SendChar(ran_arr[i]);
 //}
 //for(u8 i=0;i<8;i++)
 //{
 //if(ran_arr[i]=='9')
 //{
 //ran_arr[i]='0';
 //continue;
 //}
 //ran_arr[i]++;
 //}
 //ran_arr[8]='\0';
 //
 //for(u8 i=0;i<8;i++)
 //{
 //in_arr[i]=0;
 //}
 //UART_receiveString(req_arr);
 //UART_receiveString(in_arr);
 //
 //if(!strcmp(in_arr,ran_arr))
 //{
 //sec_flag=1;
 //LCD_Clear();
 //LCD_GoTo(1,1);
 //LCD_SendString("6701 ");
 //}
 //else
 //{
 //sec_flag=0;
 //LCD_Clear();
 //LCD_GoTo(1,1);
 //LCD_SendString("7F 27 35");
 //}
 //
 //}
 //}
 //void UART_receiveString(u8 *Str)
 //{
 //u8 i = 0;
 //Str[i] = USART_Receive();
 //while(Str[i] != '\n')
 //{
 //i++;
 //Str[i] = USART_Receive();
 //}
 //Str[i] = '\0';
 //}
//#endif /* SERVICE_H_ */