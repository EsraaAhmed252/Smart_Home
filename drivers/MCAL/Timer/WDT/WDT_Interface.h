#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_

#define WDT_TO_16_3ms 1
#define WDT_TO_32_5ms 2
#define WDT_TO_65ms 3
#define WDT_TO_130ms 4
#define WDT_TO_260ms 5
#define WDT_TO_520ms 6
#define WDT_TO_1s 7
#define WDT_TO_2_1s 8

void WDT_Enable(float prescaler);
void WDT_Disable(void);

#endif /* WDT_INTERFACE_H_ */
