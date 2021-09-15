

#ifndef UART_H_
#define UART_H_

#include "StdTypes.h"
#include "Utils.h"
#include "MemMap.h"

void UART_Init(void);
//Busy Wait.
void UART_Send(u8 data);
u8 UART_Receive(void);
/********/
// Intrrupt.
void UART_SendNoBlock(u8 data);
u8 UART_ReceiveNoBlock(void);
/********/
//Perodic Cheack
u8 UART_ReceiveDataNoBlock(u8 *pdata);
/*********/
/********************Int Func**************/
void UART_RX_InterruptEnable(void);
void UART_RX_InterruptDisable(void);
void UART_TX_InterruptEnable(void);
void UART_TX_InterruptDisable(void);
/*************************************/
#endif /* UART_H_ */