
int contactSensorPin = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(contactSensorPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(contactSensorPin) == HIGH) {
    Serial.println("Your door is Open");
  } else {
    Serial.println("Your Door is Closed");
  }

  delay(100);
}
