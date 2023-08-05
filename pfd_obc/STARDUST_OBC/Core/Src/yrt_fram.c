// author: dogu
#include "yrt_fram.h"

// i2c fram mb85rc256v 32kbyte
extern I2C_HandleTypeDef hi2c2;
#define FRAM_I2C &hi2c2

#define FRAM_ADDRESS_READ 0xA1
#define FRAM_ADDRESS_WRITE 0xA0

typedef union {
    float u32;
    uint8_t u8[4];
} fram_float_to_u8;

static uint8_t ms5611_i2c_write_byte(uint16_t reg, uint8_t data){
    HAL_StatusTypeDef res;
    res = HAL_I2C_Mem_Write(FRAM_I2C, FRAM_ADDRESS_WRITE, reg, I2C_MEMADD_SIZE_16BIT,
                     &data, 1, 100);

    // return data if success
    if (res == HAL_OK) {
        return data;
    } else {
        return 0;
    }
}

static uint8_t ms5611_i2c_read_byte(uint16_t reg, uint8_t *data){
    HAL_StatusTypeDef res;
    res = HAL_I2C_Mem_Read(FRAM_I2C, FRAM_ADDRESS_READ, reg, I2C_MEMADD_SIZE_16BIT,
                     data, 1, 100);

    // return data if success
    if (res == HAL_OK) {
        return *data;
    } else {
        return 0;
    }
}

uint8_t fram_init(){
    uint8_t data = 0;
    // check device id
//     • Device ID
// The Device ID command reads fixed Device ID. The size of Device ID is 3 bytes and consists of manufacturer
// ID and product ID. The Device ID is read-only and can be read out by following sequences.
// a) The master sends the Reserved Slave ID F8H after the START condition.
// b) The master sends the device address word after the ACK response from the slave.
// In this device address word, R/W code are “Don't care” value.
// c) The master re-sends the START condition followed by the Reserved Slave ID F9H after the ACK response
// from the slave.
// d) The master read out the Device ID succeedingly in order of Data Byte 1st / 2nd / 3rd after the ACK
//  response from the slave.
// e) The master responds the NACK (SDA is the “H” level) after reading 3 bytes of the Device ID.
// In case the master respond the ACK after reading 3 bytes of the Device ID, the master re-reading the
// Device ID from the 1st byte

    uint8_t id[3];
    HAL_I2C_Mem_Read(FRAM_I2C, FRAM_ADDRESS_READ, 0xF9, I2C_MEMADD_SIZE_16BIT,
                     id, 3, 100);
    if (id[0] != 0x00 || id[1] != 0x00 || id[2] != 0x00) {
        return 0;
    }
    return data;

}

uint8_t fram_read8(uint16_t framAddr){
    uint8_t data = 0;
    ms5611_i2c_read_byte(framAddr, &data);
    return data;
}
uint16_t fram_read16(uint16_t framAddr){
    uint8_t data[2];
    for (int i = 0; i < 2; i++) {
        ms5611_i2c_read_byte(framAddr + i, &data[i]);
    }
    return (data[0] << 8) | data[1];
}
float fram_readFloat(uint16_t framAddr){
    uint8_t data[4];
    HAL_StatusTypeDef res;
    for (int i = 0; i < 4; i++) {
        ms5611_i2c_read_byte(framAddr + i, &data[i]);
    }
    fram_float_to_u8 u;
    u.u8[0] = data[0];
    u.u8[1] = data[1];
    u.u8[2] = data[2];
    u.u8[3] = data[3];
    return u.u32;
    
}

uint8_t fram_read(uint16_t framAddr, uint8_t *value, uint8_t n){
    HAL_I2C_Mem_Read(FRAM_I2C, FRAM_ADDRESS_READ, framAddr, I2C_MEMADD_SIZE_8BIT,
                     value, n, 100);
    return 0;
}

uint8_t fram_write8(uint16_t framAddr, uint8_t value){
    ms5611_i2c_write_byte(framAddr, value);
    return value;
}
uint8_t fram_write16(uint16_t framAddr, uint16_t value){
    uint8_t data[2];
    data[0] = value >> 8;
    data[1] = value & 0xFF;
    for (int i = 0; i < 2; i++) {
        ms5611_i2c_write_byte(framAddr + i, data[i]);
    }
    return (data[0] << 8) | data[1];
}
float fram_writeFloat(uint16_t framAddr, uint32_t value){
    fram_float_to_u8 u;
    u.u32 = value;
    uint8_t data[4];
    data[0] = u.u8[0];
    data[1] = u.u8[1];
    data[2] = u.u8[2];
    data[3] = u.u8[3];
    HAL_StatusTypeDef res;
    for (int i = 0; i < 4; i++) {
        ms5611_i2c_write_byte(framAddr + i, data[i]);
    }

    return u.u32;
}
uint8_t fram_write(uint16_t framAddr, uint8_t *value, uint8_t n){
    HAL_I2C_Mem_Write(FRAM_I2C, FRAM_ADDRESS_WRITE, framAddr,
                      I2C_MEMADD_SIZE_8BIT, value, n, 100);
    return 0;
}

uint8_t clear_fram(){
    uint8_t data[32];
    for (int i = 0; i < 32; i++) {
        data[i] = 0;
    }
    HAL_I2C_Mem_Write(FRAM_I2C, FRAM_ADDRESS_WRITE, 0x00,
                      I2C_MEMADD_SIZE_8BIT, data, 32, 100);
    return 0;
}
