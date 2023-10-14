#include "StdTypes.h"
#include "Utils.h"
#include "DIO/DIO_Inteface.h"
#include "SPI/SPI_Interface.h"


void SPI_Test_init()
{
	SPI_Enable_int();
	SPI_init();
}

void SPI_Test_Runnable()
{
	SPI_Send_data(4);
	_delay_ms(100);
}
