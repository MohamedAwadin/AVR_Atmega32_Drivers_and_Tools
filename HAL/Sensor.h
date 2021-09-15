

#ifndef SENSOR_H_
#define SENSOR_H_

#include "StdTypes.h"
#include "ADC.h"

#define POT_CH CH_3
#define LM35   CH_4
#define MPX_CH CH_5
u16 POT_VoltRead(void);
u16 TEMP_Read(void);
u16 MPX_Read(void);
u16 POT_PERRead(void);

#endif /* SENSOR_H_ */