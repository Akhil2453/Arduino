#include <VirtualWire.h> // include the VirtualWire library
char inData[50];
int newmessage = 0;
void setup() {
  vw_setup(2000); // setup the transmitter @ 2000 bits per second
  vw_set_tx_pin(12); // set the transmission pin
  Serial.begin(9600); // begin serial communication @ 9600 baud
}
void loop()
{
  char inChar;
  byte index = 0;
  char mss[20];
  while (Serial.available() > 1) { // if serial is available
    if (index < 49)
    {
      delay(10);
      inChar = Serial.read(); // read the serial buffer and store the value in a character
      inData[index] = inChar;
      index++;
      inData[index] = '\0';
    }
    newmessage = 1; // this tells that there is a new message typed by you
  }
  if (newmessage == 1) { // if there's a message typed by you

    sprintf(mss, "%s", inData);
    vw_send((uint8_t *)mss, strlen(mss)); // send the message punched by you in the serial monitor
    vw_wait_tx(); // wait for the message to be transmitted
    Serial.println(mss); // print the character you typed in the serial monitor
    delay(600); // wait for 600 milliseconds
    newmessage = 0; // Indicate that there is no new message to wait for the new one
  }
}

