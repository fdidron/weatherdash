#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

struct Weather {
    float indoor_temperature;
    float indoor_humidity;
};

int initBM280();