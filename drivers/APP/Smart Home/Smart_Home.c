#include "StdTypes.h"
#include "Utils.h"
#include "DIO/DIO_Inteface.h"
#include "GI/GI_Interface.h"
#include "ADC/ADC_Interface.h"
#include "Ext_Int/Ext_Int_Interface.h"
#include "Timer/Timer2/Timer2_Interface.h"
#include "DC_Motor/DC_Motor_Interface.h"
#include "SRV_Motor/SRV_Motor_interface.h"
#include "LCD/LCD_Interface.h"
#include "KeyPad/KeyPad_Cfg.h"
#include "KeyPad/KeyPad_Interface.h"
#include "Sensors/Sensors_Interface.h"
#include "SPI/SPI_Interface.h"
#include "EEPROM/EEPROM_Interface.h"
#include "Smart_Home.h"

static u8 id_g,pass_g,func_g;
u8 mode_flag;

void start_screen()
{
	LCD_Clear();
	LCD_SETCURSOR(LINE1,0);
	LCD_WriteString("User ID:");
	LCD_SETCURSOR(LINE2,0);
	LCD_WriteString("Password:");
}

void options_screen()
{
	LCD_Clear();
	LCD_WriteString("Select Operation :");
	_delay_ms(500);
	LCD_Clear();
	LCD_SETCURSOR(LINE1,0);
	LCD_WriteString("1.Control Led");
	LCD_SETCURSOR(LINE2,0);
	LCD_WriteString("2.Control Door");
	LCD_SETCURSOR(LINE3,0);
	LCD_WriteString("3.Control Fan");
	LCD_SETCURSOR(LINE4,0);
	LCD_WriteString("4.Control Dimmer");
}

void leds_screen()
{
	LCD_Clear();
	LCD_SETCURSOR(LINE1,0);
	LCD_WriteString("Select Led:");
	LCD_SETCURSOR(LINE2,0);
	LCD_WriteString("1.Led 1");
	LCD_SETCURSOR(LINE2,8);
	LCD_WriteString("2.Led 2");
	LCD_SETCURSOR(LINE3,0);
	LCD_WriteString("3.Led 3");
	LCD_SETCURSOR(LINE3,8);
	LCD_WriteString("4.Led 4");
	LCD_SETCURSOR(LINE4,0);
	LCD_WriteString("5.Led 5");
	LCD_SETCURSOR(LINE4,8);
	LCD_WriteString("6.LEDS OFF");
}

void leds_status_screen()
{
	LCD_Clear();
	LCD_SETCURSOR(LINE1,0);
	LCD_WriteString("Select Status:");
	LCD_SETCURSOR(LINE2,0);
	LCD_WriteString("1.ON");
	LCD_SETCURSOR(LINE3,0);
	LCD_WriteString("2.OFF");
}

void ctrl_led(u8* led_num,u8* led_state)
{
	leds_screen();
	u8 f=1;
	while(f)
	{
		u8 keyy=KeyPad_get();
		if(keyy!=NO_KEY)
		{
			if(keyy=='6')
			{
				DIO_WritePort(PD,((0xE0&DIO_ReadPort(PD))));
				return ;
			}
			*led_num=keyy-'0';
			leds_status_screen();
			while(f)
				{
					keyy=KeyPad_get();
					if(keyy!=NO_KEY)
					{
						*led_state=keyy-'0';
						f=0;
					}
				}
		}
	}

}

void Door_status_screen()
{
	LCD_Clear();
	LCD_SETCURSOR(LINE1,0);
	LCD_WriteString("Select Status:");
	LCD_SETCURSOR(LINE2,0);
	LCD_WriteString("1.OPEN");
	LCD_SETCURSOR(LINE3,0);
	LCD_WriteString("2.CLOSE");
}

void ctrl_door(u8* door_status)
{
	Door_status_screen();
	u8 f=1;
	while(f)
	{
		u8 keyy=KeyPad_get();
		if(keyy!=NO_KEY)
		{
			*door_status=keyy-'0';
			f=0;
		}
	}
}

void Dimmer_screen()
{
	LCD_Clear();
	LCD_SETCURSOR(LINE1,0);
	LCD_WriteString("Enter Speed(0 to 99)");
	LCD_SETCURSOR(LINE2,0);
}

void ctrl_dimmer(u8* speed)
{
	Dimmer_screen();
	u8 f=0,num=0;
	while(f<2)
	{
		u8 keyy=KeyPad_get();
		if(keyy!=NO_KEY)
		{
			LCD_WriteChar(keyy);
			num=num*10+(keyy-'0');
			f++;
		}
	}
	*speed=num;
	_delay_ms(50);
}

void Led_Control(DIO_Pin_type LedNumber , LED_Status_t LedState)
{
	if(LED_ON == LedState)
	{
		DIO_WritePin(LedNumber , HIGH);
	}
	else if(LED_OFF == LedState)
	{
		DIO_WritePin(LedNumber , LOW);
	}
}

void Door_Control(Door_Status_t DoorState)
{
	if(DOOR_CLOSE == DoorState)
	{
		SRV_Motor_Start(45);
	}
	else if(DOOR_OPEN == DoorState)
	{
		SRV_Motor_Start(90);
	}
}

u8 Fan_Control(void)
{
	u8 temp = 0 ;
	temp = Temp_Read();

	if( MAX_TEMP < temp)
	{
		MOTOR_CW(M1);
	}
	else if( MIN_TEMP > temp )
	{
		MOTOR_Stop(M1);
	}
	return temp;
}

void Dimmer_Control(u8 duty)
{
	if((duty < 100)&&(duty > 0))
	{
		timer2_cmp_value(timer2_set_cmp(duty));
		timer2_start();
	}
	else if(duty==0)
	{
		timer2_stop();
		DIO_WritePin(PIND7,LOW);
	}
}

void SH_init()
{
	DIO_Init();
	LCD_init();
	GIE_Enable();
	ADC_init(VREF_AVCC,ADC_SCALER_64);
	EXTI_Enable(EXTI2,EXTI_RISING_EDGE);
	KeyPad_init();
	MOTOR_Init();
	SRV_Init();
	SPI_init();
	timer2_init();
	EEPROM_init();
	EEPROM_WriteByte(0,123);

	mode_flag=init_mode;
	start_screen();
}

void SH_Runnable()
{
	if(mode_flag==init_mode)
	{
		static u8 pass_trails = 0;
		u8 num = 0;
		u8 i=0;
		LCD_SETCURSOR(LINE1,8);
		while(i<3)
		{

			if(mode_flag==admin_mode)
			{
				return ;
			}
			u8 id=KeyPad_get();
			if(id!=NO_KEY)
				{
					LCD_WriteChar(id);
					num=num*10+(id-'0');
					i++;
				}
		}
		u8 x;
		EEPROM_ReadByte(num*2,&x);
		if(x==255)
		{
			LCD_Clear();
			LCD_WriteString("Wrong ID !");
			_delay_ms(500);
			LCD_Clear();
			start_screen();
		}
		else
		{
			u16 num2 = 0;
			u8 i2=0;
			LCD_SETCURSOR(LINE2,9);
			while(i2<3)
			{
				if(mode_flag==admin_mode)
				{
					return ;
				}
				u8 pass=KeyPad_get();
				if(pass!=NO_KEY)
					{
						LCD_WriteChar('*');
						num2=num2*10+(pass-'0');
						i2++;
					}
			}
			_delay_ms(50);
			if(x!=num2)
			{
				pass_trails++;
				LCD_Clear();
				LCD_WriteString("Wrong Password !");
				_delay_ms(500);
				if(pass_trails==3)
				{
					while(1)
					{
						DIO_WritePin(PINA7,HIGH);
						_delay_ms(500);
						DIO_WritePin(PINA7,LOW);
						_delay_ms(500);
					}
				}
				LCD_Clear();
				start_screen();
			}
			else
			{
				pass_trails=0;
				mode_flag=user_mode;
				options_screen();
			}
		}

	}

	else if(mode_flag==user_mode)
	{
		u8 led,state,speed,temp;
		u8 k=KeyPad_get();
		if(k!=NO_KEY)
		{
			Fan_Control();
			switch (k)
			{
				case '1':
					{
					led=0;
					state=0;
					ctrl_led(&led,&state);
					Led_Control(led+23,state);
					break;}
				case '2':
					{ctrl_door(&state);
					Door_Control(state);
					break;}
				case '3':
					{temp=Fan_Control();
					LCD_Clear();
					LCD_WriteString("Temperature : ");
					LCD_WriteNumber(temp);
					_delay_ms(500);
					break;}
				case '4':
					{ctrl_dimmer(&speed);
					Dimmer_Control(speed);
					break;}
				default:
					break;
			}
			options_screen();
		}
	}

	else if(mode_flag==admin_mode)
	{
		LCD_Clear();
		LCD_WriteString("Receiving data from ADMIN...");
		DIO_WritePin(PIND6,HIGH);
		func_g = SPI_Transceive(1);

		if(func_g == 1)
		{
			id_g = SPI_Transceive(2);
			pass_g = SPI_Transceive(3);
			EEPROM_WriteByte(id_g*2,pass_g);
		}
		else if(func_g == 2)
		{
			id_g = SPI_Transceive(1);
			EEPROM_WriteByte(id_g*2,255);
		}
		_delay_ms(50);
		LCD_Clear();
		LCD_WriteString("Data has been");
		LCD_SETCURSOR(LINE2,0);
		LCD_WriteString("received succesfully");
		DIO_WritePin(PIND6,LOW);
		_delay_ms(400);
		LCD_Clear();
		mode_flag = init_mode;
		start_screen();
	}


}
