#include "StdTypes.h"
#include "DIO/DIO_Inteface.h"
#include "Ext_Int/Ext_Int_Interface.h"
#include "Smart Home/Smart_Home.h"

extern u8 mode_flag;

void Admin_Mode_Activate (void);

int main(void)
{
	SH_init();
	EXTI2_SetCallBack(Admin_Mode_Activate);

	while (1)
	{
		SH_Runnable();
	}
}

void Admin_Mode_Activate (void)
{
	mode_flag = admin_mode;
}
