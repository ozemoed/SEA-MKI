

const int stepPin = 7;
const int dirPin = 8;
const int motorEnablePin = 9;

const int totalSteps = 1000;


void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(motorEnablePin, OUTPUT);

  digitalWrite(motorEnablePin, LOW);
}

void loop() {

  digitalWrite(dirPin, HIGH);
  
  for(int i=0; i< totalSteps; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }

//  digitalWrite(dirPin, LOW);
//  
//  for(int i=0; i< totalSteps; i++) {
//    digitalWrite(stepPin, HIGH);
//    delayMicroseconds(500);
//    digitalWrite(stepPin, LOW);
//    delayMicroseconds(500);
//  }


}

