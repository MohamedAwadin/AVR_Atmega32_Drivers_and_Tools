
#ifndef SERVO_H_
#define SERVO_H_

#include "TIMER.h"

#define SERVO_PIN OCR1A


void SERVO_Init(void);
void SERVO_SETAngle(u8 angle);




#endif /* SERVO_H_ */