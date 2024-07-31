const int motionSensorPin = 2;  
const int trigPin = 3;          
const int echoPin = 4;          
const int ledPin = LED_BUILTIN; 
const int secondLedPin = 9;     

volatile bool motionDetected = false;
volatile bool distanceDetected = false;

void handleMotion() {
  motionDetected = digitalRead(motionSensorPin) == HIGH;
}

void handleDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);

  long distance = duration * 0.034 / 2;

  distanceDetected = distance < 70;
}

void setup() {
  Serial.begin(9600);

  pinMode(motionSensorPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(ledPin, OUTPUT);
  pinMode(secondLedPin, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(motionSensorPin), handleMotion, CHANGE);

  digitalWrite(ledPin, LOW);
  digitalWrite(secondLedPin, LOW);
}

void loop() {
  handleDistance();

  if (motionDetected) {
    digitalWrite(ledPin, HIGH); 
  } else {
    digitalWrite(ledPin, LOW); 
  }

  if (distanceDetected) {
    digitalWrite(secondLedPin, HIGH); 
  } else {
    digitalWrite(secondLedPin, LOW); 
  }

  Serial.print("Motion Sensor Value: ");
  Serial.print(motionDetected);
  Serial.print(" - Built-in LED Status: ");
  Serial.print(motionDetected ? "ON" : "OFF");

  Serial.print(" | Distance Sensor Value: ");
  Serial.print(distanceDetected);
  Serial.print(" - Second LED Status: ");
  Serial.println(distanceDetected ? "ON" : "OFF");

  delay(500);
}
