#include<Servo.h>

Servo servo;
int blueip;


void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  //digitalWrite(9,HIGH);
  Serial.begin(9600);
  Serial.println("Enter AT Commands");
  Serial3.begin(9600);
  servo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial3.available()) {
    blueip = Serial3.read();
    if(blueip == '1'){
      for(int i=0; i<=180; i++){
        servo.write(i);
      }
      //digitalWrite(13, HIGH);
      //delay(2000);
    }
    if(blueip == '2'){
      for(int i=180; i>=0; i--){
        servo.write(i);
      }
      //digitalWrite(13, LOW);
    }
    Serial.write(blueip);
  }
  if (Serial.available()) {
    Serial3.write(Serial.read());
  }
}
