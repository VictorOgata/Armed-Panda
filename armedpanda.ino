/*******************************************************************************/  
/***************** Armed Panda *************************************************/                               
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
//                                
//=============================================================================


void setup() {
  
  pinMode(3,INPUT);  // sw5
  pinMode(4,INPUT);  // sw4
  pinMode(6,INPUT);  // sw3
  pinMode(7,INPUT);  // sw2
  pinMode(8,INPUT);  // sw1
  pinMode(10,INPUT); // sw0
  pinMode(13,OUTPUT);// white led
  pinMode(12,OUTPUT);// blue led
  pinMode(11,OUTPUT);// red led

}

void loop() {
 int sw0=0,sw1=0,sw2=0,sw3=0,sw4=0,sw5=0;
 
 sw0=digitalRead(10);
 sw1=digitalRead(8);
 sw2=digitalRead(7);
 sw3=digitalRead(6);
 sw4=digitalRead(4);
 sw5=digitalRead(3);
  
 delay(10);

 if(sw0==0 && sw1==0 ){//and
  digitalWrite(12,HIGH);
 }
 else {
  digitalWrite(12,LOW);
 }
 
 if(sw2==0 || sw3==0 ){//or
  digitalWrite(11,HIGH);
 }
 else {
  digitalWrite(11,LOW);
 }
  if((sw4==1 && sw5==0 )||(sw4==0 && sw5==1 )){//xor
  digitalWrite(13,HIGH);
 }
 else {
  digitalWrite(13,LOW);
 }

}
