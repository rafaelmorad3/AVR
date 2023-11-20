#include "Std_Types.h"
#include "BitMath.h"

#include "GIE_Interface.h"
#include "GIE_Private.h"

void GIE_voidEnable(void)
{
	SETBIT(SREG,7);
}

void GIE_voidDisable(void)
{
	CLRBIT(SREG,7);
}