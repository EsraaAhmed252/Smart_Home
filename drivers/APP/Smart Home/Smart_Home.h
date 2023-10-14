#ifndef SMART_HOME_H_
#define SMART_HOME_H_

#define admin_mode	1
#define user_mode 	2
#define init_mode	3

typedef enum {
	LED_ON = 1,
	LED_OFF
}LED_Status_t;

typedef enum {
	DOOR_OPEN = 1,
	DOOR_CLOSE
}Door_Status_t;

#define MAX_TEMP	28
#define MIN_TEMP	21

void SH_init();
void SH_Runnable();
void start_screen();
void options_screen();
void leds_screen();
void leds_status_screen();
void ctrl_led(u8* led_num,u8* led_state);
void Led_Control(DIO_Pin_type LedNumber , LED_Status_t LedState);
void Door_Control(Door_Status_t DoorState);
u8 Fan_Control(void);
void Dimmer_Control(u8 duty);
void Door_status_screen();
void ctrl_door(u8* door_status);
void Dimmer_screen();
void ctrl_dimmer(u8* speed);

#endif /* SMART_HOME_H_ */
