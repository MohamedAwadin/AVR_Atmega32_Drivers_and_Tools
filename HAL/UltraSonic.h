


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
#define  F_CPU    8000000UL
#include <util/delay.h>


#include "DIO_Interface.h"
#include "TIMER.h"
#include "TimerServices.h"
#include "EXInterrupt.h"

#define ECHO_PIN PIND6

void UltraSonic_Init(void);
u8 UltraSonic_GetDistance(DIO_Pin_type UltraSonic_pin );
void UltraSonic_Start(DIO_Pin_type UltraSonic_pin);
u8 UltraSonic_GetDistanceNoBlock(u8 *Pdistance);
u8 UltraSonic_GetDistance2(DIO_Pin_type UltraSonic_pin);
static void Func_ICU(void);
static void Func_OVF(void);


#endif /* ULTRASONIC_H_ */