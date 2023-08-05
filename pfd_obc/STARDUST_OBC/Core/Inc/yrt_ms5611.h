// author: dogu

#ifndef MS5611_h
#define MS5611_h

#include <main.h>
#include <stdint.h>

// #define USE_OS_DELAY 1 // uncomment to use osDelay() instead of HAL_Delay()

#define MS5611_ADDRESS (0x77)
#define CMD_RESET 0x1E
#define CMD_PROM_C1 0xA2
#define CMD_PROM_C2 0xA4
#define CMD_PROM_C3 0xA6
#define CMD_PROM_C4 0xA8
#define CMD_PROM_C5 0xAA
#define CMD_PROM_C6 0xAC

#define PRESSURE_OSR_256  0x40
#define PRESSURE_OSR_512  0x42
#define PRESSURE_OSR_1024 0x44
#define PRESSURE_OSR_2048 0x46
#define PRESSURE_OSR_4096 0x48

#define TEMP_OSR_256      0x50
#define TEMP_OSR_512  	  0x52
#define TEMP_OSR_1024 	  0x54
#define TEMP_OSR_2048     0x56
#define TEMP_OSR_4096     0x58

#define CONVERSION_OSR_256  1
#define CONVERSION_OSR_512  2
#define CONVERSION_OSR_1024 3
#define CONVERSION_OSR_2048 5
#define CONVERSION_OSR_4096 10



/**
 * @brief The oversampling rate
 * @warn an higher value means a longer conversion
 */
typedef enum OSR {
	OSR_256,
	OSR_512,
	OSR_1024,
	OSR_2048,
	OSR_4096
}OSR;


extern int ms5611_init();
extern void ms5611_setOSR(OSR osr);


#endif /* BAROMETER_H_ */
