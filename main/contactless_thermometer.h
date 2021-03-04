#ifndef contactless_thermometer_h
#define contactless_thermometer_h

/*** Library Includes ***/
#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SparkFunMLX90614.h> // SparkFunMLX90614 Arduino library

// Class for Contactless thermometer and functions
class contactlessTherm {
  public:
  // Constructor
    contactlessTherm(bool displayMsg=false);

  // Methods
    void begin(int baudRate=9600); // instantiating function

  private:
  // Place for private methods, variables etc.
    bool _msg; // display message for compilation
  
};
#endif
