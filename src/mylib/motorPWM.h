/*
 * motorPWM.h
 *
 *  Created on: 5 Mar 2020
 *      Author: Cemal
 */


#ifndef MOTORPWM_H_
#define MOTORPWM_H_

void Set_Main_Motor( int accele_l, int accele_r )
{
	//int sw_data;

	//sw_data = dipsw_get() + 5;
/*	sw_data = 15 + 5;
	accele_l = accele_l * sw_data / 20;
	accele_r = accele_r * sw_data / 20;
*/
	/* Left Motor Control */
	if( accele_l >= 0 ) {
		PORT7.DR.BYTE &= 0xef;
		MTU4.TGRC = (long)( PWM_CYCLE - 1 ) * accele_l / 100;
	} else {
		PORT7.DR.BYTE |= 0x10;
		MTU4.TGRC = (long)( PWM_CYCLE - 1 ) * ( -accele_l ) / 100;
	}

	/* Right Motor Control */
	if( accele_r >= 0 ) {
		PORT7.DR.BYTE &= 0xdf;
		MTU4.TGRD = (long)( PWM_CYCLE - 1 ) * accele_r / 100;
	} else {
		PORT7.DR.BYTE |= 0x20;
		MTU4.TGRD = (long)( PWM_CYCLE - 1 ) * ( -accele_r ) / 100;
	}
}


#endif /* MOTORPWM_H_ */
