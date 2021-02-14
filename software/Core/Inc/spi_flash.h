/*
 * spi_flash.h
 *
 *  Created on: Dec 2, 2019
 *      Author: grzegorz
 */

#ifndef INC_SPI_FLASH_H_
#define INC_SPI_FLASH_H_

#include "types.h"

#define FLASH_READ 0x03
#define FLASH_HIGH_SPEED_READ 0x0b
#define FLASH_ERASE_4k 0x20
#define FLASH_ERASE_32k 0x52
#define FLASH_ERASE_64k 0xd8
#define FLASH_CHIP_ERASE 0x60
#define FLASH_BYTE_PGM 0x02
#define FLASH_AAI_PGM 0xad
#define FLASH_RDSR 0x05
#define FLASH_EWSR 0x50
#define FLASH_WRSR 0x01
#define FLASH_WREN 0x06
#define FLASH_WRDI 0x04
#define FLASH_RDID 0x9F
#define FLASH_EBSY 0x70
#define FLASH_DBSY 0x80

#define FLASH_BUSY (1<<0)
#define FLASH_WEL (1<<1)
#define FLASH_BP0 (1<<2)
#define FLASH_BP1 (1<<3)
#define FLASH_BP2 (1<<4)
#define FLASH_BP3 (1<<5)
#define FLASH_AAI (1<<6)
#define FLASH_BPL (1<<7)

#define SPI_FLASH_DEFAULT_STATUS 0x10

uint8_t * SPI_FLASH_GetManufacturerID(uint8_t id);
void SPI_FLASH_WriteByte(uint32_t address, uint8_t val, uint8_t id);
void SPI_FLASH_Read(uint32_t address, uint8_t* buffer, uint16_t len, uint8_t id);
void SPI_FLASH_EraseAll(uint8_t id);
uint8_t SPI_FLASH_IsProtected(uint8_t id);
uint8_t SPI_FLASH_DefaultStatus(uint8_t id);
void SPI_FLASH_BoardDefault(uint8_t force);
void SPI_FLASH_BoardUpdate();

#endif /* INC_SPI_FLASH_H_ */
