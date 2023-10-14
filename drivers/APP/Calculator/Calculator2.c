/*
#include "StdTypes.h"
#include "Utils.h"
#include "DIO/DIO_Inteface.h"
#include "DC_Motor/DC_Motor_Interface.h"
#include "LCD/LCD_Interface.h"
#include "KeyPad/KeyPad_Cfg.h"
#include "KeyPad/KeyPad_Interface.h"
#include "Calculator/Calculator2.h"
u8 k2,f12,f22;
s32 num12,num22;

void Calculator_init2()
{
	cancel2();
	LCD_SETCURSOR(LINE2,3);
	LCD_WriteString("Calculator By:");
	LCD_SETCURSOR(LINE3,3);
	LCD_WriteString("Mohamed AlSoly");
	_delay_ms(1500);
	LCD_Clear();
}

void Calculator_Runnable2()
{
	k2=KeyPad_get();
	if (k2!=NO_KEY)
	{
		if (k2>='0'&&k2<='9')
		{
			num2();
		}
		else
		{
			switch (k2)
			{
				case '=':
				equ12();
				break;
				case '+':
				add12();
				break;
				case '-':
				sub12();
				break;
				case '*':
				mul12();
				break;
				case '/':
				div12();
				break;
				case 'N':
				cancel2();
				break;
			}
		}
	}
}

void num2(void)
{
	if (f12==1)
	{
		LCD_Clear();
		num12=0;
		num22=0;
		f12=0;
	}
	num12=num12*10+(k2-'0');
	if(f12>5)
	{
		num12*=-1;
		f12-=10;
	}
	LCD_WriteChar(k2);
	f22=1;
}

void equ2(void)
{
	LCD_Clear();
	LCD_WriteNumber(num22);
}

void add2(void)
{
	if (f22==0)
	{
		LCD_SETCURSOR(LINE1,cursor_cell-1);
	}
	else
	{
		num22+=num12;
		LCD_Clear();
		LCD_WriteNumber(num22);
	}
}

void sub2(void)
{
	if (f22==0)
	{
		LCD_SETCURSOR(LINE1,cursor_cell-1);
	}
	else
	{
		num22-=num12;
		LCD_Clear();
		LCD_WriteNumber(num22);
	}
}

void mul2(void)
{
	if (f22==0)
	{
		LCD_SETCURSOR(LINE1,cursor_cell-1);
	}
	else
	{
		num22*=num12;
		LCD_Clear();
		LCD_WriteNumber(num22);
	}
}

void div2(void)
{
	if (f22==0)
	{
		LCD_SETCURSOR(LINE1,cursor_cell-1);
	}
	else
	{
		if (num12==0)
		{
			LCD_WriteString("ERROR");
		}
		else
		{
			num22/=num12;
			LCD_Clear();
			LCD_WriteNumber(num22);
		}
	}
}

void cancel2(void)
{
	f12=0;
	f22=0;
	num12=0;
	num22=0;
	LCD_Clear();
}

void equ12(void)
{
	LCD_SETCURSOR(LINE4,0);
	switch (f12)
	{
		case 0:
		LCD_WriteNumber(num12);
		break;
		case 2:
		LCD_WriteNumber(num22+num12);
		num22+=num12;
		break;
		case 3:
		LCD_WriteNumber(num22-num12);
		num22-=num12;
		break;
		case 4:
		LCD_WriteNumber(num22*num12);
		num22*=num12;
		break;
		case 5:
		if (num12==0)
		{
			LCD_WriteString("ERROR");
		}
		else
		{
			LCD_WriteNumber(num22/num12);
			num22/=num12;
		}
		break;
	}
	f12=1;
}

void add12(void)
{
	switch (f12)
	{
		case 0:
		num22=num12;
		break;
		case 1:
		equ2();
		break;
		case 2:
		if (f22==1)
		{
			num22+=num12;
			equ2();
		}
		break;
		case 3:
		sub2();
		break;
		case 4:
		mul2();
		break;
		case 5:
		div2();
		break;
	}
	f12=2;
	f22=0;
	num12=0;
	LCD_WriteChar('+');
}

void sub12(void)
{
	switch (f12)
	{
		case 0:
			num22=num12;
			f12=3;
		break;
		case 1:
			equ2();
			f12=3;
		break;
		case 2:
			if (f22==0)
			{
				LCD_WriteChar(' ');
				f12=12;
			}
		else
			{
				num22+=num12;
				LCD_Clear();
				LCD_WriteNumber(num22);
				f12=3;
			}
		break;
		case 3:
			if (f22==1)
			{
				num22-=num12;
				equ2();
				}
			else
			{
				if (f22==0)
				{
					LCD_WriteChar(' ');
					f12=13;
				}
				else
				{
					num22-=num12;
					LCD_Clear();
					LCD_WriteNumber(num22);
				}
			}
		break;
		case 4:
			if (f22==0)
			{
				LCD_WriteChar(' ');
				f12=14;
			}
			else
			{
				num22*=num12;
				LCD_Clear();
				LCD_WriteNumber(num22);
				f12=3;
			}
		break;
		case 5:
			if (f22==0)
			{
				LCD_WriteChar(' ');
				f12=15;
			}
			else
			{
				if (num12==0)
				{
					LCD_WriteString("ERROR");
				}
				else
				{
					num22/=num12;
					LCD_Clear();
					LCD_WriteNumber(num22);
					f12=3;
				}
			}
		break;
	}
	f22=0;
	num12=0;
	LCD_WriteChar('-');
}

void mul12(void)
{
	switch (f12)
	{
		case 0:
		num22=num12;
		break;
		case 1:
		equ2();
		break;
		case 2:
		add2();
		break;
		case 3:
		sub2();
		break;
		case 4:
		if (f22==1)
		{
			num22*=num12;
			equ2();
		}
		break;
		case 5:
		div2();
		break;
	}
	f12=4;
	f22=0;
	num12=0;
	LCD_WriteChar('*');
}

void div12(void)
{
	switch (f12)
	{
		case 0:
		num22=num12;
		break;
		case 1:
		equ2();
		break;
		case 2:
		add2();
		break;
		case 3:
		sub2();
		break;
		case 4:
		mul2();
		break;
		case 5:
		if (f22==1)
		{
			if (num12==0)
			{
				LCD_WriteString("ERROR");
			}
			else
			{
				num22/=num12;
				equ2();
			}
		}
		break;
	}
	f12=5;
	f22=0;
	num12=0;
	LCD_WriteChar('/');
}
*/
