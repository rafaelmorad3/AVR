


#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

#define FIRST_OUTPUT   PINC5



#define ROWS   4
#define COLS   4

#define NO_KEY  'N'

#if KEYPAD_PRG

const u8 KeysARR[ROWS][COLS]={{'7','8','9','/'},
                              {'4','5','6','*'},
                              {'1','2','3','-'},
                              {'c','0','=','+'}};
								  
#endif								  

const DIO_Pin_type Col_ARR[COLS]={PIND7,PIND6,PIND5,PIND3};


#endif /* KEYPAD_CFG_H_ */