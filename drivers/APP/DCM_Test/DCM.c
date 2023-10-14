#include "StdTypes.h"
#include "DIO/DIO_Inteface.h"
#include "DC_Motor/DC_Motor_Interface.h"
#include "DCM.h"

void DCM_init()
{
	MOTOR_Init();
}

void DCM_runnable()
{
	//MOTOR_CW(M1);
	MOTOR_Speed(50);
}



