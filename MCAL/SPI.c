

#include "SPI.h"


void SPI_IniMaster(void)
{
	//Master
	SET_BIT(SPCR,MSTR);
	//clock
	//polarity
	//phase
	
	
	//ENAPLE
	SET_BIT(SPCR,SPE);
}
void SPI_IniSlave(void)
{
	//Slave
	CLEAR_BIT(SPCR,MSTR);
	
	

	//ENAPLE
	SET_BIT(SPCR,SPE);
}


u8 SPI_SendReceive(u8 data)
{
	SPDR=data;   /* SPI I/O Data Register */
	while(!READ_BIT(SPSR,SPIF));
	return SPDR;
}

void SPI_SendNoBlock(u8 data)
{
	SPDR=data;
}

u8 SPI_ReceiveNoBlock(void)
{
	return SPDR;
}
u8 SPI_ReceivePeridicChacking(u8 *pdata)
{
	if (READ_BIT(SPDR,SPIF))
	{
		*pdata=SPDR;
		return 1;
	}
	else
	{
		return 0;
	}
}
void SPI_InterruptEnable(void)
{
	SET_BIT(SPCR,SPIE);
}
void SPI_InterruptDisable(void)
{
	CLEAR_BIT(SPCR,SPIE);
}