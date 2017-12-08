//Arduino UNO

#include<SoftwareSerial.h>

SoftwareSerial bt(10,11);

void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);
  Serial.begin(9600);
  Serial.println("Enter AT Commands");
  bt.begin(38400);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (bt.available()) {
    Serial.write(bt.read());
  }
  if (Serial.available()) {
    bt.write(Serial.read());
  }
}
