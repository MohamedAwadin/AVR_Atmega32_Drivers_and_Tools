
#ifndef UART_SERVICES_H_
#define UART_SERVICES_H_

#include "UART.h"

void UART_SendInt(u32 num);
u32 UART_ReceiveInt(void);
void UART_SendString(u8*str);
void UART_ReceiveString(u8*str);
void UART_SendString_CS(u8*str);
u8 UART_ReceiveString_CS(u8 *str);
void UART_SendString_Asynch(u8* str);
void UART_ReseiveString_Asynch(u8*str);
u8 get_flag(void);
#endif /* UART_SERVICES_H_ */