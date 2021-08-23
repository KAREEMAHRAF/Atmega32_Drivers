/*
 * I2C.h
 *
 * Created: 8/24/2020 10:11:18 PM
 *  Author: kareem ashraf
 */ 


#ifndef I2C_H_
#define I2C_H_

#include "std_macros.h"


void I2C_master_init(void);
void I2C_master_start();
void I2C_master_addr(uint8_t addr);
void I2C_master_write(uint8_t data);
void I2C_master_stop(void);

// Slave
void I2C_slave_Init(uint8_t My_Add);
uint8_t I2C_slave_avialable();
uint8_t I2C_slave_read(void);



#endif /* I2C_H_ */