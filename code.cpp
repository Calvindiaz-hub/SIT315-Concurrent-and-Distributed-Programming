const int motionSensorPin = 2;  
const int ledPin = LED_BUILTIN; 
void setup() {
  
  Serial.begin(9600);

  
  pinMode(motionSensorPin, INPUT);

  
  pinMode(ledPin, OUTPUT);

  
  digitalWrite(ledPin, LOW);
}

void loop() {
  
  int motionDetected = digitalRead(motionSensorPin);

  
  if (motionDetected == HIGH) {
    digitalWrite(ledPin, HIGH); 
  } else {
    digitalWrite(ledPin, LOW); 
  }

  
  Serial.print("Motion Sensor Value: ");
  Serial.print(motionDetected);
  Serial.print(" - LED Status: ");
  if (motionDetected == HIGH) {
    Serial.println("ON");
  } else {
    Serial.println("OFF");
  }

  
  delay(500);
}