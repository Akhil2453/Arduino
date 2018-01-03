/*
   Display values of LEDData across 4*4 matrix
*/

const int latchPin = 8;
const int clockPin = 12;
const int dataPin = 11;

byte i;
byte j;

byte dataTS;

byte ledData[] = {9,13,11,9};

void setup() {
  // put your setup code here, to run once:
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  for (i = 0; i < 4; i++) {
    byte dataTS = (1 << (i + 4)) | (15 & ~ ledData[i]);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, dataTS);
    digitalWrite(latchPin, HIGH);

    //delay(500);
  }
}
