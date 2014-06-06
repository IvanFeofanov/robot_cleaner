#include "drivers.h"


//Приводные двигатели
//================================================================================
void M_drive(signed char l_vector, char l_speed, signed char r_vector, char r_speed)
	{
	//правый мотор
	switch(r_vector)
		{
		case -1:
		PORTC &= ~(1<<0);	/*down*/
		PORTC |= (1<<1);
		break;
		
		case 0:
		PORTC &= ~(1<<0);	/*stop*/
		PORTC &= ~(1<<1);
		break;
		
		case 1:
		PORTC |= (1<<0);	/*up*/
		PORTC &= ~(1<<1);
		break;
		}
	
	//левый мотор
	switch(l_vector)
		{
		case -1:
		PORTC &= ~(1<<2);	/*down*/
		PORTC |= (1<<3);
		break;
		
		case 0:
		PORTC &= ~(1<<2);	/*stop*/
		PORTC &= ~(1<<3);
		break;
		
		case 1:
		PORTC |= (1<<2);	/*up*/
		PORTC &= ~(1<<3);
		break;
		}
		
	//устанавливаем скорость
	OCR1A=(10-r_speed)*25;
	OCR1B=(10-l_speed)*25; 
	}
//================================================================================


