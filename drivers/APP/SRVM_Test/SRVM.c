#include "StdTypes.h"
#include "DIO/DIO_Inteface.h"
#include "Timer/Timer1/Timer1_Interface.h"
#include "SRV_Motor/SRV_Motor_Interface.h"
#include "SRVM.h"

void SRV_Motor_init()
{
	SRV_Init();
}

void SRV_Motor_runnable()
{
	SRV_Motor_Start(0);
}



