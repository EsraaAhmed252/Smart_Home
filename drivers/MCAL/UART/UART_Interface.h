#ifndef UART_Interface_H_
#define UART_Interface_H_

void Uart_Init();
void Uart_WritePolling(u8);
u8 Uart_ReadPolling();
void Uart_SetReadCallback(void (*ptrf)(u8));
void Uart_SetWriteCallback(void (*ptrf)(u8));
void Uart_SetEmptyCallback(void (*ptrf)(u8));

#endif /* UART_Interface_H_ */
