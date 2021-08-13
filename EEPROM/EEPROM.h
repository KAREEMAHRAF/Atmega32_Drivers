/*
 * EEPROM.h
 *
 * Created: 7/16/2020 8:42:33 PM
 *  Author: safifi
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_


#include "std_macros.h"

uint8_t eeprom_read (uint16_t  address);
void eeprom_write (uint16_t  address, uint8_t data);


#endif /* EEPROM_H_ */