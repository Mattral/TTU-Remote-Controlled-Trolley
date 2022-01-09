#include <PS2X_lib.h>

PS2X ps2x;


const int in1 = 2;
const int in2 = 3;
const int in3 = 4;
const int in4 = 5;
const int enA = 8;
const int enB = 7;
int fspeed = 255;
int rspeed, lspeed;
byte PS2 = 0;
void setup() {

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  PS2 = ps2x.config_gamepad(9,10,11,12, false, false);

  Serial.begin(57600);
}

void loop() {
  ps2x.read_gamepad();
  if (ps2x.Button(PSB_GREEN)){
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH );
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, fspeed);
    analogWrite(enA, fspeed);
    Serial.println("forward straight forward");  
    }
    
  if (ps2x.Button(PSB_BLUE)){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW );
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, fspeed);
    analogWrite(enA, fspeed);
    Serial.println("forward straight forward");  
    }
  if (ps2x.Analog(PSS_RY) > 130) {
  //rspeed = map(ps2x.Analog(PSS_RY), 128, 255, 0, 255);
    Serial.println("right up ");
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, 255);

  }
  delay(10);
  if (ps2x.Analog(PSS_RY) < 120) {
  //rspeed = map(ps2x.Analog(PSS_RY), 0, 127, 255, 0);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    Serial.println("right down ");
    analogWrite(enA, 255);

  }
  delay(10);
  if (ps2x.Analog(PSS_LY) > 130)  
  {
  //lspeed = map(ps2x.Analog(PSS_LY), 0, 127, 255, 0);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, 255);
    Serial.println( "left down");


  }
  delay(10);
  if (ps2x.Analog(PSS_LY) < 120)  
  {
  //lspeed = map(ps2x.Analog(PSS_LY), 129, 255, 0, 255);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, 255);
    Serial.println("left up");

  }
  else {
    digitalWrite(enA,LOW);
    digitalWrite(enB,LOW);
  }
  delay(10);

 
}
