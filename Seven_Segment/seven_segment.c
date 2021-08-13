/*
 * seven_segment.c
 *
 * Created: 7/19/2020 9:00:43 PM
 *  Author: safifi
 */ 
#include "seven_segment.h"




void seven_Seg_init(){
	INIT_7_SEG_PORT;
	// initial
}
// 56 % 10 
void seven_Seg_write(uint8_t x){ // 0 --> 99
	uint8_t Digit1 =  x/10;
	uint8_t Digit2 =  x%10;
	EN1(1);
	EN2(0);
	// print digit1
	_delay_ms(1);
	
	EN1(0);
	EN2(1);
	// print digit2
	_delay_ms(1);
	
	
}
