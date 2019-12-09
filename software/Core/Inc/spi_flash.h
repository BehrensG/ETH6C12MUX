/*
 * spi_flash.h
 *
 *  Created on: Dec 2, 2019
 *      Author: grzegorz
 */

#ifndef INC_SPI_FLASH_H_
#define INC_SPI_FLASH_H_

#define SPI_FLASH_DEFAULT_STATUS 0x10

uint8_t * SPI_FLASH_GetManufacturerID(uint8_t id);
void SPI_FLASH_WriteByte(uint32_t address, uint8_t val, uint8_t id);
void SPI_FLASH_Read(uint32_t address, uint8_t* buffer, uint16_t len, uint8_t id);
void SPI_FLASH_EraseAll(uint8_t id);
uint8_t SPI_FLASH_IsProtected(uint8_t id);
uint8_t SPI_FLASH_DefaultStatus(uint8_t id);
void SPI_FLASH_BoardDefault(uint8_t force, uint8_t id);
void SPI_FLASH_BoardUpdate();

#endif /* INC_SPI_FLASH_H_ */
