#ifndef ADCS_H_
#define ADCS_H_

#define Password 1234
#define led PINB7
#define buzzer PINC6
#define Door_open 180
#define Door_close 40

void ADCS_init(void);
void ADCS_Runnable(void);

#endif /* ADCS_H_ */
