
#include "I2C.h"

void I2C_Init(void)
{
	
	//@TWBR >> TWI Bit Rate Reg 
	TWBR = 72;  //Bit Rate : 400,000 MHz
	/**********/
	
	
	//@TWSR >> TWI Status Reg
	/*
	BIT7->BIT3 >> TWS : TWI Status
	BIT1 -BIT0 >> TWPS: TWI Prescaler Bits
	*/
	TWSR = 0x00;
	
	/*********/
	
	
	// @TWCR >> TWI Control Reg 
	/*Bit 6 – TWEA: TWI Enable Acknowledge Bit
	The TWEA bit controls the generation of the acknowledge pulse. If the TWEA bit is written to
	one, the ACK pulse is generated on the TWI bus if the following conditions are met:
	1. The device’s own slave address has been received.
	2. A general call has been received, while the TWGCE bit in the TWAR is set.
	3. A data byte has been received in Master Receiver or Slave Receiver mode.
	By writing the TWEA bit to zero, the device can be virtually disconnected from the Two-wire
	Serial Bus temporarily.*/
	/*• Bit 2 – TWEN: TWI Enable Bit
	The TWEN bit enables TWI operation and activates the TWI interface. When TWEN is written to
	one, the TWI takes control over the I/O pins connected to the SCL and SDA pins, enabling the
	slew-rate limiters and spike filters. If this bit is written to zero, the TWI is switched off and all TWI
	transmissions are terminated, regardless of any ongoing operation.*/
	TWCR = 0x44; // 0b01000100
	/***********/
	
	//@TWAR:TW Bus SLAVE Address
	// General Call Recongnition: off
	TWAR = 0b00000010;
	
}
void I2C_Start(void)
{
	//TWCR = 0b10100100
	// SET BIT2 >> TWEN: TWI ENABLE Bit
	// SET BIT5 >> TWSTA: TWI start Condition Bit
	// SET BIT7 >> TWINT: TWI Interrupt flag . 
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	/*
	Wait for TWINT Flag set. This indicates
	that the START condition has been
	transmitted*/
}
void I2C_Stop(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	//Transmit STOP condition
}
void I2C_Write(u8 data)
{
	TWDR = data;
	TWCR = (1<<TWINT) | (1<<TWEN);
	/*Load DATA into TWDR Register. Clear
	TWINT bit in TWCR to start transmission
	of data*/
	while (!(TWCR & (1<<TWINT)));
	/*Wait for TWINT Flag set. This indicates
	that the DATA has been transmitted, and
	ACK/NACK has been received.*/
}
u8 I2C_Read_ACK(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA); //ACK Enable 
	while(!(TWCR & (1 << TWINT))); 
	return TWDR;
}
u8 I2C_Read_NO_ACK(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN); //ACK Enable
	while(!(TWCR & (1 << TWINT)));
	return TWDR;
}
u8 I2C_Status(void)
{
	u8 status;
	status = (TWSR & 0xF8);
	return status;
}