/*
 * DOG.c
 *
 * Created: 8/21/2020 2:19:41 PM
 *  Author: kareem ashraf
 */ 
#include "DOG.h"



void START_WATCH_DOG()
{
	WDTCR |= 1<<WDE | 1<<WDP2 | 1<<WDP1 | 1<<WDP0 ;	
}

void STOP_WATCH_DOG()
{
	WDTCR |= 1<<WDTOE | 1<<WDE;
	WDTCR = 0x00 ;
	
}