#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

extern u8 keys[ROWS][COLS];
extern DIO_Pin_type Rows_pins[ROWS];
extern DIO_Pin_type Cols_pins[COLS];

void KeyPad_init(void);
u8 KeyPad_get(void);


#endif /* KEYPAD_INTERFACE_H_ */
