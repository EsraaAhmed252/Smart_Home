#ifndef CONVERTER_H_
#define CONVERTER_H_

#define DEC 1
#define BIN 2
#define HEX 3

extern s8 cursor_cell;
void Converter_init(void);
void Converter_Runnable(void);
void result(void);
void convert(void);

#endif /* CONVERTER_H_ */
