/*
 * TIMER_1.c
 *
 * Created: 10/11/2021 12:07:35 PM
 *  Author: kareem ashraf
 */ 


#include "timer.h"

void TIMER_1_NORMAL_MODE_NO_PRESCALER_INIT()
{
	TCCR1B |=  (1<<CS10) ;
	TIMSK  |= (1<<TOIE1) ;
	
	sei();
}

void TIMER_1_NORMAL_MODE_PRESCALER_INIT(uint32_t PRESCALER )
{
	TIMSK  |= (1<<TOIE1) ;
	
	if (PRESCALER==8)
	{
		TCCR1B |= (1<<CS11);
	}
	else if (PRESCALER==64)
	{
		TCCR1B |= (1<<CS11) |(1<<CS10);
	}
	else if (PRESCALER==256)
	{
		TCCR1B |= (1<<CS12);
	}
	else if (PRESCALER==1024)
	{
		TCCR1B |= (1<<CS12) |(1<<CS10);
	}
	else
	{
		
	}
	sei();
}






void TIMER_1_CTC_MODE_NO_PRESCALER_INIT()
{
	OCR1A = 16384 ;
	TCCR1B |= (1<<CS10);
	TCCR1B |= (1<<WGM12) ;   //CTC  -->ocsA
	TIMSK  |= (1<<OCIE1A) ;  // INTERRUPT  
	sei();
	
}


void TIMER_1_CTC_MODE_PRESCALER_INIT(uint32_t PRESCALER )
{
	
	
	
	if (PRESCALER==8)
	{
		TCCR1B |= (1<<CS11);
	}
	else if (PRESCALER==64)
	{
		TCCR1B |= (1<<CS11) |(1<<CS10);
	}
	else if (PRESCALER==256)
	{
		TCCR1B |= (1<<CS12);
	}
	else if (PRESCALER==1024)
	{
		TCCR1B |= (1<<CS12) |(1<<CS10);
	}
	else
	{
		TCCR1B |= (1<<CS10);
		
	}
	OCR1A = 65535 ;
	TCCR1B |= (1<<WGM12) ;   //CTC  -->ocsA
	TIMSK  |= (1<<OCIE1A) ;  // INTERRUPT
	sei();
	
}

void TIMER_1_FASR_FRQUANSE_INIT()
{
	OCR1A   = 65536 ;
	SETBIT(DDRD,5);
	TCCR1A |= (1<<COM1A0) ;  //toggel 
	TCCR1B |= (1<<WGM12) ;   //CTC  -->ocsA
	TCCR1B |= (1<<CS10);     //NO Prescaler
	TIMSK  |= (1<<OCIE1A) ;  // INTERRUPT
	
	
	
}


void TIMER_1_PWM_FAST_FRQUANSE_INIT(int dety)
{

TCCR1A |= (1<<COM1A1) | (1<<WGM11) | (1<<WGM10);
TCCR1B |= (1<<CS10) | (1<<WGM12);
SETBIT(DDRD, 5);
OCR1A = dety*10.23;
}

void TIMER_1_PWM_phase_correct_INIT(int dety)
{

	TCCR1A |= (1<<COM1A1) | (1<<WGM11) | (1<<WGM10);
	TCCR1B |= (1<<CS10) ;
	SETBIT(DDRD, 5);
	OCR1A = dety*10.23;
}


int TIMER_1_INPUT_CAPURE_INIT()
{
	int t1 , t2 ;
	TCCR1A |= (1<<WGM11); // PIN ICR1 
	TCCR1B |= (1<<WGM13) | (1<<CS10) | (1<<ICES1) ;    // PIN ICR1  //NO PRESCLER // Rising edge

	TIFR   |= ICF1 ;       //Enabel clear Flag
	while(READBIT(TCCR1B,ICF1)==0){} //INPUT CUPTER REGISTER
		t1 = ICR1 ;
		
		
	TIFR   |= ICF1 ;    //Enabel clear Flag
	while(READBIT(TCCR1B,ICF1)==0){} //INPUT CUPTER REGISTER 
		t2 = ICR1 - t1 ;   //MICROSECOND  * 1000 000 =second
		                   //period = 1/F_CPU 
						   //t2/F_CPU
		
		return t2 ;

}