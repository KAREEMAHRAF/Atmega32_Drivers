/*
 * KEYBAD.c
 *
 * Created: 12/12/2020 7:59:49 PM
 *  Author: kareem ashraf
 */ 
#include "KEYBAD.h"

void KEYBAD_INIT()
{
	DDRC = 0x0f; PORTC = 0xf0;
	//PORTC |=0b11110000;
	DDRC  |=0b00001111;
}

const uint8_t matrex[] = {15  ,  14  ,  13  ,  12,
	                      10  ,  9  ,  6  ,  3,
					      0  ,  8  ,  5  ,  2,
						 11  ,  7   , 4   ,  1 };
				  
uint16_t KEYBAD_WRITE()
{
	
	CLE_BIT(PORTC,0);
	SET_BIT(PORTC,1);
	SET_BIT(PORTC,2);
	SET_BIT(PORTC,3);

	
	if (READ_BIT(PINC,4)==0)
	{
		return matrex[0+4*0];
	}
	if (READ_BIT(PINC,5)==0)
	{
		return matrex[1];
	}
	if (READ_BIT(PINC,6)==0)
	{
		return matrex[2];
	}
	if (READ_BIT(PINC,7)==0)
	{
		return matrex[3];
	}
            
			
	_delay_ms(1);

	
	SET_BIT(PORTC,0);
	CLE_BIT(PORTC,1);
	SET_BIT(PORTC,2);
	SET_BIT(PORTC,3);

	
	if (READ_BIT(PINC,4)==0)
	{
		return matrex[0+4*1];
	}
    if (READ_BIT(PINC,5)==0)
	{
		return matrex[5];
	}
	if (READ_BIT(PINC,6)==0)
	{
		return matrex[6];
	}
	if (READ_BIT(PINC,7)==0)
	{
		return matrex[7] ;
	}
	        
		_delay_ms(1);	
	
	SET_BIT(PORTC,0);
	SET_BIT(PORTC,1);
	CLE_BIT(PORTC,2);
	SET_BIT(PORTC,3);

	
	if (READ_BIT(PINC,4)==0)
	{
		return matrex[0+4*2];
	}
	if (READ_BIT(PINC,5)==0)
	{
		return matrex[9];
	}
	if (READ_BIT(PINC,6)==0)
	{
		return matrex[10];
	}
	if (READ_BIT(PINC,7)==0)
	{
		return matrex[11];
	}
	         
		_delay_ms(1);	 
	
	
	SET_BIT(PORTC,0);
	SET_BIT(PORTC,1);
	SET_BIT(PORTC,2);
	CLE_BIT(PORTC,3);

	
	if (READ_BIT(PINC,4)==0)
	{
		return matrex[0+4*3];
	}
	if (READ_BIT(PINC,5)==0)
	{
		return matrex[13];
	}
	if (READ_BIT(PINC,6)==0)
	{
		return matrex[14];
	}
	if (READ_BIT(PINC,7)==0)
	{
		return matrex[15];
	}
	    _delay_ms(1);  
		
		
		return 0;  
	
}