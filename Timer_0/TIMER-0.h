/*
 * TIMER_0.h
 *
 * Created: 10/11/2021 7:58:13 AM
 *  Author: kareem ashraf
 */ 


#ifndef TIMER-0_H_
#define TIMER-0_H_
#include "std_macros.h"


void TIMER_0_NORMAL_MODE_NO_PRESCALER_INIT();
void TIMER_0_NORMAL_MODE_PRESCALER_INIT(uint32_t PRESCALER );
void TIMER_0_CTC_MODE_NO_PRESCALER_INIT();
void TIMER_0_CTC_MODE_PRESCALER_INIT(uint32_t PRESCALER );
void TIMER_0_FASR_FRQUANSE_INIT(int frequance);
void TIMER_0_PWM_FAST_FRQUANSE_INIT(int DETY);
void TIMER_0_PWM_phase_correct_INIT(int DETY);

#endif /* TIMER-0_H_ */