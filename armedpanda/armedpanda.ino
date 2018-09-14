/*******************************************************************************/  
/***************** Armed Panda Switches and Leds *******************************/                               
/*******************************************************************************/
//=============================================================================
//  Members: Gaspar A. Rocha , Victor O. Ogata   
//              
//  Creation Date:      22/08/2018
//  Revision History 
//  Name:               Date:         Description
//  Victor O. Ogata     22/08/2018    Switches and leds programming
//  Gaspar A. Rocha     23/08/2018    Switches and leds programming
//  Victor O. Ogata     25/08/2018    bug fixes
//  Gaspar A. Rocha     25/08/2018    bug fixes
//  Victor O. Ogata     03/09/2018    Seven-segment display programming
//  Gaspar A. Rocha     04/09/2018    Seven-segment display programming
//  Victor O. Ogata     05/09/2018    bug fixes
//  Gaspar A. Rocha     05/09/2018    bug fixes
//  Victor O. Ogata     11/09/2018    bug fixes                              
//=============================================================================

byte DIGITS[10][7] = { { 1,1,1,1,1,1,0 },  // = Digit 0
                       { 0,1,1,0,0,0,0 },  // = Digit 1
                       { 1,1,0,1,1,0,1 },  // = Digit 2
                       { 1,1,1,1,0,0,1 },  // = Digit 3
                       { 0,1,1,0,0,1,1 },  // = Digit 4
                       { 1,0,1,1,0,1,1 },  // = Digit 5
                       { 1,0,1,1,1,1,1 },  // = Digit 6
                       { 1,1,1,0,0,0,0 },  // = Digit 7
                       { 1,1,1,1,1,1,1 },  // = Digit 8
                       { 1,1,1,0,0,1,1 },  // = Digit 9
                                 };
int BinaryDigits[10][5] = { { 0,0,0,0,0 },
                            { 0,0,0,1,1 },
                            { 0,0,1,0,2 },
                            { 0,0,1,1,3 },
                            { 0,1,0,0,4 },
                            { 0,1,0,1,5 },
                            { 0,1,1,0,6 },
                            { 0,1,1,1,7 },
                            { 1,0,0,0,8 },
                            { 1,0,0,1,9 }, };
                             

void setup() {
  pinMode(11,INPUT);  // sw3
  pinMode(10,INPUT);  // sw2
  pinMode(9,INPUT);  // sw1
  pinMode(8,INPUT); // sw0
  pinMode(13,OUTPUT);// white led
  pinMode(12,OUTPUT);// blue led
  pinMode(A0,INPUT);  // sw3d
  pinMode(A1,INPUT);  // sw2d
  pinMode(A2,INPUT);  // sw1d
  pinMode(A3,INPUT); // sw0d

  pinMode(1, OUTPUT); // A  
  pinMode(2, OUTPUT); // B
  pinMode(3, OUTPUT); // C
  pinMode(4, OUTPUT); // D
  pinMode(5, OUTPUT); // E
  pinMode(6, OUTPUT); // F
  pinMode(7, OUTPUT); // G
  pinMode(0, OUTPUT); // DOT


}

void DigitConstructor(byte digit)  
{
  byte pin = 1;
  for (byte segCount = 0; segCount < 7; ++segCount)  
  { 
    digitalWrite(pin, DIGITS[digit][segCount]);
    ++pin;
 }
   delay(100); 
}



void loop() {
 int sw0=0,sw1=0,sw2=0,sw3=0;
 int swd[4],count=0;
  
 swd[3]=digitalRead(A3);
 swd[2]=digitalRead(A2);
 swd[1]=digitalRead(A1);
 swd[0]=digitalRead(A0);
 
 sw0=digitalRead(8);
 sw1=digitalRead(9);
 sw2=digitalRead(10);
 sw3=digitalRead(11);

//switches and leds
 if(sw0==0 && sw1==0 ){//and
  digitalWrite(12,HIGH);
 }
 else {
  digitalWrite(12,LOW);
 }
 
  if((sw2==1 && sw3==0 )||(sw2==0 && sw3==1 )){//xor
  digitalWrite(13,HIGH);
 }
 else {
  digitalWrite(13,LOW);
 }

//Seven segment display
  for(int y=0;y<10;y++){
    count=0;
    for(int i=0;i<4;i++){ 
      if(BinaryDigits[y][i]==swd[i]){
        count++;
      }
      }
    if(count==4){
      DigitConstructor(BinaryDigits[y][4]);
      y=10;
    }
  }

  // delay(500);
}
