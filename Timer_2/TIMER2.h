/*
 * TIMER2.h
 *
 * Created: 10/11/2021 6:01:09 PM
 *  Author: kareem ashraf
 */ 


#ifndef TIMER2_H_
#define TIMER2_H_


#include "std_macros.h"
#include "Register-Config.h"


void TIMER_2_NORMAL_MODE_NO_PRESCALER_INIT();
void TIMER_2_NORMAL_MODE_PRESCALER_INIT(uint32_t PRESCALER );


void TIMER_2_CTC_MODE_NO_PRESCALER_INIT();
void TIMER_2_CTC_MODE_PRESCALER_INIT(uint32_t PRESCALER );


void TIMER_2_FASR_FRQUANSE_INIT(int frequance);


void TIMER_2_PWM_FAST_FRQUANSE_INIT(int );



#endif /* TIMER2_H_ */