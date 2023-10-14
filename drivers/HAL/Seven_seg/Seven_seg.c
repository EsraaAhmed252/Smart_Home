#include "StdTypes.h"
#include "MemMap.h"
#include "UTILS.h"

#include "DIO/DIO_Inteface.h"
#include "DIO/DIO_Private.h"
#include "DIO/DIO_Cfg.h"
#include "Seven_Seg/Seven_Seg_Cfg.h"

void Segment_init(void)
{
	DIO_WritePin(first_7seg,HIGH);
	DIO_WritePin(second_7seg,HIGH);
	DIO_WritePin(third_7seg,HIGH);
	DIO_WritePin(fourth_7seg,HIGH);

	DIO_WritePin(A,LOW);
	DIO_WritePin(B,LOW);
	DIO_WritePin(C,LOW);
	DIO_WritePin(D,LOW);
}

void Segment_display(u8 num)
{
	char d0,d1;
	d0=num%10;
	d1=num/10;

	for(u8 l=0;l<200;l++)
	{
		DIO_WritePin(first_7seg,LOW);
		DIO_WritePin(second_7seg,HIGH);
		DIO_WritePin(third_7seg,HIGH);
		DIO_WritePin(fourth_7seg,HIGH);

		DIO_WritePin(A,(d0>>0)&1);
		DIO_WritePin(B,(d0>>1)&1);
		DIO_WritePin(C,(d0>>2)&1);
		DIO_WritePin(D,(d0>>3)&1);
	}
	for(u8 l=0;l<200;l++)
	{
		DIO_WritePin(first_7seg,HIGH);
		DIO_WritePin(second_7seg,LOW);
		DIO_WritePin(third_7seg,HIGH);
		DIO_WritePin(fourth_7seg,HIGH);

		DIO_WritePin(A,(d1>>0)&1);
		DIO_WritePin(B,(d1>>1)&1);
		DIO_WritePin(C,(d1>>2)&1);
		DIO_WritePin(D,(d1>>3)&1);
	}
}
