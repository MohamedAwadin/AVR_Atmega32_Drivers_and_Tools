/*
 * EEPROM.h
 *
 * Created: 15/01/2021 02:19:51 ص
 *  Author: Mohamed Awadin 
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_
#define  F_CPU    8000000UL
#include <util/delay.h>
#include "I2C.h"

void EEPROM_WriteByte(u8 addres, u8 data);
u8 EEPROM_ReadByte(u8 addres);


#endif /* EEPROM_H_ */