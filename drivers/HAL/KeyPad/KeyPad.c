#include "StdTypes.h"
#include "Utils.h"
#include "DIO/DIO_Inteface.h"
#include "KeyPad/KeyPad_Cfg.h"
#include "KeyPad/KeyPad_Interface.h"

void KeyPad_init()
{
	for (u8 r=0;r<ROWS;r++)
	{
		DIO_WritePin(Rows_pins[r],HIGH);
	}
}

u8 KeyPad_get()
{
	u8 key=NO_KEY;
	for (u8 r=0;r<ROWS;r++)
	{
		DIO_WritePin(Rows_pins[r],LOW);
		for (u8 c=0;c<COLS;c++)
		{
			if (DIO_ReadPin(Cols_pins[c])==LOW)
			{
				key=keys[r][c];
				_delay_ms(10);
				while(DIO_ReadPin(Cols_pins[c])==LOW);
			}
		}
		DIO_WritePin(Rows_pins[r],HIGH);
	}
	return key;
}
