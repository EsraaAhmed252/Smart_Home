#ifndef MEMMAP_H_
#define MEMMAP_H_

//////////////    DIO Registers   //////////////

#define PORTA *((volatile u8*)0x3B)
#define DDRA *((volatile u8*)0x3A)
#define PINA *((volatile u8*)0x39)

#define PORTB *((volatile u8*)0x38)
#define DDRB *((volatile u8*)0x37)
#define PINB *((volatile u8*)0x36)

#define PORTC *((volatile u8*)0x35)
#define DDRC *((volatile u8*)0x34)
#define PINC *((volatile u8*)0x33)

#define PORTD *((volatile u8*)0x32)
#define DDRD *((volatile u8*)0x31)
#define PIND *((volatile u8*)0x30)

////////////// TIMER0_Registers //////////////

#define TCCR0  *((volatile u8*)  0x53)
#define TCNT0  *((volatile u8*)  0x52)
#define TIFR  *((volatile u8*)  0x58)
#define TIMSK  *((volatile u8*)  0x59)
#define OCR0  *((volatile u8*)  0x5C)

////////////// TIMER1_Registers //////////////

#define TCCR1A  *((volatile u8*)  0x4F)
#define TCCR1B  *((volatile u8*)  0x4E)
#define TCNT1  *((volatile u8*)  0x4C)
#define OCR1A  *((volatile u16*)  0x4A)
#define OCR1BH  *((volatile u8*)  0x49)
#define OCR1BL  *((volatile u8*)  0x48)
#define ICR1  *((volatile u16*)  0x46)

////////////// TIMER2_Registers //////////////

#define TCCR2   (*((volatile u8*)0x45))
#define TCNT2   (*((volatile u8*)0x44))
#define OCR2  (*((volatile u8*)0x43))

////////////// WDT_Registers //////////////

#define WDTCR  *((volatile u8*)  0x41)

////////////// INTERRUPT_Registers //////////////

#define MCUCR *((volatile u8*) 0x55)
#define MCUCSR *((volatile u8*) 0x54)
#define GICR *((volatile u8*) 0x5B)
#define SREG *((volatile u8*) 0x5F)
#define GIFR *((volatile u8*) 0x5A)

////////////// ADC_Registers //////////////

#define ADMUX *((volatile u8*)0x27)

#define ADLAR 5
#define REFS0 6
#define REFS1 7

#define ADCSRA *((volatile u8*)0x26)
#define ADPS0 0
#define ADPS1 1
#define ADPS2 2
#define ADIE  3
#define ADIF  4
#define ADATE 5
#define ADSC  6
#define ADEN  7

#define ADCL *((volatile u8*)0x24)
#define ADCH *((volatile u8*)0x25)

#define ADC  *((volatile u16*)0x24)

////////////// UART_Registers //////////////

#define UDR			*((volatile u8*)0x2C)
#define UCSRA		*((volatile u8*)0x2B)
#define UCSRB		*((volatile u8*)0x2A)
#define UCSRC		*((volatile u8*)0x40)
#define UBRRH		*((volatile u8*)0x40)
#define UBRRL		*((volatile u8*)0x29)

////////////// SPI_Registers //////////////

#define SPCR		*((volatile u8*)0x2D)
#define SPSR		*((volatile u8*)0x2E)
#define SPDR		*((volatile u8*)0x2F)

////////////// I2C_Registers //////////////

#define TWDR		*((volatile u8*)0x23)
#define TWAR		*((volatile u8*)0x22)
#define TWSR		*((volatile u8*)0x21)
#define TWBR		*((volatile u8*)0x20)
#define TWCR		*((volatile u8*)0x56)

#endif /* MEMMAP_H_ */
