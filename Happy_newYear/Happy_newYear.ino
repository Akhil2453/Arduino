#define dataPin  11
#define latchPin 8
#define clockPin 12

byte i, MyDataToSend;

const unsigned short MyDelay = 2; //refresh delay

//define your own custom led combinations here in the array

byte ledData[][12] = //multi array
{ //ROW order from bottom to up, the numbers are the data bits (0-15) on the current row
  //search for decimal to binary converter to get an better idea what's going on here. example: 15=1111
  {0, 0, 0, 0},     //0- all off
  {9, 6, 6, 9},     //1- X
  {9, 15, 9, 6},     //2- A
  {15, 9, 7, 15},     //3- E
  {9, 15, 15, 9},   //4- H
  {9, 13, 11, 9},   //5- N
  {3, 15, 11, 15},   //6- P
  {9, 7, 9, 7},     //7- R
  {9, 15, 9, 9},    //8- W
  {1, 2, 6, 9},     //9- Y
  {0, 0, 0, 0},    //10- all off
  {6, 9, 6, 6},     //11- =)
};



void setup() // setup routine
{
  pinMode(latchPin, OUTPUT); //make those pins as OUTPUT
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin,  OUTPUT);
}

void SendThis(byte ThisData[], int number_of_times) //my custom function for sending data
{
  int n;
  for (n = 1; n <= number_of_times; n++)
  {
    for (i = 0; i < 4; i++)
    {
      byte MyDataToSend = (1 << (i + 4)) | (15 & ~ThisData[i]);
      digitalWrite(latchPin, LOW); //make pin LOW before sending data
      shiftOut(dataPin, clockPin, LSBFIRST, MyDataToSend);
      digitalWrite(latchPin, HIGH);
      delay(2);
    }
    delay(MyDelay);
  }
}

void loop() // the main program that loops, forever or until something breaks down -_=
{

  SendThis(ledData[0], 40); //0
  SendThis(ledData[1], 40); //X
  SendThis(ledData[4], 40); //H
  SendThis(ledData[2], 40); //A
  SendThis(ledData[6], 40); //P
  SendThis(ledData[6], 40); //P
  SendThis(ledData[9], 40); //Y
  SendThis(ledData[5], 40); //N
  SendThis(ledData[3], 40); //E
  SendThis(ledData[8], 40); //W
  SendThis(ledData[9], 40); //Y
  SendThis(ledData[3], 40); //E
  SendThis(ledData[2], 40); //A
  SendThis(ledData[7], 40); //R
  SendThis(ledData[11], 40); //=)
  SendThis(ledData[1], 40); //X

}
