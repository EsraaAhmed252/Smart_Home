#include "StdTypes.h"
#include "Utils.h"
#include "DIO/DIO_Inteface.h"
#include "DC_Motor/DC_Motor_Interface.h"
#include "LCD/LCD_Interface.h"
#include "KeyPad/KeyPad_Cfg.h"
#include "KeyPad/KeyPad_Interface.h"
#include "Calculator/Calculator.h"

u8 k,f1,f2;
s32 num1,num2;

void Calculator_init()
{
	cancel();
}

void Calculator_Runnable()
{
	k=KeyPad_get();
	if (k!=NO_KEY)
	{
		if (k>='0'&&k<='9')
		{
			num();
		}
		else
		{
			switch (k)
			{
			case '=':
				equ1();
				break;
			case '+':
				add1();
				break;
			case '-':
				sub1();
				break;
			case '*':
				mul1();
				break;
			case '/':
				div1();
				break;
			case 'N':
				cancel();
				break;
			}
		}	
	}
}

void num(void)
{
	if (f1==1)
	{
		LCD_Clear();
		num1=0;
		num2=0;
		f1=0;
	}
	num1=num1*10+(k-'0');
	LCD_WriteChar(k);
	f2=1;
}

void equ(void)
{
	LCD_Clear();
	LCD_WriteNumber(num2);
}

void add(void)
{
	if (f2==0)
	{
		LCD_SETCURSOR(LINE1,cursor_cell-1);
	}
	else
	{
		num2+=num1;
		LCD_Clear();
		LCD_WriteNumber(num2);
	}
}

void sub(void)
{
	if (f2==0)
	{
		LCD_SETCURSOR(LINE1,cursor_cell-1);
	}
	else
	{
		num2=num2-num1;
		LCD_Clear();
		LCD_WriteNumber(num2);
	}
}

void mul(void)
{
	if (f2==0)
	{
		LCD_SETCURSOR(LINE1,cursor_cell-1);
	}
	else
	{
		num2*=num1;
		LCD_Clear();
		LCD_WriteNumber(num2);
	}
}

void div(void)
{
	if (f2==0)
	{
		LCD_SETCURSOR(LINE1,cursor_cell-1);
	}
	else
	{
		if (num1==0)
		{
			LCD_WriteString("ERROR");
		}
		else
		{
			num2/=num1;
			LCD_Clear();
			LCD_WriteNumber(num2);
		}
	}
}

void cancel(void)
{
	f1=0;
	f2=0;
	num1=0;
	num2=0;
	LCD_Clear();
}

void equ1(void)
{
	LCD_SETCURSOR(LINE2,0);
	switch (f1)
	{
	case 0:
		LCD_WriteNumber(num1);
		break;
	case 2:
		LCD_WriteNumber(num2+num1);
		num2+=num1;
		break;
	case 3:
		LCD_WriteNumber(num2-num1);
		num2-=num1;
		break;
	case 4:
		LCD_WriteNumber(num2*num1);
		num2*=num1;
		break;
	case 5:
		if (num1==0)
		{
			LCD_WriteString("ERROR");
		}
		else
		{
			LCD_WriteNumber(num2/num1);
			num2/=num1;
		}
		break;
	}
	f1=1;
}

void add1(void)
{
	switch (f1)
	{
	case 0:
		num2=num1;
		break;
	case 1:
		equ();
		break;
	case 2:
		if (f2==1)
		{
			num2+=num1;
			equ();
		}
		break;
	case 3:
		sub();
		break;
	case 4:
		mul();
		break;
	case 5:
		div();
		break;
	}
	f1=2;
	f2=0;
	num1=0;
	LCD_WriteChar('+');
}

void sub1(void)
{
	switch (f1)
	{
	case 0:
		num2=num1;
		break;
	case 1:
		equ();
		break;
	case 2:
		add();
		break;
	case 3:
		if (f2==1)
		{
			num2-=num1;
			equ();
		}
		break;
	case 4:
		mul();
		break;
	case 5:
		div();
		break;
	}
	f1=3;
	f2=0;
	num1=0;
	LCD_WriteChar('-');
}

void mul1(void)
{
	switch (f1)
	{
	case 0:
		num2=num1;
		break;
	case 1:
		equ();
		break;
	case 2:
		add();
		break;
	case 3:
		sub();
		break;
	case 4:
		if (f2==1)
		{
			num2*=num1;
			equ();
		}
		break;
	case 5:
		div();
		break;
	}
	num1=0;
	f1=4;
	f2=0;
	LCD_WriteChar('*');
}

void div1(void)
{
	switch (f1)
	{
	case 0:
		num2=num1;
		break;
	case 1:
		equ();
		break;
	case 2:
		add();
		break;
	case 3:
		sub();
		break;
	case 4:
		mul();
		break;
	case 5:
		if (f2==1)
		{
			if (num1==0)
			{
				LCD_WriteString("ERROR");
			}
			else
			{
				num2/=num1;
				equ();
			}
		}
		break;
	}
	num1=0;
	f1=5;
	f2=0;
	LCD_WriteChar('/');
}
