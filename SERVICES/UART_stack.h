

#ifndef UART_STACK_H_
#define UART_STACK_H_

#define STACK_SIZE 100
#include "UART.h"
typedef enum{
	STACK_FULL,
	STACK_EMPTY,
	DONE
	}StackStatues_type;

StackStatues_type push(u8 data);
StackStatues_type pop(u8 *pdata);

#endif /* UART_STACK_H_ */