/***********************************************************************/
/*  File:                  LineFollower_v1_0.c                         */
/*  File Contents:         Line Follower Program				       */
/*  Version number:        Ver.1.00                                    */
/*  Date:                  06.10.2018                                  */
/*  Author:                Fatih CEKEN						 	       */
/***********************************************************************/
/*   Allâhü lâ ilâhe illâ hüvel hayyül kayyûm, lâ te'huzühu sinetün velâ nevm,
 lehu mâ fissemâvâti ve ma fil'ard, men zellezi yeşfeu indehu illâ bi'iznih,
 ya,
 velâ yü-hîtûne bi'şey'im min ilmihî illâ bima şâe vesia kürsiyyühüssemâvâti vel'ard,
 velâ yeûdühû hıfzuhümâ ve hüvel aliyyül azim.
 */
/*======================================*/
/* Include                              */
/*======================================*/
#include "iodefine.h"
#include "mylib/timers.h"
#include "mylib/misc.h"
#include "funcs.h"
#include "mylib/sensorRead.h"
#include "mylib/motorPWM.h"
#include "mylib/variables.h"
#include "mylib/pidController.h"
TIMER_TIMER PERP_Timer;
TIMER_TIMER TUR;
/*======================================*/
/* Prototype declarations               */
/*======================================*/

/*======================================*/
/* Main program                         */
/*======================================*/

int mask() {//sayac artırımın oldugu fonksiyondur.
	mz80sensor = !(PORTB.PORT.BIT.B7);
	mz80sensor_temp = !(PORTB.PORT.BIT.B7);
	while (mz80sensor_temp == 1) {
		mz80sensor = !(PORTB.PORT.BIT.B7);
		if (sensor_port_data_temp != sensor_port_data) {
			counter++;
		}
	}


	return counter;
}

void main(void) {

	System_Init();
	Set_Main_Motor(CURRENT_SPEED, CURRENT_SPEED);
	while (1) {
		while ((!(PORTB.PORT.BIT.B7))) // mesafe sensorunden gelen bilgiye göre araç durduruluyor

		{
			Set_Main_Motor(0, 0);
		}

		pidController();

	}
}

//HELLO
