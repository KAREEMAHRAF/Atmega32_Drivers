/*
 * UART.h
 *
 * Created: 8/11/2020 2:47:58 PM
 *  Author: kareem ashraf
 */ 


#ifndef UART_H_
#define UART_H_
#include "std_macros.h"


void UART_INIT();
void UART_WRITE(uint8_t data);
void UART_READ();


#endif /* UART_H_ */