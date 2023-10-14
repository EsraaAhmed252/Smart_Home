#include "StdTypes.h"
#include "MemMap.h"
#include "UTILS.h"

#include "DIO/DIO_Inteface.h"
#include "DIO/DIO_Private.h"
#include "DIO/DIO_Cfg.h"

static void DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type direction)
{
	if(direction==OUTPUT)
	{
		switch (pin/8)
		{
			case PA :
			SET_BIT(DDRA,pin%8);
			CLR_BIT(PORTA,pin%8);
			break;
			case PB :
			SET_BIT(DDRB,pin%8);
			CLR_BIT(PORTB,pin%8);
			break;
			case PC :
			SET_BIT(DDRC,pin%8);
			CLR_BIT(PORTC,pin%8);
			break;
			case PD :
			SET_BIT(DDRD,pin%8);
			CLR_BIT(PORTD,pin%8);
			break;
		}
	}
	else if(direction==INFREE)
	{
		switch (pin/8)
		{
			case PA :
			CLR_BIT(DDRA,pin%8);
			CLR_BIT(PORTA,pin%8);
			break;
			case PB :
			CLR_BIT(DDRB,pin%8);
			CLR_BIT(PORTB,pin%8);
			break;
			case PC :
			CLR_BIT(DDRC,pin%8);
			CLR_BIT(PORTC,pin%8);
			break;
			case PD :
			CLR_BIT(DDRD,pin%8);
			CLR_BIT(PORTD,pin%8);
			break;
		}
	}
	else if(direction==INPULL)
	{
		switch (pin/8)
		{
			case PA :
			CLR_BIT(DDRA,pin%8);
			SET_BIT(PORTA,pin%8);
			break;
			case PB :
			CLR_BIT(DDRB,pin%8);
			SET_BIT(PORTB,pin%8);
			break;
			case PC :
			CLR_BIT(DDRC,pin%8);
			SET_BIT(PORTC,pin%8);
			break;
			case PD :
			CLR_BIT(DDRD,pin%8);
			SET_BIT(PORTD,pin%8);
			break;
		}
	}
}

void DIO_Init(void)
{
	int length = sizeof(DIO_PinsStatusArr)/sizeof(DIO_PinsStatusArr[0]);
	DIO_Pin_type i;
	for(i =0;i<length;i++)
	{
		DIO_InitPin(DIO_PinsStatusArr[i].pin,DIO_PinsStatusArr[i].pin_state);
	}
}

void DIO_WritePin(DIO_Pin_type pin ,DIO_PinVoltage_type volt)
{
	if(volt==HIGH)
	{
		switch (pin/8)
		{
			case PA :
			SET_BIT(PORTA,pin%8);
			break;
			case PB :
			SET_BIT(PORTB,pin%8);
			break;
			case PC :
			SET_BIT(PORTC,pin%8);
			break;
			case PD :
			SET_BIT(PORTD,pin%8);
			break;
		}
	}
	else
	{
		switch (pin/8)
		{
			case PA :
			CLR_BIT(PORTA,pin%8);
			break;
			case PB :
			CLR_BIT(PORTB,pin%8);
			break;
			case PC :
			CLR_BIT(PORTC,pin%8);
			break;
			case PD :
			CLR_BIT(PORTD,pin%8);
			break;
		}
	}
}

DIO_PinVoltage_type	DIO_ReadPin(DIO_Pin_type pin)
{
	DIO_PinVoltage_type v=LOW;
	switch (pin/8)
	{
		case PA :
		v=READ_BIT(PINA,pin%8);
		break;
		case PB :
		v=READ_BIT(PINB,pin%8);
		break;
		case PC :
		v=READ_BIT(PINC,pin%8);
		break;
		case PD :
		v=READ_BIT(PIND,pin%8);
		break;
	}
	return v;
}

void DIO_TogglePin(DIO_Pin_type pin)
{
	switch (pin/8)
	{
		case PA :
		TOG_BIT(PORTA,pin%8);
		break;
		case PB :
		TOG_BIT(PORTB,pin%8);
		break;
		case PC :
		TOG_BIT(PORTC,pin%8);
		break;
		case PD :
		TOG_BIT(PORTD,pin%8);
		break;
	}
}

void DIO_WritePort(DIO_Port_type port,u8 data)
{
	switch (port)
	{
		case PA :
		PORTA=data;
		break;
		case PB :
		PORTB=data;
		break;
		case PC :
		PORTC=data;
		break;
		case PD :
		PORTD=data;
		break;
	}
}

u8 DIO_ReadPort(DIO_Port_type port)
{
	u8 data=0;
	switch (port)
	{
		case PA :
		data=PINA;
		break;
		case PB :
		data=PINB;
		break;
		case PC :
		data=PINC;
		break;
		case PD :
		data=PIND;
		break;
	}
	return data;
}





