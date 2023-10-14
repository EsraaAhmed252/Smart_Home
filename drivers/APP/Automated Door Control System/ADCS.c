#include "StdTypes.h"
#include "Utils.h"
#include "DIO/DIO_Inteface.h"
#include "SRV_Motor/SRV_Motor_Interface.h"
#include "LCD/LCD_Interface.h"
#include "KeyPad/KeyPad_Cfg.h"
#include "KeyPad/KeyPad_Interface.h"
#include "ADCS.h"

void ADCS_init()
{
	SRV_Init();
	SRV_Motor_Stop();
	DIO_WritePin(led,LOW);
	DIO_WritePin(buzzer,LOW);
}

void ADCS_Runnable()
{
	static u8 pass_trails = 0;
	u16 num = 0;
	u8 i = 0;
	LCD_Clear();
	LCD_WriteString("Enter Password:");
	while(i<4)
	{
		u8 k=KeyPad_get();
		if(k!=NO_KEY)
			{
				LCD_WriteChar(k);
				num=num*10+(k-'0');
				i++;
			}
	}
	_delay_ms(100);

	if(num==Password)
	{
		LCD_Clear();
		LCD_WriteString("Welcome !");
		SRV_Motor_Start(Door_open);
		_delay_ms(2000);
		SRV_Motor_Start(Door_close);
		LCD_Clear();
	}
	else
	{
		pass_trails++;
		LCD_Clear();
		LCD_WriteString("Wrong Password !");
		_delay_ms(500);
		if(pass_trails==3)
		{
			while(1)
			{
				DIO_WritePin(led,HIGH);
				DIO_WritePin(buzzer,HIGH);
				_delay_ms(200);
				DIO_WritePin(led,LOW);
				DIO_WritePin(buzzer,LOW);
				_delay_ms(200);
			}
		}
	}
}
