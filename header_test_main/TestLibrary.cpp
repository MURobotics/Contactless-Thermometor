

// For the sake of testing here is a function that literally just gets a random number
long getRandomNumber() {

  unsigned long specialNumber = random(5, 1000); // gets random number between 5 and 1000

  specialNumber *= PI ; // multiplies by Pi and reassigns

  specialNumber -= 5; // subtracts 5 and reassigns

  return specialNumber;
  
}
