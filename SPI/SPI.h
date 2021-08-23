/*
 * SPI.h
 *
 * Created: 8/21/2020 12:36:00 PM
 *  Author: kareem ashraf
 */ 


#ifndef SPI_H_
#define SPI_H_
#include "std_macros.h"

void SPI_INIET_MASTER();
uint8_t SPI_SEND(uint8_t data);
void SPI_RECEVE();
void SPI_INIET_SLAVE();


#endif /* SPI_H_ */