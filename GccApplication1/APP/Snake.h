/*
 * Snake.h
 *
 * Created: 23/10/23 10:05:08 AM
 *  Author: Shiko
 */ 


#ifndef SNAKE_H_
#define SNAKE_H_

#define P0  PIN7
#define P1  PIN6
#define P2  PIN5
#define P3  PIN3
#define Button_Port PD
typedef enum{
	UP,
	DOWN,
	RIGHT,
	LEFT
}Directions_t;


void Snake_Init(void);
void Snake_Runnable(void);





#endif /* SNAKE_H_ */