#ifndef ROUTINES_H_
#define ROUTINES_H_


#define __INTR_ATTRS used

#define INT0_vect		__vector_1
#define INT0_vect_num   1

#define TIMER2_COMP_vect	__vector_4
#define TIMER2_COMP_vect_num  4

#define TIMER2_OVF_vect		__vector_5
#define TIMER2_OVF_vect_num  5

#define INT1_vect     __vector_6
#define INT1_vect_num   6

#define TIMER1_COMPA_vect	__vector_7
#define TIMER1_COMPA_vect_num   7

#define TIMER1_COMPB_vect	__vector_8
#define TIMER1_COMPB_vect_num   8

#define TIMER1_OVF_vect		__vector_9
#define TIMER1_OVF_vect_num   9

#define TIMER0_COMP_vect     __vector_10
#define TIMER0_COMP_vect_num  10

#define TIMER0_OVF_vect     __vector_11
#define TIMER0_OVF_vect_num   11

#define SPI_STC_vect	__vector_12
#define SPI_STC_vect_num   12

#define USART_RXC_vect		__vector_13
#define USART_RXC_vect_num  13

#define USART_UDRE_vect	     __vector_14
#define USART_UDRE_vect_num   14

#define USART_TXC_vect		 __vector_15
#define USART_TXC_vect_num   15


#define SIG_INTERRUPT0     __vector_1
#define SIG_OUTPUT_COMPARE2		__vector_4
#define SIG_OVERFLOW2     __vector_5
#define SIG_OUTPUT_COMPARE1A		__vector_7
#define SIG_OUTPUT_COMPARE1B		__vector_8
#define SIG_OVERFLOW1			__vector_8
#define SIG_OVERFLOW0     __vector_11
#define SIG_OUTPUT_COMPARE0     __vector_10
#define SIG_UART_RECV     __vector_13
#define SIG_UART_DATA     __vector_14
#define SIG_UART_TRANS     __vector_15
#define SIG_SPI     __vector_12





#  define ISR(vector, ...)            \
void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \
void vector (void)




#endif /* ROUTINES_H_ */
