#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "Routines.h"
#include "DIO/DIO_Inteface.h"

#include "I2C_Interface.h"
#include "LCD/LCD_Interface.h"

void I2c_Master_init(u8 add)
{
	if(add<128)
	{
		TWAR=add<<1;
	}

	TWBR=12;

	CLR_BIT(TWSR,0);
	CLR_BIT(TWSR,1);

	SET_BIT(TWCR,6);
	SET_BIT(TWCR,2);
}

void I2C_SendStartCondition(void)
{
	SET_BIT(TWCR,5);

	SET_BIT(TWCR,2);
	SET_BIT(TWCR,7);
	while(!READ_BIT(TWCR,7));
	while((TWSR&0xf8)!=0x08);
}

void I2C_SendRepStartCondition(void)
{
	SET_BIT(TWCR,5);

	SET_BIT(TWCR,2);
	SET_BIT(TWCR,7);
	while(!READ_BIT(TWCR,7));
	while((TWSR&0xf8)!=0x10);
}

void I2C_SendStopCondition(void)
{
	SET_BIT(TWCR,4);
	SET_BIT(TWCR,2);
	SET_BIT(TWCR,7);
}

void I2C_SendSlaveAdd_Write(u8 slave_add)
{
	TWDR=slave_add<<1;
	CLR_BIT(TWDR,0);
	CLR_BIT(TWCR,5);

	SET_BIT(TWCR,7);
	SET_BIT(TWCR,2);
	while(!READ_BIT(TWCR,7));
	while((TWSR&0xf8)!=0x18);
}

void I2C_SendSlaveAdd_Read(u8 slave_add)
{

	TWDR=slave_add<<1;
	SET_BIT(TWDR,0);
	CLR_BIT(TWCR,5);

	SET_BIT(TWCR,2);
	SET_BIT(TWCR,7);
	while(!READ_BIT(TWCR,7));
	while((TWSR&0xf8)!=0x40);
}


void I2C_MasterData_Send(u8 data)
{
	TWDR=data;

	SET_BIT(TWCR,2);
	SET_BIT(TWCR,7);
	while(!READ_BIT(TWCR,7));
	while((TWSR&0xf8)!=0x28);
}

u8 I2C_MasterData_Read(void)
{
	SET_BIT(TWCR,7);
	SET_BIT(TWCR,2);
	SET_BIT(TWCR,6);
	while(!READ_BIT(TWCR,7));
	while((TWSR&0xf8)!=0x50);
	return TWDR;
}

void I2C_NACK_Send()
{
	SET_BIT(TWCR,2);
	SET_BIT(TWCR,7);
}
