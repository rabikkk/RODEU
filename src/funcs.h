/*
 * funcs.h
 *
 *  Created on: 04 Şub 2019
 *      Author: FATIH
 */

#ifndef FUNCS_H_
#define FUNCS_H_

#include "iodefine.h"
#include "mylib/timers.h"
#include "mylib/misc.h"

typedef enum PID_E{
	P = 0,
	I,
	D
}PID_E;

typedef enum DIR{
	NoDir = 0,
	Right,
	Left
}DIR;

typedef enum MODES{
	ModeLast = 0,
	Mode450
}MODES;

/* Constant settings */
#define PWM_CYCLE      409// 24575           /* Motor PWM period (16ms)     */
//#define SERVO_CENTER    2520            /* Servo center value          (Azalttıkça  sağa çeker.)*/
#define SERVO_CENTER    2480            /* Servo center value     yeni araç     */
#define HANDLE_STEP     13              /* 1 degree value              */
#define DESIRED_LOCATION 45 //45 olmalı sakarya için 40 yapıldı

void System_Init(void);
void led_out( unsigned char led );
void Set_Servo_Angle( int angle );
void Set_Main_Motor( int accele_l, int accele_r );
unsigned int  Sensor_Read(void);
void Check_CrossLine(void);
void Check_eightbits(void);
void Check_oval(void);

#endif /* FUNCS_H_ */
