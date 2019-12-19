/*
 * relays.h
 *
 *  Created on: Dec 17, 2019
 *      Author: grzegorz
 */

#ifndef INC_MATRIX_H_
#define INC_MATRIX_H_

#include "stm32f7xx_hal.h"

#define MATRIX_SIZE 132
#define OPEN 0
#define CLOSE 1

#define MAIN 0
#define MODULE 1

struct _low_switch_t
{
	uint8_t cs;
	uint8_t pin;
	uint8_t spi;
};

typedef struct _low_switch_t low_switch_t;

struct _relay_t
{
	uint8_t status;
	low_switch_t MCZ33996;
	int8_t* id;
	uint8_t type;
};

typedef struct _relay_t relay_t;

struct _matrix_t
{
	relay_t relays[MATRIX_SIZE];
	uint8_t module_detected;
}matrix;


#endif /* INC_MATRIX_H_ */
