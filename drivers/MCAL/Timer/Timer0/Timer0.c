#include "StdTypes.h"
#include "MemMap.h"
#include "UTILS.h"
#include "Routines.h"

#include "Timer/Timer0/Timer0_Interface.h"
#include "Timer/Timer0_Cfg.h"

void (*p2f)()=NULL_PTR;

void timer0_init(void)
{
#if Timer0_mode==Normal_mode  //mode
	CLR_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);

#elif Timer0_mode==PWM_mode
	SET_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);

#elif Timer0_mode==CTC_mode
	CLR_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);

#elif Timer0_mode==Fast_PWM_mode

	#if Timer0_modeofcmp==Non_Inverting  //cmp_mode
		TCCR0|=(Non_Inverting<<4);

	#elif Timer0_modeofcmp==Inverting
		TCCR0|=(Inverting<<4);

	#endif

	SET_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);

#endif
	return;
}

void timer0_start(void)
{
	TCCR0 &= 0xf8;
	TCCR0 |=Timer0_Prescaler;
	return;
}

void timer0_int_value(u8 value)
{
	TCNT0=value;
	return ;
}

u8 timer0_set_cmp(u8 duty)
{
	u8 OCR0_value;
	#if Timer0_modeofcmp==Inverting
		duty=100-duty;
	#endif

	OCR0_value=(duty*resoultion/100)-1;

	return OCR0_value;
}

u8 timer0_set_cmp_PC (u8 duty){

	u8 OCR0_value;
	#if Timer0_modeofcmp==Inverting
		duty=100-duty;
	#endif

	OCR0_value = ((duty*resoultion/50)-1);
}

void timer0_cmp_value(u8 value)
{
	OCR0=value;
	return ;
}

////stops the timer///
void timer0_stop(void)
{
	TCCR0&=0xf8;
	return;
}

void timer0_int_enable(void)
{
#if Timer0_mode==Normal_mode  //mode
	SET_BIT(TIMSK,0);

#elif Timer0_mode==CTC_mode
	SET_BIT(TIMSK,1);

#endif
	return ;
}

void timer0_of_set_callbck(void (*p2f_var)(void))
{
	if(p2f_var!=NULL_PTR)
	{
		p2f=p2f_var;
	}
}

void timer0_cmp_set_callbck(void (*p2f_var)(void))
{
	if(p2f_var!=NULL_PTR)
	{
		p2f=p2f_var;
	}
}

ISR(TIMER0_OVF_vect)
{
	p2f();
}

ISR(TIMER0_COMP_vect)
{
	p2f();
}


