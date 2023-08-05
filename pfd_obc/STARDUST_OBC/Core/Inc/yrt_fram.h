// author: dogu
#ifndef _ADAFRUIT_FRAM_I2C_H_
#define _ADAFRUIT_FRAM_I2C_H_

#include "main.h"
#include "stdint.h"

#define MB85RC_DEFAULT_ADDRESS \
    (0x50)  ///<* 1010 + A2 + A1 + A0 = 0x50 default */
#define MB85RC_SECONDARY_ADDRESS \
    (0x7C)  ///< secondary ID for manufacture id info

uint8_t fram_init();

uint8_t fram_read8(uint16_t framAddr);
uint16_t fram_read16(uint16_t framAddr);
float fram_readFloat(uint16_t framAddr);
uint8_t fram_read(uint16_t framAddr, uint8_t *value, uint8_t n);

uint8_t fram_write8(uint16_t framAddr, uint8_t value);
uint8_t fram_write16(uint16_t framAddr, uint16_t value);
float fram_writeFloat(uint16_t framAddr, uint32_t value);
uint8_t fram_write(uint16_t framAddr, uint8_t *value, uint8_t n);





#endif