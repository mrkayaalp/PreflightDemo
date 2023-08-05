#ifndef __CHECKING_H__
#define __CHECKING_H__

#include "def.h"
#include "stdint.h"

extern Altitude altitude;

uint8_t checkLiftoff();
uint8_t checkBurnout();
uint8_t checkApogee();
uint8_t checkMainParachute();
uint8_t checkLanding();

#endif  // __CHECKING_H__