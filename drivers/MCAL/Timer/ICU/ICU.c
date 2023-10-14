#include "StdTypes.h"
#include "MemMap.h"
#include "UTILS.h"
#include "Routines.h"

#include "Timer/ICU/ICU_Interface.h"
#include "Timer/ICU_Cfg.h"

void ICU_init(void)
{
	CLR_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	CLR_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);

#if ICU_Starting_Edge==ICU_Rising_edge
	SET_BIT(TCCR1B,6);
#elif ICU_Starting_Edge==ICU_falling_edge
	CLR_BIT(TCCR1B,6);
#endif

	SET_BIT(TIMSK,5);

	SET_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
}

void ICU_get_Duty_Cycle(u8 * duty)
{

}

void ICU_get_Frequency(u32 * frequency)
{

}

ISR(INT1_vect)
{
	static u8 edge_f = ICU_Starting_Edge;

}
