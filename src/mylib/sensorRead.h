/*
 * sensorRead.h
 *
 *  Created on: 5 Mar 2020
 *      Author: Cemal
 */

#ifndef SENSORREAD_H_
#define SENSORREAD_H_
#include "variables.h"
unsigned int Sensor_Read(void)
{
	unsigned int i = 0;
	unsigned int  location = 0;
	static unsigned int  location_last = DESIRED_LOCATION;

	sum=0;
	count=0;
	sensor_port_data = 0;
	sensor_port_data = PORT4.PORT.BYTE;
	for (i = 0; i < 8; i++) {
		if(!GET_BIT(sensor_port_data, 7-i) == TRUE){	// i = 0 --> en sol sensor, i = 7 --> en saÄŸ orta sensor.
			sum += ((i+1)*10);
			count++;
		}
	}


	if (count) {
		location = sum/count;
	}else {

	}
   if ((!GET_BIT(sensor_port_data, 7) && !GET_BIT(sensor_port_data, 6) && !GET_BIT(sensor_port_data, 0)) ||
	   (!GET_BIT(sensor_port_data, 0) && !GET_BIT(sensor_port_data, 1) && !GET_BIT(sensor_port_data, 7)) ||
	   (!GET_BIT(sensor_port_data, 0) && !GET_BIT(sensor_port_data, 1) && !GET_BIT(sensor_port_data, 6) && !GET_BIT(sensor_port_data, 7)) ||
	   (!GET_BIT(sensor_port_data, 7) && !GET_BIT(sensor_port_data, 6)) ||
	   (!GET_BIT(sensor_port_data, 0) && !GET_BIT(sensor_port_data, 1)) ||
	   (!GET_BIT(sensor_port_data, 7) && !GET_BIT(sensor_port_data, 0))) {
	   location=location_last;
   }
   location_last = location;
   return location;
}
#endif /* SENSORREAD_H_ */
