
const int stepPin = 7;
const int dirPin = 8;
const int motorEnablePin = 9;

const int totalSteps = 1000;


void setup() {
  Serial.begin(9600);
  
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(motorEnablePin, OUTPUT);

  digitalWrite(motorEnablePin, LOW);
}

void loop() {

  if (Serial.available() > 0) {

    int incomingByte = Serial.read();

    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);
  }

}

