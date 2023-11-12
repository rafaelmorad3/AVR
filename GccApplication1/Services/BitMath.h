/*
 * BitMath.h
 *
 * Created: 23/10/21 10:49:34 AM
 *  Author: Raphael Mourad
 */ 


#ifndef BITMATH_H_
#define BITMATH_H_

#define SET_BIT(p,n) ((p) |= (1 << (n)))
#define CLR_BIT(p,n) ((p) &= (~(1) << (n)))
#define TOGGLE_BIT(p,n) ((p) ^= (1 << (n)))
#define GET_BIT(p,n)   ((p&(1<<n))>>n)



#endif /* BITMATH_H_ */