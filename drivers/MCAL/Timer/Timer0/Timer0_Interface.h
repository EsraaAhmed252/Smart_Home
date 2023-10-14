#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

void timer0_init(void);
void timer0_int_value(u8 value);
void timer0_start(void);
void timer0_stop(void);
void timer0_int_enable(void);
void timer0_of_set_callbck(void (*p2f_var)(void));
void timer0_cmp_set_callbck(void (*p2f_var)(void));
u8 timer0_set_cmp(u8 duty);
void timer0_cmp_value(u8 value);


#endif /* TIMER0_INTERFACE_H_ */
