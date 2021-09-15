

#include "Stepeer_Interface.h"

#include "DIO_Interface.h"
#if(MOTOR_TYPE==BI_POLAR)

void Stepper_CW(void)
{
	DIO_WritePin(COIL1,HIGH);
	DIO_WritePin(COIL2,LOW);
	DIO_WritePin(COIL3,LOW);
	DIO_WritePin(COIL4,LOW);
	_delay_ms(500);
	DIO_WritePin(COIL1,LOW);
	DIO_WritePin(COIL2,LOW);
	DIO_WritePin(COIL3,HIGH);
	DIO_WritePin(COIL4,LOW);
	_delay_ms(500);
	DIO_WritePin(COIL1,LOW);
	DIO_WritePin(COIL2,HIGH);
	DIO_WritePin(COIL3,LOW);
	DIO_WritePin(COIL4,LOW);
	_delay_ms(500);
	DIO_WritePin(COIL1,LOW);
	DIO_WritePin(COIL2,LOW);
	DIO_WritePin(COIL3,LOW);
	DIO_WritePin(COIL4,HIGH);
	_delay_ms(500);
}
void Stepper_CCW(void)
{
	DIO_WritePin(COIL1,LOW);
	DIO_WritePin(COIL2,HIGH);
	DIO_WritePin(COIL3,LOW);
	DIO_WritePin(COIL4,LOW);
	_delay_ms(500);
	DIO_WritePin(COIL1,LOW);
	DIO_WritePin(COIL2,LOW);
	DIO_WritePin(COIL3,LOW);
	DIO_WritePin(COIL4,HIGH);
	_delay_ms(500);
	DIO_WritePin(COIL1,HIGH);
	DIO_WritePin(COIL2,LOW);
	DIO_WritePin(COIL3,LOW);
	DIO_WritePin(COIL4,LOW);
	_delay_ms(500);
	DIO_WritePin(COIL1,LOW);
	DIO_WritePin(COIL2,LOW);
	DIO_WritePin(COIL3,HIGH);
	DIO_WritePin(COIL4,LOW);
	_delay_ms(500);
}

#elif(MOTOR_TYPE==UNI_POLAR)

void Stepper_CW(void)
{
		   DIO_WritePin(COIL1,HIGH);
		   DIO_WritePin(COIL2,LOW);
		   DIO_WritePin(COIL3,LOW);
		   DIO_WritePin(COIL4,LOW);
		   _delay_ms(DELAY);
		   DIO_WritePin(COIL1,LOW);
		   DIO_WritePin(COIL2,HIGH);
		   DIO_WritePin(COIL3,LOW);
		   DIO_WritePin(COIL4,LOW);
		   _delay_ms(DELAY);
		   DIO_WritePin(COIL1,LOW);
		   DIO_WritePin(COIL2,LOW);
		   DIO_WritePin(COIL3,HIGH);
		   DIO_WritePin(COIL4,LOW);
		   _delay_ms(DELAY);
		   DIO_WritePin(COIL1,LOW);
		   DIO_WritePin(COIL2,LOW);
		   DIO_WritePin(COIL3,LOW);
		   DIO_WritePin(COIL4,HIGH);
		   _delay_ms(DELAY);		   
}
void Stepper_CCW(void)
{
	DIO_WritePin(COIL4,HIGH);
	DIO_WritePin(COIL3,LOW);
	DIO_WritePin(COIL2,LOW);
	DIO_WritePin(COIL1,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL4,LOW);
	DIO_WritePin(COIL3,HIGH);
	DIO_WritePin(COIL2,LOW);
	DIO_WritePin(COIL1,LOW);
	_delay_ms(DELAY);
    DIO_WritePin(COIL4,LOW);
	DIO_WritePin(COIL3,LOW);
	DIO_WritePin(COIL2,HIGH);
	DIO_WritePin(COIL1,LOW);
	_delay_ms(DELAY);		
	DIO_WritePin(COIL4,LOW);
	DIO_WritePin(COIL3,LOW);
	DIO_WritePin(COIL2,LOW);
	DIO_WritePin(COIL1,HIGH);
	_delay_ms(DELAY);
	
}
void Stepper_Stop(void)
{
	DIO_WritePin(COIL1,LOW);
	DIO_WritePin(COIL2,LOW);
	DIO_WritePin(COIL3,LOW);
	DIO_WritePin(COIL4,LOW);
}
void Stepper_CW_HALFSTEP(void)
{
	DIO_WritePin(COIL1,HIGH);
	DIO_WritePin(COIL2,LOW);
	DIO_WritePin(COIL3,LOW);
	DIO_WritePin(COIL4,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1,HIGH);
	DIO_WritePin(COIL2,HIGH);
	DIO_WritePin(COIL3,LOW);
	DIO_WritePin(COIL4,LOW);
	_delay_ms(DELAY);	
	DIO_WritePin(COIL1,LOW);
	DIO_WritePin(COIL2,HIGH);
	DIO_WritePin(COIL3,LOW);
	DIO_WritePin(COIL4,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1,LOW);
	DIO_WritePin(COIL2,HIGH);
	DIO_WritePin(COIL3,HIGH);
	DIO_WritePin(COIL4,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1,LOW);
	DIO_WritePin(COIL2,LOW);
	DIO_WritePin(COIL3,HIGH);
	DIO_WritePin(COIL4,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1,LOW);
	DIO_WritePin(COIL2,LOW);
	DIO_WritePin(COIL3,HIGH);
	DIO_WritePin(COIL4,HIGH);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1,LOW);
	DIO_WritePin(COIL2,LOW);
	DIO_WritePin(COIL3,LOW);
	DIO_WritePin(COIL4,HIGH);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1,HIGH);
	DIO_WritePin(COIL2,LOW);
	DIO_WritePin(COIL3,LOW);
	DIO_WritePin(COIL4,HIGH);
	_delay_ms(DELAY);
}

#endif


void SET_Angle(Stepper_DIR dir,u16 Angle)
{
	u16 i,x,z;
	z=Angle;
	x= ((z/11.25)*64)/4;
	switch(dir)
	{
		case CW:
		for (i=0;i<x;i++)
		 {
		      Stepper_CW();
		 }
		 break;
		 case CCW:
		 for (i=0;i<x;i++)
		 {
			 Stepper_CCW();
		 }
		 break;
	}
}
void STEPPER_REVOLUTION(Stepper_DIR dir,u8 rev)
{
	u32 i,n=512*rev;
	switch(dir)
	{
		case CW:
		for(i=0;i<n;i++)
		{
			Stepper_CW();
		}
		break;
		case CCW:
		for(i=0;i<n;i++)
		{
			Stepper_CCW();
		}
		break;
		
	}
	
} 