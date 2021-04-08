#include "contactless_therm.h"

//Check Distance Function:
/* This function checks the distance of the user from the thermometer */
boolean checkDistance(int trigPin, int echoPin)
{
  int distance;
  int duration;
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  if(distance<6){ //Range Finder is cm behind thermometer, so thermometer 2cm from person
    return true;
  }
  else
  {
    return false;
  }
 }

 //Temperature Read Function:
 /* This is the function fore reading temperature from the SparkFun Contactless Thermometer*/
float turnOnThermometer(IRTherm therm)
{
  
  // Call therm.read() to read object and ambient temperatures from the sensor.

  
  if (therm.read()) // On success, read() will return 1, on fail 0.
  {
    // Use the object() and ambient() functions to grab the object and ambient
  // temperatures.
  // They'll be floats, calculated out to the unit you set with setUnit().
    Serial.print("Object: " + String(therm.object(), 2));
    Serial.write('°'); // Degree Symbol
    Serial.println("F");
    Serial.print("Ambient: " + String(therm.ambient(), 2));
    Serial.write('°'); // Degree Symbol
    Serial.println("F");
    Serial.println();
  }
  delay(500);
  return (therm.object());
}

//Display Temperature Function:
/* This function takes in an input value and prints it out to the OLED Screen */
void displayTemp(float number) {


  /**value = analogRead(A0);      // sensor output to arduino analog A0 pin
  voltage = value * 0.00488;
  temperature = voltage * 100;
  **/
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(20, 10);
  display.print("Temperature");
  display.setCursor(15, 30);
  display.setTextSize(3);
  display.print(number);
  display.print("F");
  display.display();
  delay(1000);
  
}

 
