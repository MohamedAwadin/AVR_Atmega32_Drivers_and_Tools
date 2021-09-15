﻿/*
 * LCD.c
 *
 * Created: 29/09/2020 03:22:49 م
 *  Author: A4 Center
 */ 

#include <LCD.h>

#if(LCD_Mode==_8Bit)

void LCD_WriteCommand(u8 command)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePin(RW,LOW);
	DIO_WritePort(LCD_PORT,command);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

void LCD_WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePin(RW,LOW);
	DIO_WritePort(LCD_PORT,data);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

void LCD_Init(void)
{
	_delay_ms(50);
	LCD_WriteCommand(0x38);//8 bitmode,2 line ,5*7
	_delay_ms(1);
	LCD_WriteCommand(0x0c);//cursor,screen,0x0e,0x0f
	_delay_ms(1);
	LCD_WriteCommand(0x01);//Clear screen
	_delay_ms(2);
	LCD_WriteCommand(0x06);//Increase DD RAM address
	_delay_ms(1);
}

#elif(LCD_Mode==_4Bit)
void LCD_WriteCommand(u8 command)
{
	
	
	DIO_WritePin(RS,LOW);
	DIO_WritePin(RW,LOW);
	DIO_WritePin(D0,READ_BIT(command,4));
	DIO_WritePin(D1,READ_BIT(command,5));
	DIO_WritePin(D2,READ_BIT(command,6));
	DIO_WritePin(D3,READ_BIT(command,7));
	
	
	
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	DIO_WritePin(D0,READ_BIT(command,0));
	DIO_WritePin(D1,READ_BIT(command,1));
	DIO_WritePin(D2,READ_BIT(command,2));
	DIO_WritePin(D3,READ_BIT(command,3));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	
}
void LCD_WriteData(u8 data)
{
	
	DIO_WritePin(RS,HIGH);
	DIO_WritePin(RW,LOW);
	
	DIO_WritePin(D0,READ_BIT(data,4));
	DIO_WritePin(D1,READ_BIT(data,5));
	DIO_WritePin(D2,READ_BIT(data,6));
	DIO_WritePin(D3,READ_BIT(data,7));
	
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	
	DIO_WritePin(D0,READ_BIT(data,0));
	DIO_WritePin(D1,READ_BIT(data,1));
	DIO_WritePin(D2,READ_BIT(data,2));
	DIO_WritePin(D3,READ_BIT(data,3));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}
void LCD_Init(void)
{
	_delay_ms(50);
	LCD_WriteCommand(0x02);
	_delay_ms(1);
	LCD_WriteCommand(0x28);//4 bitmode,2 line ,5*7
	_delay_ms(1);
	LCD_WriteCommand(0x0c);//cursor,screen,0x0e,0x0f
	_delay_ms(1);
	LCD_WriteCommand(0x01);//Clear screen
	_delay_ms(2);
	LCD_WriteCommand(0x06);//Increase DD RAM address
	_delay_ms(1);
}
#endif
void LCD_WriteString(u8 *string)
{
	u8 i;
	for(i=0;string[i];i++)
	{
		LCD_WriteData(string[i]);
		
	}
	
	
}
void LCD_Clear(void)
{
	LCD_WriteCommand(0x01);
}

void LCD_GoTo(u8 line , u8 x)
{
	 
	
	if (line==0)
	{
		LCD_WriteCommand(0x80+x);
	}
	else if (line ==1 )
	{
		LCD_WriteCommand(0x80+0X40+x);
	}
	
}
void LCD_WriteNumber(s64 num)
{
	u8 i=0,j,rem,arr[16]={0};
		if (num==0)
		{
			LCD_WriteData('0');
		}
		else 
		{
			if (num<0)
			{
				num=num*(-1);
				 LCD_WriteData('-');
			}
			while(num>0)
			{
				rem=num%10;
				arr[i]= rem +'0';
				i++;
				num=num/10;
			}
			for (j=i;j>0;j--)
			{
				LCD_WriteData(arr[j-1]);
			}

		}
}
void LCD_CreatCharacter(u8 *ptr,u8 add)
{
	LCD_WriteCommand(0x40+add*8);
	for (u8 i=0;i<8;i++)
	{
		LCD_WriteData(ptr[i]);
	}
}
void LCD_WriteChar(u8 ch)
{
	LCD_WriteData(ch);
}
void LCD_WriteNumberInBinary(u8 num )
{
	s8 i;
	for (i=7;i>=0;i--)
	{
		LCD_WriteData(((num>>i)&1)+'0');
	}
	
}
void LCD_WriteNumberInBinary2(u8 num )
{
	s8 i,flag=0;
	for (i=7;i>=0;i--)
	{
		if((num>>i)&1)
		{
			flag=1;
		}
		if (flag==1)
		{
			LCD_WriteData(((num>>i)&1)+'0');
		}
		
	}
	
}
void LCD_WriteNumber_Goto(u8 Line, u8 place , u8 num)
{
	LCD_GoTo(Line,place);
	LCD_WriteNumber(num);
}

void LCD_DisplayNumber_4D(u16 num)
{
	LCD_WriteData(((num%10000)/1000)+'0');
	LCD_WriteData(((num%1000)/100)+'0');
	LCD_WriteData(((num%100)/10)+'0');
	LCD_WriteData(((num%10)/1)+'0');
	
}
