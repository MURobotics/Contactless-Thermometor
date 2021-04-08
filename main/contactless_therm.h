#ifndef CONTACTLESS_THERM_H
#define CONTACTLESS_THERM_H

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SparkFunMLX90614.h>

boolean checkDistance();
float turnOnThermometer();
void displayTemp(float number);


#endif
