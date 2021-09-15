#include "StdTypes.h"
#include "Utils.h"
#include "MemMap.h"
#include "Hbridge_Motor_Interface.h"
#include "DIO_Interface.h"

void HBRIDGE_MOTOR(MOTOR_Status statue,DIO_Pin_type EN1,DIO_Pin_type EN2)
{	
	switch(statue)
	{
		case motorccw:
		DIO_WritePin(EN1,HIGH);
		DIO_WritePin(EN2,LOW);
		break;
		case motorcw:
		DIO_WritePin(EN1,LOW);
		DIO_WritePin(EN2,HIGH);
		break;
		case motorstop:
		DIO_WritePin(EN1,LOW);
		DIO_WritePin(EN2,LOW);
		break;
	}		
	
}			
void RELAY_MOTOR(MOTOR_Status statue,DIO_Pin_type EN1,DIO_Pin_type EN2)
{
	switch(statue)
	{
		case motorccw:
		DIO_WritePin(EN1,HIGH);
		DIO_WritePin(EN2,HIGH);
		break;
		case motorcw:
		DIO_WritePin(EN1,LOW);
		DIO_WritePin(EN2,LOW);
		break;
		case motorstop:
		DIO_WritePin(EN1,HIGH);
		DIO_WritePin(EN2,LOW);
		break;
	}
}