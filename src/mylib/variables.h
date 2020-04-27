/*
 * variables.h
 *
 *  Created on: 5 Mar 2020
 *      Author: Cemal
 */

#ifndef VARIABLES_H_
#define VARIABLES_H_

#define  SPEED 	80
int RB = 0;
int counter = 0;//Sayaç kontrolü switch case kontrolü
int count1 = 0;//Counterin maske countu :)
int CURVE_SPEED = SPEED * 0.70;
int PERP_SPEED = SPEED * 0.30;
DIR fPERP = NoDir;
int temp1;//Switch case konrolüne tekrar girmemesi için
unsigned short fLeftCross = 0;
int CURRENT_SPEED = SPEED;
unsigned char sensor_port_data_temp = 0;//sensör bilgilerinin kopyalandığı yer

unsigned char mz80sensor=0;
unsigned long sum=0, count=0;
unsigned char sensor_port_data = 0;//sensör bilgilerinin yazıldığı yer
unsigned char  mz80sensor_temp=0;
#endif /* VARIABLES_H_ */
