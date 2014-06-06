#ifndef TIMER_H
#define TIMER_H

#include <avr/io.h>
#include <avr/interrupt.h>


#define SIZE_ARRAY_HOURS			10					//размер массива таймеров
#define TIMER_ISR					TIMER2_COMP_vect	//выбор таймера для аппаратного тика
#define TIMER_COUNTER				TCNT2				//регистр-счетчик таймера 


#define ON_interrupt			sei();		//включить прерывания
#define OFF_interrupt			cli();		//выключить прерывания

volatile static int *ArrayHours[SIZE_ARRAY_HOURS];	//массив таймеров


//прототипы функций
extern void Timer_ControlTimer(void);				//служба таймеров
extern void Timer_Task(int *Time);					//установка задач в очередь таймеров

#endif
