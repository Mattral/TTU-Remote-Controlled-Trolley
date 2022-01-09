// Arduino Car Code 
#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>


#define CE_PIN  A8
#define CSN_PIN A9

int buzzer = 22;
/////////////////////////////////MOTOR PINOUT//////////////////////////////////

const int stepX=2;
const int dirX=5;
const int stepY=3;
const int dirY=6;
const int stepZ=4;
const int dirZ=7;
const int stepA=12;
const int dirA=13;
const int enPin=8;
int DLT=80;

const int LED = 21;
 int bait=22;
 int prey=24;

int stateNow = 0;
int stateBefore = 0;
int i = 0;
int j = 0;

///////////////////////////////////////////////////////////////////////////////

char data[20]="";

RF24 radio(CE_PIN,CSN_PIN);
const uint64_t pipe = 0xE8E8F0F0E1LL;

void setup()
{
 ////////////////////////////////////MOTOR PINMODE////////////////////////////////////

  pinMode (stepX,OUTPUT);
  pinMode (dirX,OUTPUT);
  pinMode (stepY,OUTPUT);
  pinMode (dirY,OUTPUT);
  pinMode (stepZ,OUTPUT);
  pinMode (dirZ,OUTPUT);
  pinMode (stepA,OUTPUT);
  pinMode (dirA,OUTPUT);
  pinMode (enPin,OUTPUT);


  pinMode(LED,OUTPUT);
  pinMode(bait,OUTPUT);
  pinMode(prey,INPUT);

 //////////////////////////////////////////////////////////////////////////////////////
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();
  
  pinMode(buzzer,OUTPUT);
}
 
void loop(){
  String msg="";
  if ( radio.available() )
  {
    radio.read( data,sizeof(data) );
    Serial.println(data);
    msg=data;

    if(msg=="up")
    {
  
  digitalWrite (enPin,LOW); 
  digitalWrite (dirX,HIGH);
  digitalWrite (dirY,LOW);
  digitalWrite (dirZ,HIGH);
  digitalWrite (dirA,LOW);
  
  rotation();

  Serial.println("Motor forward");
  digitalWrite(buzzer,HIGH);
  }
  else if(msg=="down")
  {
  
  digitalWrite (enPin,LOW); 
  digitalWrite (dirX,LOW);
  digitalWrite (dirY,HIGH);
  digitalWrite (dirZ,LOW);
  digitalWrite (dirA,HIGH);
  
       rotation();

  Serial.println("Motor Back");
  digitalWrite(buzzer,HIGH);
  }
   else if(msg=="left")
  {
  
digitalWrite (enPin,LOW); 
  digitalWrite (dirX,HIGH);
  digitalWrite (dirY,HIGH);
  digitalWrite (dirZ,HIGH);
  digitalWrite (dirA,HIGH);
  
     rotation();

  Serial.println("Left");
  digitalWrite(buzzer,HIGH);
  }
   else if(msg=="right")
  {

  digitalWrite (enPin,LOW); 
  digitalWrite (dirX,LOW);
  digitalWrite (dirY,LOW);
  digitalWrite (dirZ,LOW);
  digitalWrite (dirA,LOW);
  
      rotation();
  
  Serial.println("right");

  }
  else if(msg=="N0")
  {
  digitalWrite (enPin,HIGH);
  Serial.println("STOP it");
   digitalWrite(buzzer,HIGH);
  }


//   while (msg=="analgobot");
//   {
//    bait=HIGH;
//   }
//  
//     
//    lighting();
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////    ROTATION     //////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////

void rotation()
{
  
  for (int x=0;x<100;x++)// pulse 
   {
 
      digitalWrite (stepX,HIGH);
      delayMicroseconds (DLT);
      digitalWrite (stepX,LOW);
      delayMicroseconds (DLT);
      //
      digitalWrite (stepY,HIGH);
      delayMicroseconds (DLT);
      digitalWrite (stepY,LOW);
      delayMicroseconds (DLT);
      //
      digitalWrite (stepZ,HIGH);
      delayMicroseconds (DLT);
      digitalWrite (stepZ,LOW);
      delayMicroseconds (DLT);
      //
      digitalWrite (stepA,HIGH);
      delayMicroseconds (DLT);
      digitalWrite (stepA,LOW);
      delayMicroseconds (DLT);
    }
    
}


///////////////////////////////// LIGHTING  /////////////////////////////////////

void lighting()
{
  
  
  stateNow = digitalRead(prey);
  if (stateNow != stateBefore) {
    if (stateNow==HIGH and i==0) {
      digitalWrite (LED, HIGH);
      j=1;
    }
    else if (stateNow==LOW and j==1) {
      i=1;
    }
    else if (stateNow==HIGH and i==1) {
      digitalWrite (LED, LOW);
      j=0;
    }
    else if (stateNow==LOW and j==0) {
      i=0;
    }
  }
  stateBefore=stateNow;
}
