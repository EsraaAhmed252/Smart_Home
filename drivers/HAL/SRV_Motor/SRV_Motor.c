#include "StdTypes.h"
#include "DIO/DIO_Inteface.h"
#include "SRV_Motor/SRV_Motor_Interface.h"
#include "SRV_Motor/SRV_Motor_Cfg.h"
#include "Timer/Timer1/Timer1_Interface.h"

void SRV_Init(void)
{
	timer1_init();
}

void SRV_Motor_Start(s8 angle)
{
	u8 duty = (Max_duty*angle/Max_angle)+Min_duty;

	if(duty>Max_duty)
	{
		duty=Max_duty;
	}
	timer1_cmp_value(timer1_set_cmp(duty,Frequency));
	timer1_start();
}
void SRV_Motor_Stop(void)
{
	timer1_stop();
}
