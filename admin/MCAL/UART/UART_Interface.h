#ifndef UART_Interface_H_
#define UART_Interface_H_

#define MPCM	0
#define U2X		1
#define PE		2
#define DOR		3
#define FE		4
#define UDRE	5
#define TXC		6
#define RXC		7

#define TXB8	0
#define RXB8	1
#define UCSZ2	2
#define TXEN	3
#define RXEN	4
#define UDRIE	5
#define TXCIE	6
#define RXCIE	7

#define UCPOL	0
#define UCSZ0	1
#define UCSZ1	2
#define USBS	3
#define UPM0	4
#define UPM1	5
#define UMSEL	6
#define URSEL	7

void USART_Init( u32 baud );
void Uart_WritePolling(u8);
u8 Uart_ReadPolling();
void Uart_SetReadCallback(void (*ptrf)(u8));
void Uart_SetWriteCallback(void (*ptrf)(void));
void Uart_SetEmptyCallback(void (*ptrf)(void));

#endif /* UART_Interface_H_ */
