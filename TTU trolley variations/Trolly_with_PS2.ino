#include <PS2X_lib.h>

PS2X ps2x;


const int in1 = 2;
const int in2 = 3;
const int in3 = 4;
const int in4 = 5;
const int enA = 8;
const int enB = 7;

const int ENA = A0 ;
const int IN1 = A1;
const int IN2 = A2;
const int IN3 = A3;
const int IN4 = A4;
const int ENB = A5;
int fspeed = 255;

const int LED = 13;
int val=0;
int counter=0;
int currentState=0;
int previousState=0;

byte PS2 = 0;
void setup() {

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(LED,OUTPUT);
  PS2 = ps2x.config_gamepad(51,A14,A15,53, false, false);

  Serial.begin(57600);
}

void loop() {
  ps2x.read_gamepad();
  if (ps2x.Button(PSB_GREEN)){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW );
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, fspeed);
    analogWrite(enA, fspeed);

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH );
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENB, fspeed);
    analogWrite(ENA, fspeed);
    
    Serial.println("forward ");  }
    
   else if (ps2x.Button(PSB_BLUE)){
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH );
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, fspeed);
    analogWrite(enA, fspeed);

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW );
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, fspeed);
    analogWrite(ENA, fspeed);
    
    Serial.println("BACKWARD");  }

 
  else if(ps2x.Button(PSB_L1)){
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, fspeed);

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENA, fspeed);

    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, fspeed);

    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, fspeed);
    Serial.println("turn LEFT");
  }
 

  else if(ps2x.Button(PSB_R1)){
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, fspeed);

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, fspeed);

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, fspeed);

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENB, fspeed);
    Serial.println("turn RIGHT");
  }


  
  else {
    digitalWrite(enA,LOW);
    digitalWrite(enB,LOW);

    digitalWrite(ENA,LOW);
    digitalWrite(ENB,LOW);
    Serial.println("");
    Serial.println("NO COMMEND");
  }
  delay(10);

  

}

void lighting()
{
  val=digitalRead(ps2x.Button(PSB_RED));
  if(val==HIGH){
  digitalWrite(LED,HIGH);
  currentState=1;
  }
  else{
    digitalWrite(LED,LOW);
    currentState=0;
  }
  if(currentState!=previousState){
    if(currentState==1);{
      counter=counter+1;
      Serial.println(counter);
      
    }
  }
  previousState=currentState;
  delay(100);
  
}
