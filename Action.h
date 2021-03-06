#ifndef Action_H
#define Action_H

#include "util/timer.h"
#include "util/drivers.h"
#include "main.h"

#define AMOUNT_MODE 4	//количество режимов

#define WAITING	0	//ожидание
#define ALONG	1	//движение вдоль стены
#define SPIRAL	2	//движение по спирали
#define MOWER	3	//"газонокосилка"

static char Mode;	//режим 

//утилиты
//================================================================================
extern void util_mode(char _mode);	//смена режима
//================================================================================



//общие переменные
static unsigned int way;			//пройденный путь
static unsigned int way_s;			//путь пройденный в прошлый раз
static char tumbling_flag;			//0-влево, 1-вправо


/*методы и свойства модуля
	* 			//метод модуля
	*_counter	//счетчик конечного автомата модуля
	*_time		//переменная-таймер модуля
*/	

//управление циклом работы
//================================================================================
extern void cycle();
static char cycle_counter;
static unsigned int cycle_time;
static char cycle_rep;
//================================================================================

//бампер
//================================================================================
extern	void bumper();
static char bumper_counter;
//================================================================================

//Управляющая кнопка
//================================================================================
extern  void button();	
static char button_flag;
static unsigned int button_time;
static char button_counter;
//================================================================================

//Привод
//================================================================================
extern  void drive();
static char drive_counter;	
static unsigned int drive_time;
static char drive_speed;
//================================================================================

//Мусорщик
//================================================================================
extern void cleaner();		
//================================================================================

//индикатор режима работы
//================================================================================
extern  void led();	
static unsigned int led_time;		
//================================================================================

#endif
