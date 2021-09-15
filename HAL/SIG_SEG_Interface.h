

#ifndef SIG_SEG_Interface_H_
#define SIG_SEG_Interface_H_

#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "DIO_Interface.h"



/******FUNCATION TO USE*******/
extern void SIGNAL_2segment_display(u8 n,DIO_Port_type MONO_SEGMENT_PORT,DIO_Port_type TENS_SEGMENT_PORT);

/**********END***************/
extern const u8 segNumbers2[];
#endif /* SIG_SEG_H_ */