/*
 * Tasks.h
 *
 * Created: 01/09/2021 12:14:38 ص
 *  Author: A4 Center
 */ 


#ifndef TASKS_H_
#define TASKS_H_
#include "StdTypes.h"
#include "Utils.h"
#include "MemMap.h"
#include "DIO_Interface.h"
#include "LCD.h"

void Task_2S_Blink(void);
void Task_1S_LcdUpdate(void);
void Task_3S_Blink(void);




#endif /* TASKS_H_ */