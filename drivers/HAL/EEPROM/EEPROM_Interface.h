#ifndef EEPROM__INTERFACE_H_
#define EEPROM__INTERFACE_H_

void EEPROM_init(void);
void EEPROM_WriteByte(u16 add,u8 data);
void EEPROM_ReadByte(u16 add,u8* data);
void EEPROM_WritePage(u16 add,u8* data_arr,u8 length);
void EEPROM_ReadSeq(u16 add,u8* data_arr,u8 length);
void EEPROM_WritePage2(u16 add,u8* data_arr);
void EEPROM_ReadSeq2(u16 add,u8* data_arr);
void I2C_NACK_Send();
#endif /* EEPROM__INTERFACE_H_ */
