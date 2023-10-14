#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#define _8_BIT 0
#define _4_BIT 1
#define LCD_Mode _4_BIT

#define RS PINA7
#define EN PINA6


#define D4 PINA5
#define D5 PINA4
#define D6 PINA3
#define D7 PINA2


#define LCD_PORT PA

#define Cursor_Mode 0x0c  //no cursor 0c - steady cursor 0e - blinking cursor 0f

#endif /* LCD_CFG_H_ */
