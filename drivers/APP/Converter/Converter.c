#include "StdTypes.h"
#include "Utils.h"
#include "DIO/DIO_Inteface.h"
#include "DC_Motor/DC_Motor_Interface.h"
#include "LCD/LCD_Interface.h"
#include "KeyPad/KeyPad_Cfg.h"
#include "KeyPad/KeyPad_Interface.h"
#include "Converter/Converter.h"

static u8 k,num=0,cf=0,ct=0,f=0,b[8];
static u8 chars[6]={'A','B','C','D','E','F'};
static s8 bi=0,z=0;
void Converter_init()
{
	LCD_WriteString("  Converter by");
	LCD_SETCURSOR(LINE2,1);
	LCD_WriteString("Mohamed AlSoly");
	_delay_ms(1500);
	LCD_Clear();
}

void Converter_Runnable()
{
	if (f==0)
	{
		LCD_Clear();
		LCD_WriteString("Convert from ...");
		LCD_SETCURSOR(LINE2,0);
		LCD_WriteString("1-Dec 2-Bin 3-Hx");
		f=1;
	}
	else if (f==2)
	{
		LCD_Clear();
		LCD_WriteString("Convert from ");
		if (cf==DEC)
		{
			LCD_WriteString("DecTo  1-Bin 2-Hex");
		}
		else if (cf==BIN)
		{
			LCD_WriteString("BinTo  1-Dec 2-Hex");
		}
		else if (cf==HEX)
		{
			LCD_WriteString("HexTo  1-Dec 2-Bin");
		}
		f=3;
	}
	
	k=KeyPad_get();
	if ((((k=='A')||(k>='0'&&k<='9'))&&f==6)||f==4)
	{
		f=3;
		LCD_Clear();
		for (u8 i=cf;f<5; i=ct)
		{
			if (i==DEC)
			{
				LCD_WriteString("Dec:");
			}
			else if (i==BIN)
			{
				LCD_WriteString("Bin:");
			}
			else if (i==HEX)
			{
				LCD_WriteString("Hex:");
			}
			f++;
			LCD_SETCURSOR(LINE2,0);
		}
		LCD_SETCURSOR(LINE1,4);
	}
	
	if (k!=NO_KEY)
	{
		if (k=='N')
		{
			f=0;
		}
		switch (f)
		{
			case 1:
			if(k=='1') {cf=DEC;}
			else if(k=='2') {cf=BIN;}
			else if(k=='3') {cf=HEX;}
			f=2;
			if((k!='1')&&(k!='2')&&(k!='3')) {f=1;}
			break;
			
			case 3:
			if(k=='1'&&cf!=DEC) ct=DEC;
			else if(k=='2'&&cf!=HEX) ct=HEX;
			else if((k=='1'&&cf==DEC)||(k=='2'&&cf==HEX)) ct=BIN;
			f=4;
			if(k!='1'&&k!='2') f=3;
			break;
			
			case 5:
			if (k!='=')
			{
				convert();
			}
			else
			{
				result();				
			}
			break;
		}
	}
}

void convert()
{
	if (cf==DEC)
	{
		num=num*10+(k-'0');
	}
	else if (cf==BIN)
	{
		b[bi]=(k-'0');
		bi++;
	}
	else
	{
		if (k>='0'&&k<='9')
		{
			b[bi]=(k-'0');
		}
		else if(k=='A')
		{
			b[bi]=(k-'7');
		}
		else if(k=='U')
		{
			bi--;
			z++;
			if (z==6){z=0;}
			b[bi]=(chars[z]-'7');
			k=chars[z];
			LCD_SETCURSOR(LINE1,cursor_cell-1);
		}
		else if(k=='D')
		{
			bi--;
			z--;
			if (z==-1){z=5;}
			b[bi]=(chars[z]-'7');
			k=chars[z];
			LCD_SETCURSOR(LINE1,cursor_cell-1);
		}
		else if(k=='S')
		{
			z=0;
			bi--;
		}
		bi++;
	}
	if (k!='S')
	{
		LCD_WriteChar(k);
	}
	
}

void result()
{
	LCD_SETCURSOR(LINE2,4);
	bi--;
	if (cf==BIN)
	{
		
		for (u8 i=1;bi>=0;bi--)
		{
			num+=i*b[bi];
			i*=2;
		}
	}
	else if(cf==HEX)
	{
		num=b[bi];
		num+=((b[bi-1])<<4);
	}
	if (ct==DEC)
	{
		LCD_WriteNumber(num);
	}
	else if (ct==BIN)
	{
		LCD_WriteBinary(num);
	}
	else if (ct==HEX)
	{
		LCD_WriteHex(num);
	}
	num=0;
	bi=0;
	f=6;
	
}
