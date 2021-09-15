/*
 * KeyPad.c
 *
 * Created: 04/10/2020 05:10:06 م
 *  Author: A4 Center
 */ 
#include "KeyPad.h"

static u8 Keys_Array[4][4]={{'7','8','9','/'},
                      {'4','5','6','*'},
				      {'1','2','3','-'},
				      {'c','0','=','+'}};
						  
u8 KEYPAD_GetEntry(void )
{
	u8 raw,col,key=DEFULT_KEY;
	DIO_WritePin(FRIST_OUT,HIGH);
	DIO_WritePin(FRIST_OUT+1,HIGH);
	DIO_WritePin(FRIST_OUT+2,HIGH);
	DIO_WritePin(FRIST_OUT+3,HIGH);
	for (raw=0;raw<4;raw++)
	{
		DIO_WritePin(FRIST_OUT+raw,LOW);
		
		
		for (col=0;col<4;col++)
		{
			if (DIO_ReadPin(FRIST_IN+col)==LOW)
			{
				key=Keys_Array[raw][col];
				while(DIO_ReadPin(FRIST_IN+col)==LOW);
			}
		}
		DIO_WritePin(FRIST_OUT+raw,HIGH);
		
	}return key;
	}


void Save_Write_Num(u8 x , u16 num)
{
	if ((x>='0')&&(x<='9'))
	{
        num = (num*10)+(x-'0');
		LCD_WriteChar(x);
			
	}
}	
/*****************************************************/
/*************Funcations of Converter****************/
void CONV_DECtoBIN(u8 num )
{
	s8 i;
	for (i=7;i>=0;i--)
	{
		LCD_WriteData(((num>>i)&1)+'0');
	}	
}
/*********/


void Strrev(u8 *source)
{
	if (!source) return;
	u8 *temp = source;
	while(*temp) ++temp;    //find the length of the string
	--temp;                // temp points to the last real char
	                      // source still points to the first
	for( ; source < temp; ++source, --temp) {
		// walk pointers inwards until they meet or cross in the middle
		u8 s = *source, t = *temp;
		*source = t;           // swapping as we go
		*temp = s;
	}
}
void CONV_DECtoHEX(u32 decimal)
{
	u8 HEXVALUE[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

	u32 tempDecimal;
	u8 hex[65];
	u8 index, rem;
	tempDecimal = decimal;
    if (decimal == 0)
    {
		LCD_WriteChar(HEXVALUE[0]);
    }
	else if (decimal != 0)
	{
	index = 0;
	while(tempDecimal !=0)
	{
		rem = tempDecimal % 16;

		hex[index] = HEXVALUE[rem];

		tempDecimal /= 16;

		index++;
	}
	hex[index] = '\0';

	Strrev(hex);
	LCD_WriteString(hex);
	
	}
}
/***********/
u8 string_lens(u8 * str)
{
	u8 i;
	for (i=0; str[i]!=0 ; i++);
	return i;
}

u16 powr(u16 num,u8 pw)
{
	u8 result=0  ;
	for (u8 i = pw; i>0 ; i--)
	{
		num = num * num ;
		result = result + num ;
	}
	return result;
}

void CONV_HEXtoDEC(u8 * hex)
{
	
	u32 decimal = 0, base = 1;
	u8 i = 0, value, length;
	
	length = string_lens(hex);
	for(i = length--; i >= 0; i--)
	{
		if(hex[i] >= '0' && hex[i] <= '9')
		{
			decimal += (hex[i] - 48) * base;
			base *= 16;
		}
		else if(hex[i] >= 'A' && hex[i] <= 'F')
		{
			decimal += (hex[i] - 55) * base;
			base *= 16;
		}
		else if(hex[i] >= 'a' && hex[i] <= 'f')
		{
			decimal += (hex[i] - 87) * base;
			base *= 16;
		}
	}
	
	LCD_WriteNumber(hex);
	
}