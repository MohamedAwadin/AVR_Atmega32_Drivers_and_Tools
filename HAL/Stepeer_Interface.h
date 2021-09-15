/*
 * Stepeer_Interface.h
 *
 * Created: 27/09/2020 04:09:02 م
 *  Author: A4 Center
 */ 



#ifndef STEPEER_INTERFACE_H_
#define STEPEER_INTERFACE_H_


#include "StdTypes.h"
#include "Utils.h"
#include "MemMap.h"

#include "DIO_Interface.h"
#define  F_CPU    8000000UL
#include <util/delay.h>

typedef enum{
	CW=0,
	CCW,
}Stepper_DIR;

#define BI_POLAR   0
#define UNI_POLAR  1

/*******************STEPPER PIN CONFIG*********/

#define MOTOR_TYPE   UNI_POLAR

#define COIL1 PINA3
#define COIL2 PINA4
#define COIL3 PINA5
#define COIL4 PINA6 
#define DELAY 5
/*************************/
void Stepper_CW(void);
void Stepper_CCW(void);

void Stepper_CW(void);
void Stepper_CCW(void);
void Stepper_Stop(void);
void Stepper_CW_HALFSTEP(void);
void SET_Angle(Stepper_DIR dir,u16 Angle);
void STEPPER_REVOLUTION(Stepper_DIR dir,u8 rev);
#endif /* STEPEER_INTERFACE_H_ */