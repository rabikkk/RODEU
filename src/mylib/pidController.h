/*
 * pidController.h
 *
 *  Created on: 5 Mar 2020
 *      Author: Cemal
 */

#ifndef PIDCONTROLLER_H_
#define PIDCONTROLLER_H_
#include "variables.h"
#include "motorPWM.h"
#include "sensorRead.h"
volatile int L_PWM = 0, R_PWM = 0, Angle = 0, Angle_Perp = 0;
volatile unsigned int 	sensor_data = 0;
// Differential PID
float const PID_Coefs_DIFF[3] = { 0.4, 0, 5 };//7,1,5
float p_DIFF = 0, i_DIFF = 0, d_DIFF = 0, t_DIFF = 0;
// PID Error variables
volatile long error = 0, error_lst = 0, error_dif = 0;
void pidController() {
	sensor_data = Sensor_Read();

	//=============Virajlarda yavaÅŸlama=============//
	if (!GET_BIT(sensor_port_data, 7) || !GET_BIT(sensor_port_data, 6)
			|| !GET_BIT(sensor_port_data, 5) || !GET_BIT(sensor_port_data, 2)
			|| !GET_BIT(sensor_port_data, 1) || !GET_BIT(sensor_port_data, 0)) {
		if (CURRENT_SPEED != PERP_SPEED) {
			CURRENT_SPEED = CURVE_SPEED;
		}

	} else {
		if (CURRENT_SPEED != PERP_SPEED) {
			CURRENT_SPEED = SPEED;
		}
	}
	//=============Virajlarda yavaÅŸlama=============//
	error = sensor_data - DESIRED_LOCATION;
	error_dif = error - error_lst;
	error_lst = error;

	p_DIFF = PID_Coefs_DIFF[P] * error;
	i_DIFF = i_DIFF + (PID_Coefs_DIFF[I] * error_dif);
	d_DIFF = PID_Coefs_DIFF[D] * error_dif;

	t_DIFF = p_DIFF + i_DIFF + d_DIFF;

	if ((CURRENT_SPEED + (int) t_DIFF) > 100) {
		i_DIFF = 0;
	}

	if ((CURRENT_SPEED + (int) t_DIFF) < -100) {
		i_DIFF = 0;
	}

	L_PWM = CURRENT_SPEED + (int) t_DIFF;
	R_PWM = CURRENT_SPEED - (int) t_DIFF;

	if (L_PWM < -100)
		L_PWM = -100;
	if (L_PWM > 100)
		L_PWM = 100;

	if (R_PWM < -100)
		R_PWM = -100;
	if (R_PWM > 100)
		R_PWM = 100;

	if (error == 0) {
		Set_Main_Motor(CURRENT_SPEED, CURRENT_SPEED);
		i_DIFF = 0;
	} else {
		Set_Main_Motor(L_PWM, R_PWM);
	}
}
#endif /* PIDCONTROLLER_H_ */
