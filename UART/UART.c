/*
 * UART.c
 *
 * Created: 8/11/2020 2:47:44 PM
 *  Author: kareem ashraf
 */ 
#include "UART.h"

void UART_INIT()
{
	 UBRRL = 103 ;
	 UCSRB = (1<<RXEN) | (1<<TXEN) ;
	 UCSRC = (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0) ;
}

void UART_WRITE(uint8_t data)
{
	UDR = data ;
	while(READBIT(UCSRA,TXC)==0);
	SETBIT(UCSRA,TXC);
}

void UART_READ()
{
	while(READBIT(UCSRA,RXC)==0);
	return UDR ;
}
