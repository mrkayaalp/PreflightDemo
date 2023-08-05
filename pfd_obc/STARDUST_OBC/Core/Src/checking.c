#include "checking.h"

#include "system.h"

uint8_t checkLiftoff()
{
    if (fabs((double)accel.absG) > LIFTOFF_ACCELERATION &&
        altitude.altitude > LIFTOFF_ALTITUDE)
    {
        return 1;
    }
    else
        return 0;
}

uint8_t checkBurnout()
{
    if (fabs((double)accel.absG) < BURNOUT_ACCELERATION &&
        altitude.altitude > BURNOUT_ALTITUDE)
    {
        return 1;
    }
    else
        return 0;
}

uint8_t checkApogee()
{
    if (altitude.altitude > APOGEE_ALTITUDE &&
        velocity.verticalVelocity < APOGEE_VERTICAL_VELOCITY &&
        accel.x < 0.5 && (fabs(accel.y) > 0.5 || fabs(accel.z) > 0.5))
    {
        return 1;
    }
    else
        return 0;
}

uint8_t checkMainParachute()
{
    if (altitude.altitude < MAIN_PARACHUTE_ALTITUDE)
    {
        return 1;
    }
    else
        return 0;
}

uint8_t checkLanding()
{
    if (velocity.verticalVelocity > -1 && velocity.verticalVelocity < 1 &&
        altitude.altitude < 100)
    {
        return 1;
    }
    else
        return 0;
}
