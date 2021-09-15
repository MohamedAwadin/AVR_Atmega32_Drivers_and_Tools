

#ifndef MXSEG_INTERFACE_H_
#define MXSEG_INTERFACE_H_

#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "DIO_Interface.h"

/*****FUNCATION TO USE************/        
extern void MIX_2segment_display(u8 n,DIO_Pin_type ENABLE1,DIO_Pin_type ENABLE2,DIO_Port_type SEGMENT_PORT);
/*********END*********/

#endif /* SEG_INTERFACE_H_ */