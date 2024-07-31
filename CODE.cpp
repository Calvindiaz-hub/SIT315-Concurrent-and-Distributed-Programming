
const int motionSensorPin = 2;  
const int ledPin = LED_BUILTIN; 

volatile bool motionDetected = false;

void handleMotion() {
  motionDetected = digitalRead(motionSensorPin) == HIGH;
}

void setup() {
  Serial.begin(9600);

  pinMode(motionSensorPin, INPUT);

  pinMode(ledPin, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(motionSensorPin), handleMotion, CHANGE);

  digitalWrite(ledPin, LOW);
}

void loop() {
  if (motionDetected) {
    digitalWrite(ledPin, HIGH); 
  } else {
    digitalWrite(ledPin, LOW); 
  }

  Serial.print("Motion Sensor Value: ");
  Serial.print(motionDetected);
  Serial.print(" - LED Status: ");
  if (motionDetected) {
    Serial.println("ON");
  } else {
    Serial.println("OFF");
  }

  delay(500);
}
