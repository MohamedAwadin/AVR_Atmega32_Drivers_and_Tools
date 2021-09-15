

#include "Sensor.h"

u16 POT_VoltRead(void)
{
	u16 adc = ADC_Read(POT_CH);
	u16 volt= ((u32)5000*adc)/1024;   //mVolt
	return volt;
	
	
}

u16 POT_PERRead(void)
{
	u16 adc = ADC_Read(POT_CH);
	u16 volt= ((u32)100*adc)/1023;   //mVolt
	return volt;
	 
	
}

u16 TEMP_Read(void)
{
	u16 adc = ADC_Read(LM35);
	u16 volt= ((u32)5000*adc)/1024;   //mVolt
	u16 temp = volt;
	return temp;
}

u16 MPX_Read(void)
{
	/*
	f32 adc = ADC_Read(MPX_CH);
	u16 volt= ((u32)5000*adc)/1024;   //mVolt
	u16 pressur = ((volt/5.0)+0.095)/0.009;
	return pressur;
	*/
	
	u32 adc= (5.0/1023.0)*ADC_Read(MPX_CH);

	adc=((adc/5.0)+0.095)/0.009-1;
	return adc;
}
