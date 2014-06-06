#include "main.h"
#include <util/delay.h>

//прерывание: Таймер-счетчик-2
ISR(TIMER_ISR)
	{
	Timer_ControlTimer();	//служба таймеров 
	}

	

int main(void)
	{
	Periphery();			//настройка периферии 

	//главный цикл программы 
	while(1)
		{
 		button();
		cycle();
		drive();
		cleaner();
		bumper(); 
		led();
		}
	}
