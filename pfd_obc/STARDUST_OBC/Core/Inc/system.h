#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include <i2c.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "bmp280.h"
#include "def.h"
#include "lis3mdl.h"
#include "stdint.h"
#include "stm32f4xx_hal.h"
#include "yrt_fram.h"
#include "yrt_simpleKalman.h"

extern uint8_t flightState;
extern uint8_t controlDebugState;
extern char tlcTxString[STRING_BUFFER_SIZE];
extern char tlcRxString[STRING_BUFFER_SIZE];

extern char logString[STRING_BUFFER_SIZE];

extern char pccRxString[STRING_BUFFER_SIZE];

extern Time time;
extern Accel accel;
extern Gyro gyro;
extern Magnetometer mag;
extern Altitude altitude;
extern Velocity velocity;
extern Angle angle;
extern Gps gps;

extern LIS3MDL_Axes_t magnetoData;

/* File read buffer */

void readTime();

int initBarometer();
int readBarometer();
int readAltitude();

int initIMU();
int readIMU();
int fusionProcess();

int initMagnetometer();
int readMagnetometer();

void openingThemeSong(uint32_t time);

void writeFRAM_Float(uint16_t address, float data);
float readFRAM_Float(uint16_t address);

void initSD();
void writeSD(char *data);
void createTxString();
void parseTlcString(char *data);
void parsePccString(char *data);

void initFilter();

void buzzer(uint8_t state);
void led(uint8_t state);

void dragSchute(uint8_t state);
void mainSchute(uint8_t state);

void parseData(uint8_t *data);
void parseKongrulData(uint8_t *data);
void parseIllinoisData(uint8_t *data);

void altitudeApogee();
void velocityCalculated();
void readData();

#endif /* __SYSTEM_H__ */
