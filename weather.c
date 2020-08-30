#include "weather.h"
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

Adafruit_BME280 bme;

int initBM280() {
  return bme.begin(0x76);
}