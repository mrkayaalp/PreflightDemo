#include "pfd.h"

void parseKongrulData((uint8_t *)data)
{
    sscanf(data, "%f, %f, %f, %f, %f, %f, %f",
           &altitude.altitude, &velocity.verticalVelocity,
           &altitude.temperature, &altitude.humidity,
           &gps.latitude, &gps.longtitude, &time.current);
}

void parseIllinoisData((uint8_t *)data)
{
    sscanf(data, "%f,%f,%f,%f,%f,%f,%f,%f,%f,%f", &time.current,
           &accel.x, &accel.y, &accel.z,
           &gyro.x, &gyro.y, &gyro.z,
           &gps.latitude, &gps.longtitude,
           &illinois.altitude, &altitude.pressure);
}

void parseSemrukVData((uint8_t *)data) // semrukV = ['time', 'ax', 'ay', 'az','barometer_altitude','velo']
{
    sscanf(data, "%f, %f, %f, %f, %f, %f", &time.current, &accel.x, &accel.y, &accel.y, &altitude.altitude, velocity.verticalVelocity);
}

void parseSemruk3Data((uint8_t *)data)
{
    sscanf(data, "%f", &altitude.altitude);
}