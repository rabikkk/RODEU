/*
 * readBit.h
 *
 *  Created on: 5 Mar 2020
 *      Author: Cemal
 */

#ifndef READBIT_H_
#define READBIT_H_
int Read_bit()
{	RB=0;
	sensor_port_data=0;
	sensor_port_data = PORT4.PORT.BYTE;
	if(!(GET_BIT(sensor_port_data, 7)))RB++;
	if(!(GET_BIT(sensor_port_data, 6)))RB++;
	if(!(GET_BIT(sensor_port_data, 5)))RB++;
	if(!(GET_BIT(sensor_port_data, 4)))RB++;
	if(!(GET_BIT(sensor_port_data, 3)))RB++;
	if(!(GET_BIT(sensor_port_data, 2)))RB++;
	if(!(GET_BIT(sensor_port_data, 1)))RB++;
	if(!(GET_BIT(sensor_port_data, 0)))RB++;
return RB;
}

#endif /* READBIT_H_ */
