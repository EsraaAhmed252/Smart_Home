#ifndef DIO_INTEFACE_H_
#define DIO_INTEFACE_H_

typedef enum{
	PINA0=0,
	PINA1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	PIND0,
	PIND1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7,
	TOTAL_PINS
}DIO_Pin_type;


#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

typedef enum{
	OUTPUT,
	INFREE,
	INPULL
	}DIO_PinStatus_type;

typedef enum{
	PA=0,
	PB,
	PC,
	PD
	}DIO_Port_type;

typedef enum{
	LOW,
	HIGH
	}DIO_PinVoltage_type;

typedef struct{
	DIO_Pin_type pin;
	DIO_PinStatus_type pin_state;
	}Pin_Cfg_type;

void DIO_Init(void);
void DIO_WritePin(DIO_Pin_type pin ,DIO_PinVoltage_type volt);
DIO_PinVoltage_type	DIO_ReadPin(DIO_Pin_type pin);
void DIO_TogglePin(DIO_Pin_type pin);
void DIO_WritePort(DIO_Port_type port,u8 data);
u8 DIO_ReadPort(DIO_Port_type port);


#endif /* DIO_INTEFACE_H_ */
