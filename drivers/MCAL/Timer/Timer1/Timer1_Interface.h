#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

void timer1_init(void);
void timer1_int_value(u16 value);
void timer1_max_value(u16 value);
void timer1_start(void);
void timer1_stop(void);
void timer1_int_enable(void);
u16 timer1_set_cmp(u8 duty, u32 freq);
void timer1_cmp_value(u16 value);
void timer1_of_set_callbck(void (*p2f_var)(void));
void timer1_cmpA_set_callbck(void (*p2f_var)(void));
void timer1_cmpB_set_callbck(void (*p2f_var)(void));

#endif /* TIMER1_INTERFACE_H_ */
