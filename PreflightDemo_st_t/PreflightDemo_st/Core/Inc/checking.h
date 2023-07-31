#ifndef __CHECKING_H__
#define __CHECKING_H__

#include "stdint.h"

uint8_t checkLiftoff();
uint8_t checkApogee();
uint8_t checkMainParachute();
uint8_t checkLanding();

uint8_t checkSeparationAltitude();
uint8_t checkSteadyAltitude();
uint8_t checkBeforeLanding();

#endif // __CHECKING_H__