int m1p = 2;
int m1n = 3;
int m2p = 4;
int m2n = 5;
int m3p = 6;
int m3n = 7;
int m4p = 8;
int m4n = 9;

void Lfwd();
void Lbkwd();
void Rfwd();
void Rbkwd();
void Stop();


void setup() {
  // put your setup code here, to run once:
  pinMode(m1p, OUTPUT);
  pinMode(m1n, OUTPUT);
  pinMode(m2p, OUTPUT);
  pinMode(m2n, OUTPUT);
  pinMode(m3p, OUTPUT);
  pinMode(m3n, OUTPUT);
  pinMode(m4p, OUTPUT);
  pinMode(m4n, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Lfwd();
  Rfwd();
  delay(1000);
  Stop();
  delay(1000);
  Lbkwd();
  Rbkwd();
  delay(1000);
  Stop();
  delay(1000);
}

void Lbkwd()
{
  //left forward
  digitalWrite(m1p, LOW);
  digitalWrite(m1n, HIGH);
  digitalWrite(m2p, HIGH);
  digitalWrite(m2n, LOW);
}
void Lfwd()
{
  //left back
  digitalWrite(m1p, HIGH);
  digitalWrite(m1n, LOW);
  digitalWrite(m2p, LOW);
  digitalWrite(m2n, HIGH);
}
void Rbkwd()
{
  //right forwar
  digitalWrite(m3p, LOW);
  digitalWrite(m3n, HIGH);
  digitalWrite(m4p, HIGH);
  digitalWrite(m4n, LOW);
}
void Rfwd()
{
  //right backward
  digitalWrite(m3p, HIGH);
  digitalWrite(m3n, LOW);
  digitalWrite(m4p, LOW);
  digitalWrite(m4n, HIGH);
}
void Stop()
{
  //left stop
  digitalWrite(m1p, LOW);
  digitalWrite(m1n, LOW);
  digitalWrite(m2p, LOW);
  digitalWrite(m2n, LOW);
  //right stop
  digitalWrite(m3p, LOW);
  digitalWrite(m3n, LOW);
  digitalWrite(m4p, LOW);
  digitalWrite(m4n, LOW);
}


