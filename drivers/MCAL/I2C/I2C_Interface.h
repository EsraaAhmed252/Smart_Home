#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

void I2c_Master_init(u8 add);
void I2C_SendStartCondition(void);
void I2C_SendRepStartCondition(void);
void I2C_SendStopCondition(void);
void I2C_SendSlaveAdd_Write(u8 slave_add);
void I2C_SendSlaveAdd_Read(u8 slave_add);
void I2C_MasterData_Send(u8 data);
u8 I2C_MasterData_Read(void);


#endif /* I2C_INTERFACE_H_ */
