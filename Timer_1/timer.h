

#ifndef TIMER_H_
#define TIMER_H_
#include "std_macros.h"
#include "std_macros.h"


void TIMER_1_NORMAL_MODE_NO_PRESCALER_INIT();
void TIMER_1_NORMAL_MODE_PRESCALER_INIT(uint32_t PRESCALER );
void TIMER_1_CTC_MODE_NO_PRESCALER_INIT();
void TIMER_1_CTC_MODE_PRESCALER_INIT(uint32_t PRESCALER );
void TIMER_1_FASR_FRQUANSE_INIT();
void TIMER_1_PWM_FAST_FRQUANSE_INIT(int);
void TIMER_1_PWM_phase_correct_INIT(int);
int TIMER_1_INPUT_CAPURE_INIT();
#endif /* TIMER_H_ */