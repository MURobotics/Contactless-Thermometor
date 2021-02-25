//main test file for dummy header

void setup() {
    // put setup code here, to run once:
    Serial.begin(9600);

    randomSeed(analogRead(A0));
    
}

void loop() {
    // put your main code here, to run repeatedly:
    long rndNo = getRandomNumber(); // function that returns a random number to be printed

    Serial.println(rndNo);

    delay(2000);
    
}

// For the sake of testing here is a function that literally just gets a random number
long getRandomNumber() {

  unsigned long specialNumber = random(5, 1000); // gets random number between 5 and 1000

  specialNumber *= PI ; // multiplies by Pi and reassigns

  specialNumber -= 5; // subtracts 5 and reassigns

  return specialNumber;
  
}
