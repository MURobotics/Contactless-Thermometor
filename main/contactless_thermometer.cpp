#include "contactless_thermometer.h"

contactlessTherm::contactlessTherm(bool displayMsg) {
  // Variables, print messages, or anything else needed when instatiating our library object goes here
  _msg = displayMsg; // setting our input constructor boolean equal to a private variable to control begin message output
}

void contactlessTherm::begin(int baudRate) {
  Serial.begin(baudRate);
  if (_msg) {
  Serial.println("Contactless Thermometer constructor instantiated successfully.");
  }
}

// Contactless Therm Library Functions
