#ifndef ICU_INTERFACE_H_
#define ICU_INTERFACE_H_

#define ICU_Rising_edge 1
#define ICU_falling_edge 1

void ICU_init(void);
void ICU_get_Duty_Cycle(u8 * duty);
void ICU_get_Frequency(u32 * frequency);

#endif /* ICU_INTERFACE_H_ */
