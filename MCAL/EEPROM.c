/*
 * EEPROM.c
 *
 * Created: 15/01/2021 02:20:10 ص
 *  Author: Mohamed Awadin
 */ 

#include "EEPROM.h"

void EEPROM_WriteByte(u8 addres, u8 data)
{
	while((EECR & (1 << EEWE)) == 1);		//Wait for EEWE = 0, EEPROM is ready for read or write
	
	EEAR = addres;							//Put the address in which you want to put the Data
	
	EEDR = data;							//Put the Data you want to save
	
	SET_BIT(EECR,EEMWE);                    //When EEMWE is set, setting EEWE within four clock cycles will write data to the EEPROM at the selected address If EEMWE is zero
	
	SET_BIT(EECR,EEWE);                     // EEWE bit must be written to one to write the value into the EEPROM
	
	_delay_ms(100);
}

u8 EEPROM_ReadByte(u8 addres)
{
	while((EECR & (1 << EEWE)) == 1);	     //Wait for EEWE = 0, EEPROM is ready for read or write
	EEAR = addres;							
	SET_BIT(EECR , EERE);				   // the EERE bit must be written to a logic one to trigger the EEPROM read
	return EEDR;						 
}