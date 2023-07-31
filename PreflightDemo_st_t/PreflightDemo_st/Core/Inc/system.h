#ifndef SYSTEM_H
#define SYSTEM_H

#include "main.h"
#include "def.h"


extern uint8_t flightState;
extern Bpc bpc;
extern Altitude altitude;
extern Velocity velocity;
extern Gps gps;
extern Time time;

void parseData(uint8_t *data);
void parseKongrulData(uint8_t *data);
void readTime();
void altitudeApogee();
void velocityCalculated();

#endif
