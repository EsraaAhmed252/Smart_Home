#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "Routines.h"
#include "UART/UART_Interface.h"
#include "UART/UART_Cfg.h"
#include "LCD/LCD_Interface.h"


void (*_read_ptrf)(u8) = 0;
void (*_empty_ptrf)(void) = 0;
void (*_write_ptrf)(void) = 0;

#define UART_F_CPU 16000000

void Uart_Init(void){
	// UBRR
	u32 ubbr;
	ubbr = (u32)( ( ( UART_F_CPU ) / ( 16 * ( (u32) UART_BAUDRATE ) ) )-1);
	UBRRL= (u8) ubbr;
	UBRRH = (u8) ((ubbr >> 8) & (0b00001111));

	// UART Mode
	switch(UART_MODE){
	case UART_ASYNCH:
			UCSRC |= 1<<7 | 1<<6;
		break;
	case UART_SYNCH:
			UCSRC |= (1<<7) & (~(1<<6));  // 0b1000 0000  (  --> 1000 0000)
		break;
	}

	// UART Stop Bit
	switch(UART_STOP_BIT){
	case Stop_1Bit:
			UCSRC |= 1<<7 | 1<<3;
		break;
	case Stop_2Bit:
			UCSRC |= (1<<7) & (~(1<<3));  // 0b1000 0000  (  --> 1000 0000)
		break;
	}

	// UART Parity Bit
	switch(UART_PARITY){
	case NO_PARITY:
			UCSRC |= (1<<7) & (~(1<<5)) & (~(1<<4));
		break;
	case ODD_PARITY:
			UCSRC |= (1<<7) | (1<<5) | (1<<4);
		break;
	case EVEN_PARITY:
			UCSRC |= ( (1<<7) | (1<<5) ) & (~(1<<4));
		break;
	}

	switch(UART_CHARSIZE){
	case CHAR_SIZE_5:	// SEL		//CS0		//CS1
			UCSRC |= ( (1<<7) & (~(1<<1)) & (~(1<<2) ) );
						// CS2
			UCSRB &=~(1<<2);
			break;
	case CHAR_SIZE_6:
		UCSRC |= ( ( (1<<7) | (1<<1) )& ( ~ ( 1<<2 )  ) );
					// CS2
		UCSRB &=~(1<<2);
		break;
	case CHAR_SIZE_7:
		UCSRC |= ( ( (1<<7) | (1<<2) )& ( ~ ( 1<<1 )  ) );
					// CS2
		UCSRB &=~(1<<2);
		break;
	case CHAR_SIZE_8:
		UCSRC |= ( (1<<7) | (1<<1) | ( 1<<2 ) );
					// CS2
		UCSRB &=~(1<<2);
		break;
	case CHAR_SIZE_9:
		UCSRC |= ( (1<<7) | (1<<1) | ( 1<<2 ) );
					// CS2
		UCSRB |= (1<<2);
		break;
	}

	// Transmission
	switch(UART_TRANSMISSION){
	case Enable_Polling:
		// enable transmission
		UCSRB |= 1<<3;
		break;
	case Enable_Interrupt:
		// enable transmission and interrupt
		UCSRB |= 1 <<3 | 1<<6;
		break;
	case Disable:
		UCSRB &=~(1<< 3 | 1<< 6);
		break;
	}

	// Reciving
	switch(UART_RECEIVING){
	case Enable_Polling:
		// enable transmission
		UCSRB |= 1<<4;
		break;
	case Enable_Interrupt:
		// enable transmission and interrupt
		UCSRB |= 1<<4 | 1<<7;
		break;
	case Disable:
		UCSRB &=~(1<<4 | 1<<7);
		break;
	}


}

void Uart_WritePolling(u8 data){
	while(!(UCSRA & 1<<5));
	UDR = data;
}

u8 Uart_ReadPolling(){
	while(!(UCSRA & 1<<7));
	return UDR;
}

void Uart_SetEmptyCallback(void (*ptrf)(u8)){
	_empty_ptrf = ptrf;
}

void Uart_SetReadCallback(void (*ptrf)(u8)){
	_read_ptrf = ptrf;
}

void Uart_SetWriteCallback(void (*ptrf)(u8)){
	_write_ptrf = ptrf;
}

ISR(USART_RXC_vect){
	u8 data = UDR;
	if(_read_ptrf != 0)
	{
		_read_ptrf(data);
	}
}

ISR(USART_TXC_vect){
	if(_write_ptrf != 0)
	{
		_write_ptrf();
	}
}


ISR(USART_UDRE_vect)
{
	if(_empty_ptrf != 0)
		_empty_ptrf();
}
