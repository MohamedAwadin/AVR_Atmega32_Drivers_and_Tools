/*
 * KeyPad.h
 *
 * Created: 04/10/2020 05:10:25 م
 *  Author: A4 Center
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_


#define  F_CPU    8000000UL
#include <util/delay.h>

#include "StdTypes.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "LCD.h"
#include <math.h>

#define  FRIST_IN  PINB0 //Colum's
#define  FRIST_OUT PINB4 //Row's

#define  DEFULT_KEY '.'

u8 KEYPAD_GetEntry(void);
void Save_Write_Num(u8 x , u16 num);
/*****************************************/
/***************Funcations of Converter*****/
void CONV_DECtoBIN(u8 num );
void CONV_DECtoHEX(u32 decimal);
void CONV_HEXtoDEC(u8 * hex);
void Strrev(u8 *head);
u8 string_lens(u8 * str);
u16 powr(u16 num,u8 pw);
#endif /* KEYPAD_H_ */