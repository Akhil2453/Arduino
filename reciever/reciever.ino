#include <VirtualWire.h>// import the Virtual Wire library
//#include <AFMotor.h> // import the Adafruit Motor Shield library
//AF_DCMotor motor1(3); // Set up a DC Motor named 'motor1' on the channel M1 of the motor shield
//AF_DCMotor motor2(4); // Set up a DC Motor named 'motor2' on the channel M2 of the motor shield
int a = 5;
int b = 6;

int c = 9;
int d = 10;

void setup()
{
  Serial.begin(9600); // begin serial communication @ 9600 baud
  pinMode(13, OUTPUT);
  vw_setup(2000); // set up the receiver @ 2000 bits per second
  vw_set_rx_pin(A4); // set up the receiver on digital pin 2
  vw_rx_start(); // Tell the D2 to listen for signals from the transmitter
  // motor1.setSpeed(105); // Set the speed of motor1 to 125. You can choose any speed from 0 to 255
  // motor2.setSpeed(105); // Set the speed of motor2 to 125
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
}
void loop()
{
  byte message[VW_MAX_MESSAGE_LEN];
  byte messageLength = VW_MAX_MESSAGE_LEN;
  if (vw_get_message(message, &messageLength)) // if the receiver gets a message
  {
    for (int i = 0; i < messageLength; i++)
    {
      Serial.write(message[i]); // print in the received message in the serial monitor
      if (message[i] == 'w') { // if message received is 'w', make the motors move forward
        //motor1.run(FORWARD);
        //motor2.run(FORWARD);
        digitalWrite(a, HIGH);
        digitalWrite(b, LOW);
        digitalWrite(c, LOW);
        digitalWrite(d, HIGH);
      }
      if (message[i] == 'x') { // if message received is 'x', make the motors stop
        //motor1.run(RELEASE);
        //motor2.run(RELEASE);
        digitalWrite(a, HIGH);
        digitalWrite(b, HIGH);
        digitalWrite(c, HIGH);
        digitalWrite(d, HIGH);
      }
      if (message[i] == 'a') { // if message received is 'a', make the motors move left
        //motor1.run(FORWARD);
        //motor2.run(BACKWARD);
        digitalWrite(a, HIGH);
        digitalWrite(b, LOW);
        digitalWrite(c, HIGH);
        digitalWrite(d, HIGH);
      }
      if (message[i] == 's') { // if the message received is 's' , make the motors move backwards
        //motor1.run(BACKWARD);
        //motor2.run(BACKWARD);
        digitalWrite(b, HIGH);
        digitalWrite(a, LOW);
        digitalWrite(d, LOW);
        digitalWrite(c, HIGH);
      }
      if (message[i] == 'd') { //if the message received is 'd', make the motors move right
        //motor1.run(BACKWARD);
        //motor2.run(FORWARD);
        digitalWrite(c, HIGH);
        digitalWrite(d, LOW);
        digitalWrite(a, HIGH);
        digitalWrite(b, HIGH);
      }

    }
    Serial.println();
  }
} // if the movements of the motors don't fit ypur requirement, please feel free to change them




