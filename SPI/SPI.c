/*
 * SPI.c
 *
 * Created: 8/21/2020 12:35:45 PM
 *  Author: kareem ashraf
 */ 
#include "SPI.h"

void SPI_INIET_MASTER()
{
	SPCR |= 1<<SPE | 1<<MSTR ;	
}
void SPI_INIET_SLAVE()
{
	SPCR |= 1<<SPE;	
}
uint8_t SPI_SEND(uint8_t data)
{
	SPSR = data ;
	while(READBIT(SPSR,SPIF)==0);
}
void SPI_RECEVE()
{
	while(READBIT(SPSR,SPIF)==0);
	return SPSR ;	
}
