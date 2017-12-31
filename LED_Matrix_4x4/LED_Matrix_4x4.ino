/*
 * This code will light each led in the 4x4 matrix one at a time
 */

const int latchPin = 8;
const int clockPin = 12;
const int dataPin = 11;

byte i;
byte j;

byte dataTS;

void setup() {
  // put your setup code here, to run once:
pinMode(latchPin, OUTPUT);
pinMode(clockPin, OUTPUT);
pinMode(dataPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
for(i=0; i<4; i++){
  for(j=0; j<4; j++){
    
    dataTS = (1 << (i+4))|(15 &~ (1<<j));
    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, dataTS);
    digitalWrite(latchPin, HIGH);

    delay(5);
  }
}
}
