void setup() {
  // put your setup code here, to run once:
  pinMode(A0, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(A0, HIGH);
  delay(1000);
  analogWrite(A0, LOW);
  delay(1000);
}
