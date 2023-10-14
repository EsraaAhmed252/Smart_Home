#ifndef TIMER2_INTERFACE_H_
#define TIMER2_INTERFACE_H_

void timer2_init(void);
void timer2_start(void);
void timer2_int_value(u8 value);
u8 timer2_set_cmp(u8 duty);
u8 timer2_set_cmp_PC (u8 duty);
void timer2_cmp_value(u8 value);
void timer2_stop(void);
void timer2_int_enable(void);
void timer2_of_set_callbck(void (*p2f_var)(void));
void timer2_cmp_set_callbck(void (*p2f_var)(void));


#endif /* TIMER2_INTERFACE_H_ */
