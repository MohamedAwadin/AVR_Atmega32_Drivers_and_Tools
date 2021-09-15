


#include "MXSEG_Interface.h"
#include "StdTypes.h"
#include "Utils.h"
#include "MemMap.h"
#include "DIO_Interface.h"

#define  F_CPU    8000000UL
#include <util/delay.h>

const u8 segNumbers[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

void MIX_2segment_display(u8 n,DIO_Pin_type ENABLE1,DIO_Pin_type ENABLE2,DIO_Port_type SEGMENT_PORT)
{
	u8 temp , unit_num,tens_num;
	temp=n;
	unit_num = segNumbers[temp/10];
	temp=n;
	tens_num = segNumbers[temp%10];
	switch(SEGMENT_PORT)
	{
		case PA:
	    DIO_WritePin(ENABLE1,HIGH);
	    DIO_WritePin(ENABLE2,LOW);
	    DIO_WritePort(PA,unit_num);
	    _delay_ms(1);
	    DIO_WritePin(ENABLE2,HIGH);
	    DIO_WritePin(ENABLE1,LOW);
	    DIO_WritePort(PA,tens_num);
	    _delay_ms(1);
		break;
		case PB:
		DIO_WritePin(ENABLE1,HIGH);
		DIO_WritePin(ENABLE2,LOW);
		DIO_WritePort(PB,unit_num);
		_delay_ms(1);
		DIO_WritePin(ENABLE2,HIGH);
		DIO_WritePin(ENABLE1,LOW);
		DIO_WritePort(PB,tens_num);
		_delay_ms(1);
		break;
		case PC:
		DIO_WritePin(ENABLE1,HIGH);
		DIO_WritePin(ENABLE2,LOW);
		DIO_WritePort(PC,unit_num);
		_delay_ms(1);
		DIO_WritePin(ENABLE2,HIGH);
		DIO_WritePin(ENABLE1,LOW);
		DIO_WritePort(PC,tens_num);
		_delay_ms(1);
		break;
		case PD:
		DIO_WritePin(ENABLE1,HIGH);
		DIO_WritePin(ENABLE2,LOW);
		DIO_WritePort(PD,unit_num);
		_delay_ms(1);
		DIO_WritePin(ENABLE2,HIGH);
		DIO_WritePin(ENABLE1,LOW);
		DIO_WritePort(PD,tens_num);
		_delay_ms(1);
		break;						
	}

}

