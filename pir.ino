int Status = 12;  // Digital pin D6

int sensor = 13;  // Digital pin D7
void setup() {

  pinMode(sensor, INPUT);   // declare sensor as input
  pinMode(Status, OUTPUT);// declare LED as output
Serial.begin(115200);
}
  
void loop() {


    if(digitalRead(sensor) == HIGH) {
      
      digitalWrite (Status, HIGH);
      Serial.println("hasshod000000000");
      delay(1000);
    }
    else {
      digitalWrite (Status, LOW);
      Serial.println("nadarad");
      delay(1000);
      }
}
