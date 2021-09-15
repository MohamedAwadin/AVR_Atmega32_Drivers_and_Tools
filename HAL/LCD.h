


#ifndef LCD_H_
#define LCD_H_

#define  F_CPU    8000000UL
#include <util/delay.h>

#include "StdTypes.h"
#include "Utils.h"
#include "DIO_Interface.h"

#define _8Bit 0
#define _4Bit 1
 

/****************************CONFIG***********/
#define LCD_Mode _4Bit

#define RS          PINA0
#define RW          PINA1
#define EN          PINA2

//  LCD 4Bit Pin's 
#define D0 PINA0
#define D1 PINA1
#define D2 PINA2
#define D3 PINA3

// LCD 8Bit PORT
#define LCD_PORT    PD
/************************************************************/

void LCD_WriteCommand(u8 command);
void LCD_WriteData(u8 data);
void LCD_Init(void);
void LCD_WriteCommand(u8 command);
void LCD_WriteData(u8 data);
void LCD_Init(void);
void LCD_WriteString(u8 *string);
void LCD_WriteNumber(s64 num);
void LCD_WriteNumberInBinary(u8 num);
void LCD_WriteNumberInBinary2(u8 num );
void LCD_GoTo(u8 line , u8 x);
void LCD_Clear(void);
void LCD_CreatCharacter(u8 *ptr,u8 add);
void LCD_WriteChar(u8 ch);
void LCD_WriteNumber_Goto(u8 Line, u8 place , u8 num);
void LCD_DisplayNumber_4D(u16 num);


#endif /* LCD_H_ */