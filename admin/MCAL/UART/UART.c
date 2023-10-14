#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "Routines.h"
#include "UART/UART_Interface.h"
//#include "UART/UART_Cfg.h"

#define UART_F_CPU 8000000

void USART_Init( u32 baud ){

	u32 UBRR;
		UBRR = ((UART_F_CPU / (16*baud)) - 1);
		UBRRL= (u8) UBRR;
		UBRRH = (u8) ((UBRR >> 8) & (0b00001111));

		UCSRB = (1<<RXEN)|(1<<TXEN);
		UCSRC = (1<<URSEL)|(3<<UCSZ0);

}

void Uart_WritePolling(u8 data){
	while (!( UCSRA & (1 << UDRE)))	;
	UDR = data;
}

u8 Uart_ReadPolling(){
	while (!(UCSRA & (1 << RXC)));
	return UDR;
}

