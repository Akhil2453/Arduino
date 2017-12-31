/*
 * Hellow World
 * 
 * Counting from 0-255
 */

 // ST_CP(pin 12 of 74HC595) --> pin 8
 int latch = 8;

 // SH_CP (pin 11 of 74HC595) --> pin 12
 int clk = 12;

 // DS (pin 14 of 74HC595) --> pin 11
 int data = 11;

 
void setup() {
  // put your setup code here, to run once:
  // Set pins to output
  pinMode(latch, OUTPUT);
  pinMode(clk, OUTPUT);
  pinMode(data, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  // count from 0-255 on LEDs
  int num = 0;
  for(num = 0; num<256; num++){
    //set latchpin to low, so that LEDs don;t change while the data is being sent
    digitalWrite(latch, LOW);
    // Shift out the bits
    shiftOut(data, clk, MSBFIRST, num);
    // set latchpin high, for the LED to glow
    digitalWrite(latch, HIGH);
    //pause before next value
    delay(1000);
  }
}
