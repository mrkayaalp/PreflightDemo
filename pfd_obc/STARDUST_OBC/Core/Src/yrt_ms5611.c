// author: dogu
#include "yrt_ms5611.h"

extern I2C_HandleTypeDef hi2c2;
#define MS5611_I2C &hi2c2


static uint16_t prom[6];

// min OSR by default
static uint8_t pressAddr = PRESSURE_OSR_256;
static uint8_t tempAddr = TEMP_OSR_256;
static uint32_t convDelay = CONVERSION_OSR_256;

static int32_t temperature;
static int32_t pressure;
static float altitude;

void ms5611_i2c_write_byte(uint8_t reg, uint8_t data) {
    HAL_I2C_Mem_Write(MS5611_I2C, MS5611_ADDRESS << 1, reg,
                      I2C_MEMADD_SIZE_8BIT, &data, 1, 100);
}

void ms5611_i2c_read_byte(uint8_t reg, uint8_t *data) {
    HAL_I2C_Mem_Read(MS5611_I2C, MS5611_ADDRESS << 1, reg, I2C_MEMADD_SIZE_8BIT,
                     data, 1, 100);
}

uint16_t ms5611_i2c_read_word(uint8_t reg) {
    uint8_t data[2];
    HAL_I2C_Mem_Read(MS5611_I2C, MS5611_ADDRESS << 1, reg, I2C_MEMADD_SIZE_8BIT,
                     data, 2, 100);
    return (data[0] << 8) | data[1];
}

uint32_t ms5611_i2c_read_24bits(uint8_t reg) {
    uint8_t data[3];
    HAL_I2C_Mem_Read(MS5611_I2C, MS5611_ADDRESS << 1, reg, I2C_MEMADD_SIZE_8BIT,
                     data, 3, 100);
    return (data[0] << 16) | (data[1] << 8) | data[2];
}

void ms5611_delay(uint32_t time) {
// HAL_Delay or osDelay
#ifdef USE_OS_DELAY
    osDelay(time);
#else
    HAL_Delay(time);
#endif
}

int ms5611_init() {
    ms5611_i2c_write_byte(CMD_RESET, CMD_RESET);
    ms5611_delay(3);

    prom[0] = ms5611_read16bits(CMD_PROM_C1);
    prom[1] = ms5611_read16bits(CMD_PROM_C2);
    prom[2] = ms5611_read16bits(CMD_PROM_C3);
    prom[3] = ms5611_read16bits(CMD_PROM_C4);
    prom[4] = ms5611_read16bits(CMD_PROM_C5);
    prom[5] = ms5611_read16bits(CMD_PROM_C6);

    return 1;
}

uint32_t ms5611_read_rawTemp() {
    ms5611_i2c_write_byte(tempAddr, tempAddr);
    ms5611_delay(10);
    return ms5611_i2c_read_24bits(0x00);
}

uint32_t ms5611_read_rawPress() {
    ms5611_i2c_write_byte(pressAddr, pressAddr);
    ms5611_delay(10);
    return ms5611_i2c_read_24bits(0x00);
}

void ms5611_calculate() {
    int32_t dT;
    int64_t TEMP, OFF, SENS, P;
    uint32_t D1, D2;
    float press, r, c;

    D1 = ms5611_readRawPressure();
    D2 = ms5611_readRawTemp();

    dT = D2 - ((long)prom[4] * 256);
    TEMP = 2000 + ((int64_t)dT * prom[5]) / 8388608;
    OFF = (int64_t)prom[1] * 65536 + ((int64_t)prom[3] * dT) / 128;
    SENS = (int64_t)prom[0] * 32768 + ((int64_t)prom[2] * dT) / 256;

    if (TEMP < 2000) {  // second order temperature compensation
        int64_t T2 = (((int64_t)dT) * dT) >> 31;
        int64_t Aux_64 = (TEMP - 2000) * (TEMP - 2000);
        int64_t OFF2 = (5 * Aux_64) >> 1;
        int64_t SENS2 = (5 * Aux_64) >> 2;
        TEMP = TEMP - T2;
        OFF = OFF - OFF2;
        SENS = SENS - SENS2;
    }

    P = (D1 * SENS / 2097152 - OFF) / 32768;
    temperature = TEMP;
    pressure = P;

    press = (float)pressure;
    r = press / 101325.0;
    c = 1.0 / 5.255;
    altitude = (1 - pow(r, c)) * 44330.77;
}

void ms5611_getTemperatureAndPressure(float *temp, float *press,
                                      float *alt) {
    ms5611_calculate();
    // *temperature = (float)temperature / 100.0;
    // *pressure = (float)pressure / 100.0;
    *temp = temperature / 100.0;
    *press = pressure / 100.0;
    *alt = altitude;
}

void ms5611_setOSR(OSR osr)
{
	switch(osr)
	{
		default:
		case OSR_256:
			pressAddr = PRESSURE_OSR_256;
			tempAddr = TEMP_OSR_256;
			convDelay = CONVERSION_OSR_256;
			break;
		case OSR_512:
			pressAddr = PRESSURE_OSR_512;
			tempAddr = TEMP_OSR_512;
			convDelay = CONVERSION_OSR_512;
			break;
		case OSR_1024:
			pressAddr = PRESSURE_OSR_1024;
			tempAddr = TEMP_OSR_1024;
			convDelay = CONVERSION_OSR_1024;
			break;
		case OSR_2048:
			pressAddr = PRESSURE_OSR_2048;
			tempAddr = TEMP_OSR_2048;
			convDelay = CONVERSION_OSR_2048;
			break;
		case OSR_4096:
			pressAddr = PRESSURE_OSR_4096;
			tempAddr = TEMP_OSR_4096;
			convDelay = CONVERSION_OSR_4096;
			break;
	}
}