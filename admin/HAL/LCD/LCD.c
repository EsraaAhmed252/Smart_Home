#include "StdTypes.h"
#include "Utils.h"
#include "DIO/DIO_Inteface.h"
#include "LCD/LCD_Interface.h"
#include "LCD/LCD_Cfg.h"
#include "LCD/LCD_Private.h"

s8 cursor_line=0,cursor_cell=0;
Write_M mode=LtoR;


#if LCD_Mode==_8_BIT

static void WriteIns(u8 ins)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePort(LCD_PORT,ins);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

static void WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePort(LCD_PORT,data);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

void LCD_init()
{
	_delay_ms(50);
	WriteIns(0x38);
	WriteIns(Cursor_Mode);
	WriteIns(0x01);
	_delay_ms(1);
	WriteIns(mode);
}

#else

static void WriteIns(u8 ins)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePin(D7,READ_BIT(ins,7));
	DIO_WritePin(D6,READ_BIT(ins,6));
	DIO_WritePin(D5,READ_BIT(ins,5));
	DIO_WritePin(D4,READ_BIT(ins,4));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	
	DIO_WritePin(D7,READ_BIT(ins,3));
	DIO_WritePin(D6,READ_BIT(ins,2));
	DIO_WritePin(D5,READ_BIT(ins,1));
	DIO_WritePin(D4,READ_BIT(ins,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

static void WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePin(D7,READ_BIT(data,7));
	DIO_WritePin(D6,READ_BIT(data,6));
	DIO_WritePin(D5,READ_BIT(data,5));
	DIO_WritePin(D4,READ_BIT(data,4));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	
	DIO_WritePin(D7,READ_BIT(data,3));
	DIO_WritePin(D6,READ_BIT(data,2));
	DIO_WritePin(D5,READ_BIT(data,1));
	DIO_WritePin(D4,READ_BIT(data,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

void LCD_init()
{
	_delay_ms(50);
	WriteIns(0x02);
	WriteIns(0x28);
	WriteIns(Cursor_Mode);
	WriteIns(0x01);
	_delay_ms(1);
	WriteIns(mode);
}

#endif

void LCD_Clear()
{
	WriteIns(0x01);
	cursor_line=LINE1;
	cursor_cell=0;
	if ( mode == RtoL)
	{
		Write_Mode(RtoL);
		LCD_SETCURSOR(LINE1,15);
		cursor_cell=15;
	}
}

void Write_Mode(Write_M m)
{
	if (m==LtoR)
	{
		mode=LtoR;
		WriteIns(0x06);
	}
	else
	{
		mode=RtoL;
		WriteIns(0x04);
	}
}

void LCD_SETCURSOR(LINE_NUMBER line ,u8 cell)
{
	cursor_line=line;
	cursor_cell=cell;
	WriteIns((0x80+line)+cell);
}

void LCD_WriteChar(u8 data)
{
	if (mode == LtoR)
	{
		if (cursor_cell==20)
		{
			if (cursor_line==LINE1)
			{
				LCD_SETCURSOR(LINE2,0);
				cursor_line=LINE2;
				cursor_cell=0;
			}
			else if (cursor_line==LINE2)
			{
				LCD_SETCURSOR(LINE3,0);
				cursor_line=LINE3;
				cursor_cell=0;
			}
			else if (cursor_line==LINE3)
			{
				LCD_SETCURSOR(LINE4,0);
				cursor_line=LINE4;
				cursor_cell=0;
			}
			else if (cursor_line==LINE4)
			{
				LCD_SETCURSOR(LINE1,0);
				cursor_line=LINE1;
				cursor_cell=0;
			}
		}
		cursor_cell++;
	}
	else
	{
		if (cursor_cell<0)
		{
			if (cursor_line==LINE1)
			{
				LCD_SETCURSOR(LINE2,19);
				cursor_line=LINE2;
				cursor_cell=19;
			}
			else if(cursor_line==LINE2)
			{
				LCD_SETCURSOR(LINE3,19);
				cursor_line=LINE3;
				cursor_cell=19;
			}
			else if (cursor_line==LINE3)
			{
				LCD_SETCURSOR(LINE4,19);
				cursor_line=LINE4;
				cursor_cell=19;
			}
			else if (cursor_line==LINE4)
			{
				LCD_SETCURSOR(LINE1,19);
				cursor_line=LINE1;
				cursor_cell=19;
			}
		}
		cursor_cell--;
	}
	WriteData(data);
	
}

void LCD_WriteString(u8* s)
{
	for (u8 i = 0; s[i] ; i++)
	{
		LCD_WriteChar(s[i]);
	}
}

void LCD_WriteNumber(s32 num)
{
	u8 str[12];
	u8 i=0;
	if(num==0)
	{
		LCD_WriteChar('0');
	}
	if(num<0)
	{
		LCD_WriteChar('-');
		num*=-1;
	}
	while(num)
	{
		str[i]=num%10 + '0';
		num/=10;
		i++;
	}
	for (;i;i--)
	{
		LCD_WriteChar(str[i-1]);
	}
}

void LCD_WriteBinary(u32 num)
{
	u8 f=0;
	for(s8 i=31;i>=0;i--)
	{
		if ((f==0)&&(READ_BIT(num,i)?'1':'0')=='1')
		{
			f=1;
		}
		if (f==1)
		{
			LCD_WriteChar(READ_BIT(num,i)?'1':'0');
		}
		
	}
}

void LCD_WriteHex(u32 num)
{
	u8 f=0;
	LCD_WriteChar('0');
	LCD_WriteChar('x');
	for(s8 i = 28; i>=0 ; i-=4)
	{
		if (num>>i)
		{
			f=1;
		}
		if (f)
		{
			if((num>>i)>9)
			{
				LCD_WriteChar((num>>i)+55);
			}
			else
			{
				LCD_WriteChar((num>>i)+'0');
			}
		}
		
		num=num<<(32-i);
		num=num>>(32-i);
	}
	
}

void Insert_Char(u8 adress,u8* Character)
{
	if (mode == LtoR)
	{
		WriteIns(64+adress*8);
		for (u8 i=0 ; i<8 ; i++)
		{
			WriteData(Character[i]);
		}
	}
	else
	{
		WriteIns(64+((adress+1)*8)-1);
		for (u8 i=0 ; i<8 ; i++)
		{
			WriteData(Character[7-i]);
		}
	}
}

void Array_Fill(u8* arr,u8 p0,u8 p1,u8 p2,u8 p3,u8 p4,u8 p5,u8 p6,u8 p7)
{
	arr[0]=p0;
	arr[1]=p1;
	arr[2]=p2;
	arr[3]=p3;
	arr[4]=p4;
	arr[5]=p5;
	arr[6]=p6;
	arr[7]=p7;
}

