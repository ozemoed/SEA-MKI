const int stepPin = 7;
const int dirPin = 8;
const int motorEnablePin1 = 9;
const int motorEnablePin2 = 2;

const int motor2PinA = 3;
const int motor2PinB = 4;
const int motor2PinC = 5;
const int motor2PinD = 6;

const int forcePin1 = 10;
const int forcePin2 = 10;
const int forcePin3 = 10;
const int forcePin4 = 10;

const int totalSteps = 380;
const int incrementalSteps = 50;
const int maxUpMovements = 5;

int upCounter = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(motorEnablePin1, OUTPUT);
  pinMode(motorEnablePin2, OUTPUT);

  pinMode(forcePin1, INPUT);
  pinMode(forcePin2, INPUT);
  pinMode(forcePin3, INPUT);
  pinMode(forcePin4, INPUT);
  
  // LOW means ENABLED
  digitalWrite(motorEnablePin1, LOW);
  digitalWrite(motorEnablePin2, HIGH);
}

void loop() {

  int val1 = digitalRead(forcePin1);
  int val2 = digitalRead(forcePin2);
  int val3 = digitalRead(forcePin3);
  int val4 = digitalRead(forcePin4);

  int delayMicro = 1000;
  if (val1 == 0) {
    delayMicro = 1100;
    
    // HIGH means arm going down
    digitalWrite(dirPin, HIGH);
    if (upCounter > 0) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(delayMicro);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(delayMicro);
  
      upCounter -= 1;
    }
    return;

  } else if (val2 == 0) {

    //do nothing
    return;
    
  } else if (val3 == 0) {
    delayMicro = 3000;
  } else if (val4 == 0) {
    delayMicro = 1500;
  }

  // Arm going up
  digitalWrite(dirPin, LOW);

  digitalWrite(stepPin, HIGH);
  delayMicroseconds(delayMicro);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(delayMicro);
  upCounter += 1;

}

