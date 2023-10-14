#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "ADC/ADC_Interface.h"

void ADC_init(ADC_VOLTREF_type vref,ADC_Prescaler_type scaler)
{
	switch (vref)
	{
	case VREF_AREF:
		CLR_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
	case VREF_AVCC:
		SET_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
	case VREF_256V:
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
	break;
	}
	
	ADCSRA&=0xF8;
	scaler&=0x07;
	ADCSRA|=scaler;
	
	SET_BIT(ADCSRA,ADEN);
}

u16 ADC_Read(ADC_Channel_type CH)
{
	ADMUX&=0xE0;
	CH&=0x07;
	ADMUX|=CH;
	
	SET_BIT(ADCSRA,ADSC);
	
	while(READ_BIT(ADCSRA,ADSC));
	 /*u16 adc=ADCL;
	adc|=(ADCH<<8);
 if (ADLAR==1)
		{
			adc=0;
			adc=ADCL>>6;
			adc=adc|ADCH<<2;
		}*/
	return ADC;
}

u16 ADC_VoltRead(ADC_Channel_type CH)
{
	u16 volt;
	u16 adc;
	adc=ADC_Read(CH);
	
	volt=(adc*(u32)5000)/1023;
	return volt;
	
}
