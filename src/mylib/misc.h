/*
 * misc.h
 *
 *  Created on: 07 Eki 2018
 *      Author: FATIH
 */
/*RABİA*/
#ifndef MISC_H_
#define MISC_H_

typedef unsigned int uint32_t;
typedef unsigned char uint8_t;

#define TRUE		(1)
#define FALSE		(0)


#define GET_BIT(n,k)	((n>>k) & 0x01)

#define SET_BIT(n,k) ((n) |= (1 << (k)))
#define CLR_BIT(n,k) ((n) &= (~(1) << (k)))

#endif /* MISC_H_ */
