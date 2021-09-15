

#include "UART.h"

void UART_Init(void)
{
	
	//baud rate 9600
	UBRRL=51;
	
	//Enable Transimeter,Receiver
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
	
}
void UART_Send(u8 data)
{
	
	while(!READ_BIT(UCSRA,UDRE));
	UDR =data;
	
}
u8 UART_Receive(void)
{
	
	while(!READ_BIT(UCSRA,RXC));
	return UDR;
}
void UART_SendNoBlock(u8 data)
{
	UDR =data;	
}
u8 UART_ReceiveNoBlock(void)
{
	return UDR;
}
u8 UART_ReceiveDataNoBlock(u8 *pdata)
{
	if(READ_BIT(UCSRA,RXC))
	{
		*pdata=UDR;
		return 1;
	}
	else
	{
		return 0;
	}
}

/********************Int Func**************/
void UART_RX_InterruptEnable(void)
{
	SET_BIT(UCSRB,RXCIE);
}

void UART_RX_InterruptDisable(void)
{
	CLEAR_BIT(UCSRB,RXCIE);
}

void UART_TX_InterruptEnable(void)
{
	SET_BIT(UCSRB,TXCIE);
}

void UART_TX_InterruptDisable(void)
{
	CLEAR_BIT(UCSRB,TXCIE);
}
/******************************/