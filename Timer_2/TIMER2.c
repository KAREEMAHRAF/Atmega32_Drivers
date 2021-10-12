/*
 * TIMER2.c
 *
 * Created: 10/11/2021 6:01:25 PM
 *  Author: kareem ashraf
 */ 

#include "TIMER2.h"

void TIMER_2_NORMAL_MODE_NO_PRESCALER_INIT()
{
	TCCR2 |= (1<<FOC2) | (1<<CS20);
	TIMSK |= (1<<TOIE2);
	sei();
	
}
void TIMER_2_NORMAL_MODE_PRESCALER_INIT(uint32_t PRESCALER )
{
	
	TCCR2 |= (1<<FOC2) ;
	TIMSK |= (1<<TOIE2);
	
	if (PRESCALER==8)
	{
		TCCR2 |= (1<<CS21);
	}
	else if (PRESCALER==64)
	{
		TCCR2 |= (1<<CS22) ;
	}
	else if (PRESCALER==256)
	{
		TCCR2 |= (1<<CS22) | (1<<CS21);
	}
	else if (PRESCALER==1024)
	{
		TCCR2 |= (1<<CS22) |(1<<CS21) |(1<<CS20) ;
	}
	else
	{
		
	}
	sei();

}
void TIMER_2_CTC_MODE_NO_PRESCALER_INIT()
{
	TCCR2 |= (1<<FOC2) |(1<<WGM21) | (1<<COM21) | (1<<CS20) ;
	OCR2 = 250 ;
	TIMSK |= (1<<OCIE2) ;
	sei();
		
}
void TIMER_2_CTC_MODE_PRESCALER_INIT(uint32_t PRESCALER )
{
		TCCR2 |= (1<<FOC2)|(1<<WGM21) | (1<<COM21) ;
		TIMSK |= (1<<OCIE2);
		OCR2 = 250 ;
		if (PRESCALER==8)
		{
			TCCR2 |= (1<<CS21);
		}
		else if (PRESCALER==64)
		{
			TCCR2 |= (1<<CS22) ;
		}
		else if (PRESCALER==256)
		{
			TCCR2 |= (1<<CS22) | (1<<CS21);
		}
		else if (PRESCALER==1024)
		{
			TCCR2 |= (1<<CS22) |(1<<CS21) |(1<<CS20) ;
		}
		else
		{
			
		}
		sei();
	
}
//void TIMER_2_FASR_FRQUANSE_INIT(int frequance);
void TIMER_2_PWM_FAST_FRQUANSE_INIT(int dety)
{
	TCCR2 |= (1<<WGM21)|(1<<WGM20) |(1<<CS20) | (1<<COM21)  ;
	
	SETBIT(DDRD,7);
	OCR2 = dety * 2.55 ;
}
//void TIMER_2_PWM_phase_correct_INIT(int dety);