#include "StdTypes.h"
#include "MemMap.h"
#include "UTILS.h"
#include "GI/GI_Interface.h"

void GIE_Enable(void)
{
	SET_BIT(SREG,7);
}

void GIE_Disable(void)
{
	CLR_BIT(SREG,7);
}


