#include "StdTypes.h"
#include "Utils.h"
#include "DIO/DIO_Inteface.h"
#include "LCD/LCD_Interface.h"
#include "UART/UART_Interface.h"
#include "SPI/SPI_Interface.h"
#include "GI/GI_Interface.h"

#define ADD_USER 1
#define DELETE_USER 2

#define EXTI_send PINA0
#define START_CHAT PINA1
#define INT_PIN PINB2

void SPI_Connection_Start(void);

u8 SPI_ACK = 0 ;
u8 UART_End_Flage = 0 ;
u8 UART_USER_ID;
u8 UART_USER_Pass;
u16 UART_OPERATION;

int main(){

	DIO_Init();
	LCD_init();
	GIE_Enable();
	USART_Init(9600);
	SPI_init();


	while(1)
	{
		if ( UART_End_Flage == 0 )
		{
			UART_End_Flage = 1;
			LCD_Clear();
			LCD_WriteString("CHOOSE OPERATION :");
			LCD_SETCURSOR(LINE2,0);
			LCD_WriteString("1.ADD NEW USER");
			LCD_SETCURSOR(LINE3,0);
			LCD_WriteString("2.DELETE USER");
			UART_OPERATION = Uart_ReadPolling()-'0';

			if(ADD_USER==UART_OPERATION)
			{
				UART_USER_ID=0;
				UART_USER_Pass=0;
				LCD_Clear();
				LCD_WriteString("ENTER NEW ID");
				LCD_SETCURSOR(LINE2,0);

				for(u8 i=0;i<3;i++)
				{
					UART_USER_ID = UART_USER_ID*10+(Uart_ReadPolling()-'0');
					LCD_WriteNumber(UART_USER_ID%10);
					_delay_ms(100);
				}

				LCD_Clear();
				LCD_WriteString("ENTER NEW PASSWORD");
				LCD_SETCURSOR(LINE2,0);
				for(u8 i=0;i<3;i++)
				{
					UART_USER_Pass = UART_USER_Pass *10+(Uart_ReadPolling()-'0');
					LCD_WriteNumber(UART_USER_Pass%10);
					_delay_ms(100);
				}
			}
			else if(DELETE_USER==UART_OPERATION)
			{
				UART_USER_ID=0;
				LCD_Clear();
				LCD_WriteString("ENTER ID TO BE");
				LCD_SETCURSOR(LINE2,0);
				LCD_WriteString("DELETED");
				LCD_SETCURSOR(LINE3,0);
				for(u8 i=0;i<3;i++)
				{
					UART_USER_ID = UART_USER_ID*10+(Uart_ReadPolling()-'0');
					LCD_WriteNumber(UART_USER_ID%10);
					_delay_ms(100);
				}

			}
		}
		else if( UART_End_Flage == 1 )
		{
			DIO_WritePin(EXTI_send , HIGH);
			while(DIO_ReadPin(START_CHAT) == 0);
			SPI_Connection_Start();
			UART_End_Flage = 0;
		}
	}
	return 0;
}

void SPI_Connection_Start(void){

	DIO_WritePin(PINA0 , LOW);
	SPI_ACK = SPI_Transceive(UART_OPERATION);

	if(SPI_ACK == 1 )
	{
		LCD_Clear();
		LCD_WriteString("Operation has been sent !");
	}

	SPI_ACK = SPI_Transceive(UART_USER_ID);

		if(SPI_ACK == 2 )
		{
			if((DELETE_USER==UART_OPERATION))
				{
					LCD_Clear();
					LCD_WriteString("ID HAS BEEN SENT !");
				}
		}

	if(ADD_USER==UART_OPERATION)
	{
		SPI_ACK = SPI_Transceive(UART_USER_Pass);

		if(SPI_ACK == 3 )
		{
			LCD_Clear();
			LCD_WriteString("ID AND PASSWORD HAVEBEEN SENT !");
		}
	}
	_delay_ms(800);
}
