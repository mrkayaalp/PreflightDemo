#include "checking.h"
#include "main.h"
#include "system.h"
#include "def.h"

uint8_t checkLiftoff()
{
    if (altitude.altitude > 50)
    { // +acc
        return 1;
    }
    else
        return 0;
}

uint8_t checkApogee()
{

    if (altitude.altitude > 500 && altitude.diffToMax > 10)
    { // altitude.diffToMax kısmına emin ol
        return 1;
    }
    else
        return 0;
}

uint8_t checkMainParachute()
{
    if (altitude.altitude < MAIN_PARACHUTE_ALTITUDE + 10)
    {
        return 1;
    }
    else
        return 0;
}

uint8_t checkSeparationAltitude()
{
    if (altitude.altitude < SEPARATION_ALTITUDE + 10)
    {
        return 1;
    }
    else
        return 0;
}

uint8_t checkSteadyAltitude()
{
    if (altitude.altitude < STEADY_WAITING_ALTITUDE + 10)
    {
        return 1;
    }
    else
        return 0;
}
uint8_t checkBeforeLanding()
{
    if (altitude.altitude < 40)
    {
        return 1;
    }
    else
        return 0;
}

uint8_t checkLanding()
{
    if (altitude.altitude < 10 || time.apogeeTime > 31690)
    {
        return 1;
    }
    else
        return 0;
}
