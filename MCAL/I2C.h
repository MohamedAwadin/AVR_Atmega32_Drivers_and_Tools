


#ifndef I2C_H_
#define I2C_H_

#include "MemMap.h"
#include "Utils.h"
#include "StdTypes.h"

void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Write(u8 data);
u8 I2C_Read_ACK(void);
u8 I2C_Read_NO_ACK(void);
u8 I2C_Status(void);



#endif /* I2C_H_ */