#include "StdTypes.h"
#include "MemMap.h"
#include "UTILS.h"
#include "Routines.h"

#include "Timer/WDT/WDT_Interface.h"

void WDT_Enable(float prescaler)
{
	WDTCR &= 0xF8;
	if(prescaler==WDT_TO_16_3ms)
	{

	}
	else if(prescaler==WDT_TO_32_5ms)
	{
		WDTCR |=0xF9;
	}
	else if(prescaler==WDT_TO_65ms)
	{
		WDTCR |=0xFA;
	}
	else if(prescaler==WDT_TO_130ms)
	{
		WDTCR |=0xFB;
	}
	else if(prescaler==WDT_TO_260ms)
	{
		WDTCR |=0xFC;
	}
	else if(prescaler==WDT_TO_520ms)
	{
		WDTCR |=0xFD;
	}
	else if(prescaler==WDT_TO_1s)
	{
		WDTCR |=0xFE;
	}
	else if(prescaler==WDT_TO_2_1s)
	{
		WDTCR |=0xFF;
	}

	SET_BIT(WDTCR,3);
}

void WDT_Disable(void)
{
	WDTCR |= (3<<3);
	WDTCR &=~ (1<<4);
}
