#include "system.h"

Bpc bpc;
Altitude altitude;
Velocity velocity;
Gps gps;
Time time;
Velocity velocity;

uint8_t flightState = START;


void parseData(uint8_t *data)
{
    sscanf(data, "%d,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f",
           &bpc.tick, &bpc.altitude,
           &bpc.pressure, &bpc.maxAltitude, &bpc.accel.x,
           &bpc.accel.y, &bpc.accel.z, &bpc.mag.x,
           &bpc.mag.y, &bpc.mag.z,
           &bpc.gyro.x, &bpc.gyro.y, &bpc.gyro.z);
}

void parseKongrulData(uint8_t *data)
{
    sscanf(data, "%f, %f, %f, %f, %f, %f, %f",
           &altitude.altitude, &velocity.verticalVelocity,
           &altitude.temperature, &altitude.humidity,
           &gps.latitude, &gps.longtitude, &time.current);
}

void readTime()
{
    time.timeDifference = (time.current - time.prevTime);
    time.prevTime = time.current;

    if (flightState > AFTER_LIFTOFF)
    {
        time.flightTime = (time.current - time.liftoffTime);
    }
}

void altitudeApogee()
{
    altitude.diffToMax = altitude.maxAltitude - altitude.altitude;
    if (altitude.altitude > altitude.maxAltitude)
    {
        altitude.maxAltitude = altitude.altitude;
    }
}

void velocityCalculated()
{
    altitude.prevAltitude = altitude.altitude;

    // calculate vertical velocity m/s
    velocity.timeDiffVertical =
        (time.current - velocity.prevTimeVertical) / 1000.0f;

    if (velocity.timeDiffVertical >
        1.f)
    { // Dikey hizi sagli olcmke icin bekleme

        velocity.prevTimeVertical = time.current;
        /*  (+) ise cikiyorsun (-) ise iniyorsun  */
        // 									Bura
        // santimetredir
        // .
        velocity.verticalVelocityCalculated =
            (altitude.altitude - altitude.prevAltitudeForVelocity) /
            (velocity.timeDiffVertical);

        altitude.prevAltitudeForVelocity = altitude.altitude;
    }

    return 0;
}

