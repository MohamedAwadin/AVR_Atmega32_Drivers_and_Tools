
#ifndef HBRIDGE_MOTOR_INTERFACE_H_
#define HBRIDGE_MOTOR_INTERFACE_H_

#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "DIO_Interface.h"

typedef enum{
	motorcw=0,
	motorccw,
	motorstop
	}MOTOR_Status;

/*****FUNCATION TO USE*******/
void HBRIDGE_MOTOR(MOTOR_Status statue,DIO_Pin_type EN1,DIO_Pin_type EN2);
void RELAY_MOTOR(MOTOR_Status statue,DIO_Pin_type EN1,DIO_Pin_type EN2);
/******END********/

#endif /* HBRIDGE_MOTOR_INTERFACE_H_ */