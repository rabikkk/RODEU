/*
 * timers.c
 *
 *  Created on: 07 Eki 2018
 *      Author: FATIH
 */

#include "timers.h"

volatile uint32_t mSec_Counter = 0;
volatile uint32_t US;
TIMER_TIMER TIMER_Timer;

/* CMT0 Interrupt Handler
 * CMT0 interrupt happens on every 1 ms
 */
#pragma interrupt Excep_CMT0_CMI0(vect=28)
void Excep_CMT0_CMI0(void)
{
	mSec_Counter++;
}

/* CMT0 Timer Initializer
 * CMT0 defined in timers.h to interrupt on every 1 ms
 */
void Timers_Init(void){

}

void TIMER_Start(TIMER_TIMER *Timer, uint32_t Value)
{
	Timer->Value = Value;
	Timer->Base = mSec_Counter;
}

void TIMER_Reset(TIMER_TIMER *Timer)
{
	Timer->Value = 0;
	Timer->Base = 0;
}

unsigned char TIMER_Over(TIMER_TIMER *Timer)
{
	if (Timer->Value > 0){
		while (Timer->Base != mSec_Counter){
			if (Timer->Value-- == 0) return 1;
			Timer->Base++;
		}
		return 0;
	} else return 1;
}

/*	delayMs */
void delayMs(uint32_t delayInMs)
{
	TIMER_Start(&TIMER_Timer, delayInMs);
	while (!TIMER_Over(&TIMER_Timer));

	return;
}

uint32_t millis(void)
{
	return mSec_Counter;
}
