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
