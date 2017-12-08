// code written by Vinayak Tyagi for reading your joysticks' values
#define Xpin A0 // define the X axis pin at analog 0
#define Ypin A1 // define the Y axis pin at analog 1
int X = 0;
int Y = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // begin serial communication @ 9600 baud

}

void loop() {
  // put your main code here, to run repeatedly:
  X = analogRead(Xpin); // read the value of X axis
  Y = analogRead(Ypin); // read the values of Y axis
  X = map(X, 0, 1023, 0, 10); // Map the values of X axis from 0 to 1023, to 0 to 10
  Y = map(Y, 0, 1023, 0, 10); // Map the values of Y axis from 0 to 1023, to 0 to 10
  Serial.println("Value of X axis :");
  Serial.println(X);
  Serial.println("\n");
  Serial.println("Value of Y axis :");
  Serial.println(Y);
  Serial.println("\n \n");
  delay(800);

}
