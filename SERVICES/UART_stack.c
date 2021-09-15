
#include "UART_stack.h"

static u8 stack[STACK_SIZE]={0};  // creat stack
static u8 sp=0; // Creat stack pointer to point the LOC of the stack



StackStatues_type push(u8 data)  //push data in the empty LOC on the stack
{
	if (sp==STACK_SIZE)
	{
		return STACK_FULL;
	}
	stack[sp]=data;
	sp++;
	return DONE;
}
StackStatues_type pop(u8 *pdata)  //get the last data saved in the stack and delet it from the stack
{
	if (sp==0)
	{
		return STACK_EMPTY;
	}
	sp--;  //to point to the last data  saved (no to the second empty loc)
	*pdata=stack[sp];
	return DONE;
}