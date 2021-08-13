/*
 * seven_segment.h
 *
 * Created: 7/19/2020 9:01:04 PM
 *  Author: safifi
 */ 


#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_

#include "std_macros.h"


#define  INIT_7_SEG_PORT DDRA |=0b11111110; DDRC |= 0b11000000; 

#define  EN1(x)    if(x == 0) CLRBIT(PORTC,6); else SETBIT(PORTC,6);
#define  EN2(x)    if(x == 0) CLRBIT(PORTC,7); else SETBIT(PORTC,7);
#define  A(x)    if(x == 0) CLRBIT(PORTA,1); else SETBIT(PORTA,1);
#define  B(x)    if(x == 0) CLRBIT(PORTA,2); else SETBIT(PORTA,2);
#define  C(x)    if(x == 0) CLRBIT(PORTA,3); else SETBIT(PORTA,3);
#define  D(x)    if(x == 0) CLRBIT(PORTA,4); else SETBIT(PORTA,4);
#define  E(x)    if(x == 0) CLRBIT(PORTA,5); else SETBIT(PORTA,5);
#define  F(x)    if(x == 0) CLRBIT(PORTA,6); else SETBIT(PORTA,6);
#define  G(x)    if(x == 0) CLRBIT(PORTA,7); else SETBIT(PORTA,7);


void seven_Seg_init();
void seven_Seg_write(uint8_t x);




#endif /* SEVEN_SEGMENT_H_ */