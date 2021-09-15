#include "Tasks.h"

void Task_2S_Blink(void)
{
	DIO_TogglePin(PINB0);
}

void Task_1S_LcdUpdate(void)
{
	static u16 u16Seconds =1 ;
	
	LCD_GoTo(0,10);
	LCD_WriteNumber(u16Seconds);
	u16Seconds++ ;
}

void Task_3S_Blink(void)
{
	DIO_TogglePin(PINB3);
}