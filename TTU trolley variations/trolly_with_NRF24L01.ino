// Arduino Car Code 
#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>


#define CE_PIN  9
#define CSN_PIN 10


/////////////////////////////////MOTOR PINOUT//////////////////////////////////

const int ENA = A0 ;
const int IN1 = A1;
const int IN2 = A2;
const int IN3 = A3;
const int IN4 = A4;
const int ENB = A5;

const int in1 = 7;
const int in2 = 2;
const int in3 = 3;
const int in4 = 4;
const int enA = 5;
const int enB = 6;

int fspeed =  255;

const int LED = 7;
int val=0;
int counter=0;
int currentState=0;
int previousState=0;

///////////////////////////////////////////////////////////////////////////////

char data[20]="";

RF24 radio(CE_PIN,CSN_PIN);
const uint64_t pipe = 0xE8E8F0F0E1LL;

void setup()
{
 ////////////////////////////////////MOTOR PINMODE////////////////////////////////////

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

  pinMode(LED,OUTPUT);


    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW );
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    digitalWrite(ENA, 0);
    digitalWrite(ENB, 0);

    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW );
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    digitalWrite(enA, 0);
    digitalWrite(enB, 0);
  

 //////////////////////////////////////////////////////////////////////////////////////
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();
  
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

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH );
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENB, fspeed);
    analogWrite(ENA, fspeed);

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW );
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, fspeed);
    analogWrite(enA, fspeed);
    
  Serial.println("Motor forward");
 
  }
  else if(msg=="down")
  {
  
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW );
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, fspeed);
    analogWrite(ENA, fspeed);

    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH );
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, fspeed);
    analogWrite(enA, fspeed);
    
  Serial.println("Motor Back");

  }
   else if(msg=="left")
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENA, fspeed);

    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, fspeed);

    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, fspeed);

    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, fspeed);

  Serial.println("Left");
  
  }
   else if(msg=="right")
  {

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, fspeed);

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENB, fspeed);

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, fspeed);

    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, fspeed);
  
  Serial.println("right");
  }
 
     else if(msg=="NO")
   {
    Serial.println("STOPPED");
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW );
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    digitalWrite(ENA,0);
    digitalWrite(ENB,0);
  // delay(1);
   }
  

  }
}


//////////////////////////////////////////////////////////////////////////////////////

//void lighting()
//{
//  String msg="";
//  if(msg=="analgobut"){
//    val=HIGH;
//  }
//  else{
//    val=LOW;
//  }
//  delay(10);
//  //val=digitalRead(msg=="analgobut");
//  if(val==HIGH){
//  digitalWrite(LED,HIGH);
//  currentState=1;
//  }
//  else{
//    digitalWrite(LED,LOW);
//    currentState=0;
//  }
//  if(currentState!=previousState){
//    if(currentState==1);{
//      counter=counter+1;
//      Serial.println(counter);
//      
//    }
//  }
//  previousState=currentState;
//  delay(100);
//  
//}
