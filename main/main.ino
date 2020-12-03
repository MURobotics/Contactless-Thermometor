#include <Wire.h> // I2C library, required for MLX90614
#include <SparkFunMLX90614.h> // SparkFunMLX90614 Arduino library


#define echoPin A2
#define trigPin A1
IRTherm therm; // Create an IRTherm object to interact with throughout

const byte LED_PIN = 8; // Optional LED attached to pin 8 (active low)
boolean checkDistance();
boolean check;
int temp = 0;

boolean checkDistance()
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
int sendToDisplay2(int temp)
{
  return 1;
}
int turnOnThermometer()
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
  return int(therm.object(), 2);
}

void setup() {
  // put your setup code here, to run once:
   pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // Initialize Serial to log output
  therm.begin(); // Initialize thermal IR sensor
  therm.setUnit(TEMP_F); // Set the library's units to Farenheit
  // Alternatively, TEMP_F can be replaced with TEMP_C for Celsius or
  // TEMP_K for Kelvin.
  
 // pinMode(LED_PIN, OUTPUT); // LED pin as output
  Serial.println("Please place your forehead near the sensor");

}

void loop() {
   Serial.println(temp);
  check=checkDistance();
  if (check==true)
  {
    temp=turnOnThermometer();
  }
  sendToDisplay2(temp);
  delay(3000);
}
  
