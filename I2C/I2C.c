/*
 * I2C.c
 *
 * Created: 8/24/2020 10:10:38 PM
 *  Author: kareem ashraf
 */ 

#include "I2C.h"
void I2C_master_init()
{
	TWBR =   12 ;
	
}
void I2C_master_start()
{
	TWCR |= (1<<TWSTA) | (1<<TWINT) | (1<<TWEN);
	while(READBIT(TWCR,TWINT)==0);	
}
void I2C_master_addr(uint8_t addr)
{
	   TWDR = addr<<1 ;
	   TWCR |=(1<<TWINT) | (1<<TWEN);
	   while(READBIT(TWCR,TWEA)==0);	
}
void I2C_master_write(uint8_t data)
{
	TWDR = data ;
	TWCR |=(1<<TWINT) | (1<<TWEN);   
    while(READBIT(TWCR,TWEA)==1);
}
void I2C_master_stop(void)
{
	 TWCR |= (1<<TWSTO) | (1<<TWEN);
}

// Slave
void I2C_slave_Init(uint8_t My_Add)
{
	TWAR = My_Add << 1 ;
	
}
uint8_t I2C_slave_avialable()
{
	
		 TWCR |= (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
		  while(READBIT(TWCR,TWINT)==0);
		  if (TWSR = 0x60)
		  {
			  return 1 ;
		  }
		  else
		  return 0 ;
}
uint8_t I2C_slave_read(void)
{
	 TWCR |= (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	  while(READBIT(TWCR,TWINT)==0);
	  return TWDR ;
	
}