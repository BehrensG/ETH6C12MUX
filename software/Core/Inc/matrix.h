/*
 * relays.h
 *
 *  Created on: Dec 17, 2019
 *      Author: grzegorz
 */

#ifndef INC_MATRIX_H_
#define INC_MATRIX_H_

#include "stm32f7xx_hal.h"
#include "types.h"

#define MATRIX_SIZE 132
#define OPEN 0
#define CLOSE 1

#define MAIN 0
#define MODULE 1

#define SPI_CMD_SIZE 10

#define MAXROW 133
#define MAXCOL 1
#define MAXDIM 1

#define CS0 0
#define CS1 1
#define CS2 2
#define CS3 3
#define CS4 4
#define CS5 5
#define CS6 6
#define CS7 7
#define CS8 8
#define CS9 9

#define SPI4_ID 4
#define SPI5_ID 5
#define MODULE_RELAY_INDEX 66

struct _spi_command_t
{
    uint8_t tx_data[3];
    uint16_t tx_tmp;
    uint8_t cs;
    uint8_t spi;
    uint8_t enabled;
};

typedef struct _spi_command_t spi_command_t;

struct _low_switch_t
{
	uint8_t cs;
	uint8_t out;
	uint8_t spi;
};

typedef struct _low_switch_t low_switch_t;

struct _relay_t
{
	uint8_t state;
	low_switch_t MCZ33996;
	char* id;
	uint8_t type;
	uint8_t index;

};

typedef struct _relay_t relay_t;

struct _matrix_t
{
	relay_t relays[MATRIX_SIZE];
	uint8_t module_detected;
    spi_command_t spi_commands[SPI_CMD_SIZE];
}matrix;

void MATRIX_InitMain();
void MATRIX_ResetSPICommands();

#endif /* INC_MATRIX_H_ */
