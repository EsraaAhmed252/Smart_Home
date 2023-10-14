#include "StdTypes.h"
#include "DIO/DIO_Inteface.h"
#include "DC_Motor/DC_Motor_Interface.h"
#include "DC_Motor/DC_Motor_Cfg.h"
#include "Timer/Timer0/Timer0_Interface.h"


void MOTOR_Init(void)
{
	 MOTOR_Stop(M1);
	 MOTOR_Stop(M2);
	 MOTOR_Stop(M3);
	 MOTOR_Stop(M4);

}

void MOTOR_Stop(MOTOR_type m)
{
	m*=2;
	DIO_WritePin(MOTOR_PinsArr[m],LOW);
	DIO_WritePin(MOTOR_PinsArr[m+1],LOW);
}

void MOTOR_CW(MOTOR_type m)
{
	m*=2;
	DIO_WritePin(MOTOR_PinsArr[m],HIGH);
	DIO_WritePin(MOTOR_PinsArr[m+1],LOW);	
}

void MOTOR_CCW(MOTOR_type m)
{
	m*=2;
	DIO_WritePin(MOTOR_PinsArr[m],LOW);
	DIO_WritePin(MOTOR_PinsArr[m+1],HIGH);
}

void MOTOR_Speed(u8 speed)
{
	timer0_stop();
	timer0_init();
	timer0_cmp_value(timer0_set_cmp(speed));
	timer0_start();
}
