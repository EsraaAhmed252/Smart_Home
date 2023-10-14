#include "StdTypes.h"
#include "Utils.h"
#include "DIO/DIO_Inteface.h"

#include "I2C/I2C_Interface.h"
#include "EEPROM_Interface.h"
#include "LCD/LCD_Interface.h"


void EEPROM_init(void)
{
	I2c_Master_init(200);
}
void EEPROM_WriteByte(u16 add,u8 data)
{
	u8 address = (add>>8) | 0x50;
	I2C_SendStartCondition();
	I2C_SendSlaveAdd_Write(address);
	I2C_MasterData_Send((u8)add);
	I2C_MasterData_Send(data);
	I2C_SendStopCondition();
	_delay_ms(5);
}

void EEPROM_ReadByte(u16 add,u8* data)
{
	u8 address = (add>>8) | 0x50;
	//LCD_WriteNumber(0);
	I2C_SendStartCondition();
	//LCD_WriteNumber(1);
	I2C_SendSlaveAdd_Write(address);
	//LCD_WriteNumber(2);
	I2C_MasterData_Send((u8)add);
	//LCD_WriteNumber(3);
	I2C_SendRepStartCondition();
	//LCD_WriteNumber(4);
	I2C_SendSlaveAdd_Read(address);
	//LCD_WriteNumber(5);
	*data=I2C_MasterData_Read();
	//LCD_WriteNumber(6);
	I2C_SendStopCondition();
	//LCD_WriteNumber(7);
	_delay_ms(5);
}

void EEPROM_WritePage(u16 add,u8* data_arr,u8 length)
{u8  x=0;
	u8 counter=(length/16)+(length%16?1:0);
	u8 c=counter;
	u8 i = 0;
	for(;counter>0;counter--)
	{
		u8 address = (add>>8) | 0x50;
		I2C_SendStartCondition();
		I2C_SendSlaveAdd_Write(address);
		I2C_MasterData_Send((u8)add);

		for (; (i < (16*(c-counter)+16))&&(i<length) ; i++)
		{
			I2C_MasterData_Send(data_arr[i]);
		}
		I2C_SendStopCondition();
			_delay_ms(100);
		add+=(u16)16;
	}
}

void EEPROM_ReadSeq(u16 add,u8* data_arr,u8 length)
{
	u8 address = (add>>8) | 0x50;
	I2C_SendStartCondition();
	I2C_SendSlaveAdd_Write(address);
	I2C_MasterData_Send((u8)add);
	I2C_SendRepStartCondition();
	I2C_SendSlaveAdd_Read(address);

	for (u8 i = 0; i < length; i++)
	{
		data_arr[i]=I2C_MasterData_Read();
		LCD_WriteNumber(data_arr[i]);
		LCD_WriteChar(' ');
	}
	I2C_SendStopCondition();
	_delay_ms(100);
}

void EEPROM_WritePage2(u16 add,u8* data_arr)
{
	for (u16 i = 0; i < 30; i++)
	{
		EEPROM_WriteByte(add+i,data_arr[i]);
	}
}

void EEPROM_ReadSeq2(u16 add,u8* data_arr)
{
	u8 x=0;
	for (u16 i = 0; i < 30; i++)
	{
		EEPROM_ReadByte(add+i,&x);
		data_arr[i]=x;
	}
}
