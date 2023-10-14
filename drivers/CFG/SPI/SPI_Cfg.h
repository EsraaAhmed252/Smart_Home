#ifndef SPI_CFG_H_
#define SPI_CFG_H_

#define Master 1
#define Slave 2

#define SPI_Mode Slave

#define  Rising 1
#define  falling 2

#define Clock_pol falling

#define Sample 1
#define Setup 2

#define Clock_phase Setup

#define _4_prescalar 0
#define _16_prescalar 1
#define _64_prescalar 2
#define _128_prescalar 3

#define SPI_Prescaler _16_prescalar

#define Enable 0
#define Disable 1

#define SPI_x2Speed Disable

#endif /* SPI_CFG_H_ */
