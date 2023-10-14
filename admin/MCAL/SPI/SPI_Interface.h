#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_init(void);
u8 SPI_Transceive(u8 data);
void SPI_Enable_int(void);
void SPI_Set_Callback(void (*ptrf)(u8));
void SPI_Send_data(u8 data);


#endif /* SPI_INTERFACE_H_ */
