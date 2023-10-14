#include "StdTypes.h"
#include "Utils.h"
#include "EEPROM/EEPROM_Interface.h"
#include "I2C_test.h"
#include "LCD/LCD_Interface.h"

void I2C_init()
{
	EEPROM_init();
}


void I2C_Runnable()
{
	u8 arr[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39};
	u8 length = sizeof(arr)/sizeof(arr[0]);
	u8  arr2[40];
	u16 add=0x0A;
	EEPROM_WritePage(add,arr,length);
	EEPROM_ReadSeq(add,arr2,length);
}
