

#ifndef SPI_H_
#define SPI_H_

#include "MemMap.h"
#include "Utils.h"
#include "StdTypes.h"

void SPI_IniMaster(void);
void SPI_IniSlave(void);
u8 SPI_SendReceive(u8 data);
u8 SPI_ReceiveNoBlock(void);
void SPI_SendNoBlock(u8 data);
u8 SPI_ReceivePeridicChacking(u8 *pdata);
void SPI_InterruptEnable(void);
void SPI_InterruptDisable(void);
#endif /* SPI_H_ */