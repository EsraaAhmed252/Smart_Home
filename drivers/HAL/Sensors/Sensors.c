#include "StdTypes.h"
#include "ADC/ADC_Interface.h"
#include "Sensors/Sensors_Cfg.h"
#include "Sensors/Sensors_Interface.h"

u16 Temp_Read(void)
{
	u16 adc=ADC_Read(LM35_CH);
	u16 temp=((adc*(u32)1000)/2048);
	return temp;
} 

u16 Temp_Read1(void)
{
	u16 volt=ADC_VoltRead(LM35_CH);
	u16 temp=volt;
	if (temp%10<=2){temp-=temp%10;}
	else if (temp%10>2&&temp%10<=4){temp+=(5-temp%10);}
	else if (temp%10>5&&temp%10<=7){temp-=((temp%10)-5);}
	else if (temp%10>7){temp+=(10-temp%10);}
	return temp;
}

u16 Temp_Read2(void)
{
	u16 adc=ADC_Read(LM35_CH);
	u16 temp=((adc*(u32)1000)/921)+91;
	return temp;
}
