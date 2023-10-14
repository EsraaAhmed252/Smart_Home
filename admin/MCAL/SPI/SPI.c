#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "Routines.h"
#include "SPI/SPI_Interface.h"
#include "SPI/SPI_Cfg.h"

static void (*ptrr)(u8);

void SPI_init()
{
	SET_BIT(SPCR,5);

	#if SPI_Mode==Slave
			CLR_BIT(SPCR,4);

	#elif SPI_Mode==Master
			SET_BIT(SPCR,4);

			#if SPI_Prescaler==_4_prescalar
				CLR_BIT(SPCR,0);
				CLR_BIT(SPCR,1);
			#elif SPI_Prescaler==_16_prescalar
				SET_BIT(SPCR,0);
				CLR_BIT(SPCR,1);
			#elif SPI_Prescaler==_64_prescalar
				CLR_BIT(SPCR,0);
				SET_BIT(SPCR,1);
			#elif SPI_Prescaler==_128_prescalar
				SET_BIT(SPCR,0);
				SET_BIT(SPCR,1);
			#endif

			#if SPI_x2Speed==Enable
				Set_BIT(SPSR,0);
			#elif SPI_x2Speed==Disable
				CLR_BIT(SPSR,0);
			#endif
	#endif

	#if Clock_pol==Rising
		CLR_BIT(SPCR,3);
	#elif Clock_pol==falling
		SET_BIT(SPCR,3);
	#endif

	#if Clock_phase==Sample
		CLR_BIT(SPCR,2);
	#elif Clock_phase==Setup
		SET_BIT(SPCR,2);
	#endif

	SET_BIT(SPCR,6);	//SPI Enable
}

void SPI_Enable_int()
{
	SET_BIT(SPCR,7);
}

u8 SPI_Transceive(u8 data)
{
	while(READ_BIT(SPSR,6));
	SPDR=data;
	while(!READ_BIT(SPSR,7));
	return SPDR;
}

void SPI_Send_data(u8 data)
{
	while(1 == READ_BIT(SPSR,6));
	SPDR=data;
}


void SPI_Set_Callback(void (*ptrf)(u8))
{
	ptrr=ptrf;
}


ISR(SPI_STC_vect)
{
	ptrr(SPDR);
}







