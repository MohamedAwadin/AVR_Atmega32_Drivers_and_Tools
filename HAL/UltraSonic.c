

#include "UltraSonic.h"

static volatile u16 t1,t2,flag=0,c=0;

void UltraSonic_Init(void)
{
     
	 Timer1_Init(TIMER1_NORMAL_MODE,TIMER1_SCALER_8,OC1A_DISCONNECTED,OC1B_DISCONNECTED);
	 Timer1_OVF_SetCallBack(Func_OVF);
	 Timer1_ICU_SetCallBack(Func_ICU);
}

u8 UltraSonic_GetDistance(DIO_Pin_type UltraSonic_pin )
{
	u8 Distance;
	u16 Time;
	TCNT1 =0;
	c=0;
	flag=0;
	DIO_WritePin(UltraSonic_pin ,HIGH);
	_delay_us(10);
	DIO_WritePin(UltraSonic_pin ,LOW);
	Timer1_InputCaptureEdge(RISING);
	Timer1_ICU_InterruptEnable();
	while(flag<2);
	Time = t2-t1 +((u32)c*65535);
	Distance = Time/58 ;
	Timer1_ICU_InterruptDisable();
	return Distance; 
}
void UltraSonic_Start(DIO_Pin_type UltraSonic_pin)
{
	if (flag == 0)
	{
		DIO_WritePin(UltraSonic_pin,HIGH);
		_delay_us(10);
		DIO_WritePin(UltraSonic_pin,LOW);
		Timer1_InputCaptureEdge(RISING);
		Timer1_ICU_InterruptEnable();
		Timer1_OVF_InterruptEnable();
	}
	
}
u8 UltraSonic_GetDistanceNoBlock(u8 *Pdistance)
{
	u8 distance;
	u16 time ;
	if (flag == 2)
	{
		time = t2-t1 +((u32)c*65535);
		distance = time/58 ;
		Timer1_ICU_InterruptEnable();
		flag =0;
		return 1;
	}
	return 0;
}
u8 UltraSonic_GetDistance2(DIO_Pin_type UltraSonic_pin)
{
	u8 distance;
	u16 time;
	DIO_WritePin(UltraSonic_pin,HIGH);
	_delay_us(10); 
	DIO_WritePin(UltraSonic_pin,LOW);
	while(!DIO_ReadPin(ECHO_PIN));
	TCNT1=0;
	while(DIO_ReadPin(ECHO_PIN));
	time =TCNT1;
	distance = time/58;
	return distance;
}
static void Func_ICU(void)
{
	if (flag == 0)
	{
		c=0;
		t1=ICR1;
		flag =1;
		Timer1_InputCaptureEdge(FALLING);
	}
	else if(flag ==1)
	{
		t2=ICR1;
		flag =2;
		Timer1_InputCaptureEdge(RISING);
		Timer1_OVF_InterruptDisable();
		Timer1_ICU_InterruptDisable();
	}
}
static void Func_OVF(void)
{
	c++;
}