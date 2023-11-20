


#ifndef BITMATH_H_
#define BITMATH_H_

#define SETBIT(reg,bit)  (reg=reg|(1<<bit))
#define ToggleBIT(reg,bit)  (reg^=(1<<bit))
#define CLRBIT(reg,bit)  (reg=reg&(~(1<<bit)))
#define READBIT(reg,bit)  ((reg>>bit)&1)



#endif /* BITMATH_H_ */