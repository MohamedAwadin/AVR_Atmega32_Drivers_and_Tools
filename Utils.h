/*
 * Utils.h
 *
 * Created: 22/09/2020 03:29:45 م
 *  Author: A4 Center
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define   SET_BIT(reg,bit)      (reg=reg|(1<<bit))
#define   CLEAR_BIT(reg,bit)    (reg=reg&(~(1<<bit)))
#define   READ_BIT(reg,bit)     ((reg>>bit)&1)
#define   TOGGLE_BIT(reg,bit)      (reg=reg^(1<<bit))
#define   WRITE_BIT(reg,bit,valu) (reg=reg&(~(1<<bit)|(valu<<bit)))




#endif /* UTILS_H_ */