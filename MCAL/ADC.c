#include "ADC.h"

#include "LCD.h"


static u8 Read_Flag =0;
void ADC_Init(ADC_Vref_type vref , ADC_SCALER_type scaler)
{
	
	// VREF
	switch (vref)
	{
		case VREF_AVCC:
		SET_BIT(ADMUX,REFS0);
		CLEAR_BIT(ADMUX,REFS1);
		break;
		case VREF_AVEF:
		CLEAR_BIT(ADMUX,REFS0);
		CLEAR_BIT(ADMUX,REFS1);
		break;
		case VREF_256:
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
		break;
	}
	//CLOCK
	ADCSRA=ADCSRA&0xF8; //Clear last 3 digit
	scaler = scaler&0x07;
	ADCSRA=ADCSRA|scaler;

    //read adjust right 
	CLEAR_BIT(ADMUX,ADLAR); 

	
	//ENABLE
	SET_BIT(ADCSRA,ADEN);
	
}

u16 ADC_Read(ADC_Channel_type ch)
{
	ADMUX = ADMUX&0xE0; //0B11100000
	ADMUX=ADMUX|ch;
	//Start Conversion
	SET_BIT(ADCSRA,ADSC);
	while(READ_BIT(ADCSRA,ADSC)); //Polling Until ADC End Conversion
	//u16 adc =ADCL|((u16)ADCH<<8)    //second way 
	return ADC;
}

void ADC_StartConversion(ADC_Channel_type ch)
{
	if (Read_Flag==0)
	{
		//selsct channel
		ADMUX = ADMUX&0xE0; //0B11100000
		ADMUX=ADMUX|ch;
		//Start Conversion
		SET_BIT(ADCSRA,ADSC);
		Read_Flag =1; // Don't start again until ADC_GetRead Finish
	}
	
}
u16 ADC_GetRead(void)
{
	while(READ_BIT(ADCSRA,ADSC)); //Polling (Busy wait) Until ADC End Conversion
	//u16 adc =ADCL|((u16)ADCH<<8)    //second way 
	Read_Flag =0 ;
	return ADC;
}
u8 ADC_GetReadNoBlock(u16 *pdata)
{
	if(READ_BIT(ADCSRA,ADSC)==0) //Polling (Perodic Check) Until ADC End Conversion
	{ 
	    //u16 adc =ADCL|((u16)ADCH<<8)    //second way
	    *pdata = ADC;
		 Read_Flag =0 ;
	     return 1 ;
		
	}
	else
	{
		return 0;
	}
}
