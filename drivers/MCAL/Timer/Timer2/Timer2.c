#include "StdTypes.h"
#include "MemMap.h"
#include "UTILS.h"
#include "Routines.h"

#include "Timer/Timer2/Timer2_Interface.h"
#include "Timer/Timer2_Cfg.h"

void (*p2f_2)()=NULL_PTR;

void timer2_init(void)
{
#if Timer2_mode==Normal_mode  //mode
	CLR_BIT(TCCR2,6);
	CLR_BIT(TCCR2,3);

#elif Timer2_mode==PWM_mode
	SET_BIT(TCCR2,6);
	CLR_BIT(TCCR2,3);

#elif Timer2_mode==CTC_mode
	CLR_BIT(TCCR2,6);
	SET_BIT(TCCR2,3);

#elif Timer2_mode==Fast_PWM_mode

	#if Timer2_modeofcmp==Non_Inverting  //cmp_mode
		TCCR2|=(Non_Inverting<<4);

	#elif Timer2_modeofcmp==Inverting
		TCCR2|=(Inverting<<4);

	#endif

	SET_BIT(TCCR2,6);
	SET_BIT(TCCR2,3);

#endif
	return;
}

void timer2_start(void)
{
	TCCR2 &= 0xf8;
	TCCR2 |=Timer2_Prescaler;
	return;
}

void timer2_int_value(u8 value)
{
	TCNT2=value;
	return ;
}

u8 timer2_set_cmp(u8 duty)
{
	u8 OCR2_value;
	#if Timer2_modeofcmp==Inverting
		duty=100-duty;
	#endif

	OCR2_value=(duty*resoultion/100)-1;

	return OCR2_value;
}

u8 timer2_set_cmp_PC (u8 duty){

	u8 OCR2_value;
	#if Timer2_modeofcmp==Inverting
		duty=100-duty;
	#endif

	OCR2_value = ((duty*resoultion/50)-1);
}

void timer2_cmp_value(u8 value)
{
	OCR2=value;
	return ;
}

////stops the timer///
void timer2_stop(void)
{
	TCCR2&=0xf8;
	return;
}

void timer2_int_enable(void)
{
#if Timer2_mode==Normal_mode  //mode
	SET_BIT(TIMSK,0);

#elif Timer2_mode==CTC_mode
	SET_BIT(TIMSK,1);

#endif
	return ;
}

void timer2_of_set_callbck(void (*p2f_var)(void))
{
	if(p2f_var!=NULL_PTR)
	{
		p2f_2=p2f_var;
	}
}

void timer2_cmp_set_callbck(void (*p2f_var)(void))
{
	if(p2f_var!=NULL_PTR)
	{
		p2f_2=p2f_var;
	}
}

ISR(TIMER2_OVF_vect)
{
	p2f_2();
}

ISR(TIMER2_COMP_vect)
{
	p2f_2();
}


