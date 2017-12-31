/*
   Reads from Serial Monitor and displays on the LED's
*/

// ST_CP(pin 12 of 74HC595) --> pin 8
int latch = 8;

// SH_CP (pin 11 of 74HC595) --> pin 12
int clk = 12;

// DS (pin 14 of 74HC595) --> pin 11
int data = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(latch, OUTPUT);
  pinMode(clk, OUTPUT);
  pinMode(data, OUTPUT);
  Serial.begin(9600);
  Serial.println("__Reset__");
}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available() > 0){
  /*
   * ASCII 0-9 are represented as 48-57
   * if user types 0-9, tou can subtract 48 to get the 
   * actual value
   */

   int biT = Serial.read() - 48;

   //write to shift register
   registerWrite(biT, HIGH);
}
}

// thos method sends data to shift register
void registerWrite(int pin, int state)
{
  byte bits = 0;
  digitalWrite(latch, LOW);
  bitWrite(bits, pin, state);
  shiftOut(data, clk, MSBFIRST, bits);
  digitalWrite(latch, HIGH);
}


