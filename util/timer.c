#include "timer.h"


//установщик задач
//=================================================================================================================================
void Timer_Task(int *Time)				
	{
	OFF_interrupt								//запрещаем прерывания
	
	int index = 0;
	
	for(char i=0; i<SIZE_ARRAY_HOURS; i++)		//пока не переберем всю очередь таймеров 
		{
		if(ArrayHours[i]==Time)					//если такая переменная уже есть в очереди
			{
			ON_interrupt						//разрешаем прерывания
			return;								//выходим
			}
		}
	
	while(index != SIZE_ARRAY_HOURS)			//перебираем очередь таймеров 
		{
		if(ArrayHours[index] == 0)				//если нашли пустую ячейку
			{
			ArrayHours[index] = Time;			//записываем туда указатель на переменную
			break;								//выходим
			}
		else									//если не нашли
			{
			index++;							//переходим на следующую ячейку
			}
		}
	ON_interrupt								//разрешаем прерывания	
	}
//====================================================================================================================================	




//диспетчер таймеров
//====================================================================================================================================
inline void Timer_ControlTimer(void)
	{
	TIMER_COUNTER = 0;						//сбрасываем значение счетчика аппаратного таймера

	int index=0;
		
	while(index != SIZE_ARRAY_HOURS)		//ищем таймеры которые до тикали 
		{
		if(ArrayHours[index]!=0)			//если ячейка не пустая
			{
			if(*ArrayHours[index]==0)		//если счетчик был сброшен
				{
				ArrayHours[index]=0;		//освобождаем ячейку
				}
			else
				{
				*ArrayHours[index]-=1;		//уменьшаем значение таймера на единицу
			
				if(*ArrayHours[index]==0)		//если счетчик до тикал
					{
					ArrayHours[index]=0;		//освобождаем ячейку
					}
				}
			}
		index++;							//переходим к следующему элементу 	
		}
	}
//==================================================================================================================================

	
