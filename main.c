
#define  F_CPU    8000000UL
#include <util/delay.h>

#include "MemMap.h"
#include "StdTypes.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "MXSEG_Interface.h"
#include "LCD.h"
#include "TIMER.h"
//#include "KeyPad.h"
//#include "Stepeer_Interface.h"
//#include "ADC.h"
//#include "Sensor.h"
//#include "EEPROM.h"
//#include "I2C.h"
//#include "UART.h"
//#include "UART_Services.h"
//#include "SPI.h"
#include "OS.h"
#include "Tasks.h"
volatile static u16 u16Secs =0 ;
volatile static u16 u16Millis =0 ;
volatile static u16 u16_100uSCounter =0 ;

void vInitEcu(void)
{
	u8  str[] = {"Seconds: "};
		sei();
		DIO_Init();
		DIO_InitPin(PINB0,OUTPUT);
		DIO_InitPin(PINB2,OUTPUT);
		
		DIO_WritePin(PINB0,LOW);
		DIO_WritePin(PINB0,LOW);
		
		LCD_Init();
		LCD_WriteString(str);
}

void vMillisIncrement(void)
{
	u16_100uSCounter++; 
	
	if (u16_100uSCounter >= 10)
	{
		u16_100uSCounter =0 ;
		u16Millis++:
	}
	if (u16Millis >= 10)
	{
		u16Millis =0 ;
		u16Secs++:
		OS_TaskTimer();
	}

}

void cInitScheduler(void)
{
	Timer0_Init(TIMER0_NORMAL_MODE,TIMER0_SCALER_8,OCO_DISCONNECTED);
	Timer0_OV_InterruptEnable();
	Timer0_OVF_SetCallBack(vMillisIncrement);
	
	OS_TaskCreate(&Task_2S_Blink,2,BLOCKED); //(TASK,Pirudisty.status)
	OS_TaskCreate(&Task_1S_LcdUpdate,1,BLOCKED); //(TASK,Pirudisty.status)
	OS_TaskCreate(&Task_3S_Blink,3,BLOCKED); //(TASK,Pirudisty.status)

}


int main(void)
{
	vInitEcu();
	cInitScheduler();
	
	
   
	
	while(1)
	{
		OS_TaskExecution();
		
	}
}
