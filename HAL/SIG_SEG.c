#include "SIG_SEG_Interface.h"
#include "StdTypes.h"
#include "Utils.h"
#include "MemMap.h"
#include "DIO_Interface.h"
const u8 segNumbers2[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

void SIGNAL_2segment_display(u8 n,DIO_Port_type MONO_SEGMENT_PORT,DIO_Port_type TENS_SEGMENT_PORT)
{   
	u8 temp,UNIT_NUM,TENS_NUM;
	temp=n;
	UNIT_NUM = segNumbers2[temp/10];
	temp =n;  
	TENS_NUM = segNumbers2[temp%10];

    switch(MONO_SEGMENT_PORT)
    {
	    case PA:
	    DIO_WritePort(PA,UNIT_NUM);
	    break;
	    case PB:
	    DIO_WritePort(PB,UNIT_NUM);
	    break;
	    case PC:
	    DIO_WritePort(PC,UNIT_NUM);
	    break;
	    case PD:
	    DIO_WritePort(PD,UNIT_NUM);
	    break;
    }
	switch(TENS_SEGMENT_PORT)
    {
	    case PA:
	    DIO_WritePort(PA,TENS_NUM);
	    break;
	    case PB:
	    DIO_WritePort(PB,TENS_NUM);
	    break;
	    case PC:
	    DIO_WritePort(PC,TENS_NUM);
	    break;
	    case PD:
	    DIO_WritePort(PD,TENS_NUM);
	    break;
    } 	
}