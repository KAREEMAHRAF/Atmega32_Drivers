/*
 * Timer_0.c
 *
 * Created: 10/11/2021 7:57:27 AM
 *  Author: kareem ashraf
 */ 


//TIMER 8 bit 2^8 =255 max number 0 to 255



//NORMAL MODE NO PRESCALER


#include "TIMER-0.h"

void TIMER_0_NORMAL_MODE_NO_PRESCALER_INIT()
{
	TCCR0 |= (1<<FOC0)| (1<<CS00);
	TIMSK |= (1<<TOIE0) ;
	sei();
}

//NORMAL MODE PRESCALER

void TIMER_0_NORMAL_MODE_PRESCALER_INIT(uint32_t PRESCALER )  // 8  64 256 1024 
{
	TCCR0 |= (1<<FOC0) ;
	TIMSK |= (1<<TOIE0);
	
	if (PRESCALER==8)
	{
		TCCR0 |= (1<<CS01);
	}
	else if (PRESCALER==64)
	{
		TCCR0 |= (1<<CS01) |(1<<CS00);
	}
	else if (PRESCALER==256)
	{
		TCCR0 |= (1<<CS02);
	}
	else if (PRESCALER==1024)
	{
		TCCR0 |= (1<<CS02) |(1<<CS00);
	}
	else
	{
		
	}
	sei();
}


//OUTCOMPARE MODE NO PRESCALER

void TIMER_0_CTC_MODE_NO_PRESCALER_INIT()
{
	OCR0 =255 ;
	TCCR0 |= (1<<FOC0)| (1<<CS00) | (1<<WGM01) ;
	TIMSK |= (1<<OCIE0) ;
	sei();
}

//OUTCOMPARE MODE PRESCALER

void TIMER_0_CTC_MODE_PRESCALER_INIT(uint32_t PRESCALER )  // 8  64 256 1024
{
	TCCR0 |= (1<<FOC0) | (1<<WGM01) ;
	TIMSK |= (1<<OCIE0);
	OCR0 =100 ;
	
	if (PRESCALER==8)
	{
		TCCR0 |= (1<<CS01);
	}
	else if (PRESCALER==64)
	{
		TCCR0 |= (1<<CS01) |(1<<CS00);
	}
	else if (PRESCALER==256)
	{
		TCCR0 |= (1<<CS02);
	}
	else if (PRESCALER==1024)
	{
		TCCR0 |= (1<<CS02) |(1<<CS00);
	}
	else
	{
		
	}
	sei();
}


//Fast frequancy

void TIMER_0_FASR_FRQUANSE_INIT(int frequance)
{
	OCR0 = frequance ;
	TCCR0 |= (1<<FOC0)| (1<<CS00) | (1<<WGM01)  | (1<<COM00) ;
	SETBIT(DDRB, 3);	
}



//PWM MODE

void TIMER_0_PWM_FAST_FRQUANSE_INIT(int DETY)
{
	OCR0 = DETY * 2.55 ;
	TCCR0 |= (1<<CS00) | (1<<WGM00) | (1<<WGM01)  | (1<<COM01) ;
	SETBIT(DDRB,3);
	
}

void TIMER_0_PWM_phase_correct_INIT(int DETY)
{
		OCR0 = DETY * 2.55 ;
		TCCR0 |= (1<<CS00) | (1<<WGM00)  | (1<<COM01) ;
		SETBIT(DDRB,3);
		
	
}