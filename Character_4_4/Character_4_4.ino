//////////////////////////////////////////////////by RizX///////
//4x4 led matrix with shift register and arduino 
//on a 5x5+ matrix it would be a lot nicer to write characters (go and try to make capital B,S,E.. etc in 4x4 pixels->looks like a fugly smudge)
 //im just testing something, btw my programming skills suck
//in this example i used R60 resitors, you might need to calculate different values for your project
//not sure if resistors 5-8 are needed, but i added them so the simulation wouldn't say i burned the ic :)
//if your chip is running hot, then just add some transistor on the row/column lines
 
#define dataPin  11 
#define latchPin 8
#define clockPin 12 

byte i,MyDataToSend;

const unsigned short MyDelay = 2; //refresh delay

//define your own custom led combinations here in the array 

byte ledData[][18]= //multi array 
{ //ROW order from bottom to up, the numbers are the data bits (0-15) on the current row
  //search for decimal to binary converter to get an better idea what's going on here. example: 15=1111
{0,0,0,0},   //0- all off 
{9,15,9,6},  //1- A
{9,6,6,9},   //2- X
{1,2,4,8},   //3- /
{9,15,15,9}, //4- H
{15,7,1,15}, //5- E -doesn't look much like E , but,, yeah 4x4 pixels -_-
{15,15,3,3}, //6- L
{6,9,9,6},   //7- O
{9,15,9,9},  //8- W
{9,7,9,7},   //9- R
{7,9,9,7},   //10-D
{6,9,6,6},   //11- =)
{15,0,0,0},  //12- _
{8,8,8,8},   //13-  |
{1,1,1,1},   //14-|
{0,0,0,15},  //15- -
{9,6,6,9},
{9,6,6,9}

};



void setup() // setup routine
{
  pinMode(latchPin, OUTPUT); //make those pins as OUTPUT
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin,  OUTPUT);
}

void SendThis(byte ThisData[],int number_of_times) //my custom function for sending data
{ 
  int n;
  for(n=1; n <= number_of_times; n++)
  {
   for (i=0; i<4; i++)
   {
     byte MyDataToSend = (1 << (i+4)) | (15 & ~ThisData[i]);
     digitalWrite(latchPin, LOW); //make pin LOW before sending data
     shiftOut(dataPin, clockPin, LSBFIRST, MyDataToSend);      
     digitalWrite(latchPin, HIGH);
     delay(MyDelay); 
   }
  }  
}

void loop() // the main program that loops, forever or until something breaks down -_=
{

 SendThis(ledData[12],10);  //-
 SendThis(ledData[14],10);  //|
 SendThis(ledData[15],10);  //|
 SendThis(ledData[13],10);  //-

 SendThis(ledData[11],50); //=)
 
 SendThis(ledData[4],30);  //H
 SendThis(ledData[5],30);  //E
 SendThis(ledData[6],30);  //L
 SendThis(ledData[6],30);  //L
 SendThis(ledData[7],30);  //O
 SendThis(ledData[8],30);  //W
 SendThis(ledData[7],30);  //O
 SendThis(ledData[9],30);  //R
 SendThis(ledData[6],30);  //L
 SendThis(ledData[10],30); //D

}


