/*! \file bmi088_stm32.h
 \STM32 specific SPI functions */

/*********************************************************************/
/* header files */
#include "bmi08x_defs.h"

int8_t stm32_i2c_write(uint8_t i2c_addr, uint8_t reg_addr, uint8_t *data, uint16_t len);

int8_t stm32_i2c_read(uint8_t i2c_addr, uint8_t reg_addr, uint8_t *data, uint16_t len);

