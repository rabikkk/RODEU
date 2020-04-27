/*
 * timers.h
 *
 *  Created on: 07 Eki 2018
 *      Author: FATIH
 */

#ifndef TIMERS_H_
#define TIMERS_H_

#include "../iodefine.h"
#include "misc.h"

typedef struct TIMER_TIMER {
	uint32_t Value;										// Reload value
	uint32_t Base;										// Base counter to compare
} TIMER_TIMER;

void Timers_Init(void);

void TIMER_Start(TIMER_TIMER *Timer, uint32_t Value);
unsigned char TIMER_Over(TIMER_TIMER *Timer);
void TIMER_Reset(TIMER_TIMER *Timer);
uint32_t millis(void);

void delayMs(uint32_t delayInMs);

#endif /* TIMERS_H_ */
