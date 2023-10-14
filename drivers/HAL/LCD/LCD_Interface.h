#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

typedef enum{
	LINE1=0x00,
	LINE2=0x40,
	LINE3=0x14,
	LINE4=0x54
}LINE_NUMBER;

typedef enum{
	LtoR,
	RtoL
}Write_M;

void LCD_init(void);


void LCD_WriteChar(u8 s);
void LCD_WriteString(u8* s);
void LCD_WriteNumber(s32 num);
void LCD_WriteBinary(u32 num);
void LCD_WriteHex(u32 num);

void LCD_SETCURSOR(LINE_NUMBER line ,u8 cell);
void Insert_Char(u8 adress,u8* Character);
void Write_Mode(Write_M m);

void LCD_Clear(void);

void Array_Fill(u8* arr,u8 P0,u8 P1,u8 P2,u8 P3,u8 P4,u8 P5,u8 P6,u8 P7);


#endif /* LCD_INTERFACE_H_ */
