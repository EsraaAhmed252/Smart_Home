#include "StdTypes.h"
#include "MemMap.h"
#include "UTILS.h"
#include "Routines.h"

#include "Timer/Timer1/Timer1_Interface.h"
#include "Timer/Timer1_Cfg.h"

void (*p2f_11)()=NULL_PTR;
void (*p2f_12)()=NULL_PTR;
void (*p2f_13)()=NULL_PTR;

void timer1_init(void)
{
#if Timer0_mode==Normal_mode  //mode
	CLR_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	CLR_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);

#elif Timer0_mode==PWM_mode
	SET_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	CLR_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);

#elif Timer0_mode==CTC_mode
	CLR_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);

#elif Timer0_mode==Fast_PWM_mode

	#if Timer0_modeofcmp==Non_Inverting  //cmp_mode
		TCCR1A|=(Non_Inverting<<6);

	#elif Timer0_modeofcmp==Inverting
		TCCR1A|=(Inverting<<6);

	#endif

		CLR_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		SET_BIT(TCCR1B,3);
		SET_BIT(TCCR1B,4);

#endif
	return;
}

void timer1_start(void)
{
	TCCR1B &= 0xf8;
	TCCR1B |=Timer1_Prescaler;
	return;
}

void timer1_int_value(u16 value)
{
	TCNT1=value;
	return ;
}

void timer1_max_value(u16 value)
{
	ICR1=value;
	return ;
}

u16 timer1_set_cmp(u8 duty,u32 freq)
{
	#if Timer1_Prescaler==_1_prescalar  //mode
		u16 ICR1_value=(16000000/(freq))-1;

	#elif Timer1_Prescaler==_8_prescalar
		u16 ICR1_value=(2000000/(freq))-1;

	#elif Timer1_Prescaler==_64_prescalar
		u16 ICR1_value=(1000000/(freq*4))-1;

	#elif Timer1_Prescaler==_256_prescalar
		u16 ICR1_value=(1000000/(freq*16))-1;

	#elif Timer1_Prescaler==_1024_prescalar
		u16 ICR1_value=(1000000/(freq*64))-1;

#endif

		timer1_max_value(ICR1_value);

	#if Timer1_modeofcmp==Inverting
		duty=100-duty;
	#endif

	u32 OCR1A_value;
	OCR1A_value=(duty*ICR1_value/100);

	return OCR1A_value;
}

void timer1_cmp_value(u16 value)
{
	OCR1A=value;
	return ;
}

////stops the timer///
void timer1_stop(void)
{
	TCCR1B&=0xf8;
	return;
}

void timer1_int_enable(void)
{
#if Timer0_mode==Normal_mode  //mode
	SET_BIT(TIMSK,0);

#elif Timer0_mode==CTC_mode
	SET_BIT(TIMSK,1);

#endif
	return ;
}

void timer1_of_set_callbck(void (*p2f_var)(void))
{
	if(p2f_var!=NULL_PTR)
	{
		p2f_11=p2f_var;
	}
}

void timer1_cmpA_set_callbck(void (*p2f_var)(void))
{
	if(p2f_var!=NULL_PTR)
	{
		p2f_12=p2f_var;
	}
}

void timer1_cmpB_set_callbck(void (*p2f_var)(void))
{
	if(p2f_var!=NULL_PTR)
	{
		p2f_13=p2f_var;
	}
}

ISR(TIMER1_OVF_vect)
{
	p2f_11();
}
ISR(TIMER1_COMPB_vect)
{
	p2f_12();
}
ISR(TIMER1_COMPA_vect)
{
	p2f_13();
}



