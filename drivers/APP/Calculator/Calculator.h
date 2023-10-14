#ifndef CALCULATOR_H_
#define CALCULATOR_H_

extern u8 cursor_cell;
void Calculator_init(void);
void Calculator_Runnable(void);

void num(void);
void equ(void);
void add(void);
void sub(void);
void mul(void);
void div(void);
void cancel(void);
void equ1(void);
void add1(void);
void sub1(void);
void mul1(void);
void div1(void);

#endif /* CALCULATOR_H_ */