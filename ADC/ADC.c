/*
 * ADC.c
 *
 * Created: 10/22/2020 2:16:59 PM
 *  Author: kareem ashraf
 */ 

#include "KAREEM.h"
#include "std_macros.h"
void ADC_init()
{
	
	
	ADMUX |= 1<<REFS0 ;
	ADCSRA = 1<<ADEN | 1<<ADSC  | 1<<ADPS0| 1<<ADPS1 | 1<<ADPS2;
}

uint16_t ADC_READ(uint8_t ch)
{
	ADMUX = ADMUX & 0b11100000;
	
	ADMUX = ADMUX | ch ;
    
	ADCSRA |= 1<<ADSC ;
	
	while (READBIT(ADIF,4)==1){}
		
		//SETBIT(ADIF,4);
		return ADC ;
}