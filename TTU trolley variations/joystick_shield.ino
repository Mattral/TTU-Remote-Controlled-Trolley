
//Arduino Joystick shield Code
#include <nRF24L01.h>
#include <RF24.h>
#include <SPI.h>


#define CE_PIN  9
#define CSN_PIN 10

const int up_button     = 3; 
int down_button   = 5;  
int left_button   = 6;  
int right_button  = 4; 
int start_button  = 7; 
int select_button = 8; 
int analog_button = 2;  
int x_axis = A0;
int y_axis = A1;
int buttons[]={up_button, down_button,left_button,
               right_button,start_button,select_button,analog_button};


const uint64_t pipe = 0xE8E8F0F0E1LL;
RF24 radio(CE_PIN,CSN_PIN);
char msg[20] = "";

void setup(){
     for(int i; i <1 ; i++)
     {
         pinMode(buttons[i],INPUT);
         digitalWrite(buttons[i],LOW);  
     } 
     Serial.begin(9600);
     radio.begin();
     radio.openWritingPipe(pipe);
}

void loop(){
       
      if(digitalRead(up_button)==HIGH)
      {
        char msg[]="up";
      radio.write(&msg,sizeof(msg));
      delay(1);
        Serial.println("UP Button Pressed");
      }
      
       if(digitalRead(down_button)==HIGH)
       {
        char msg[]="down";
      radio.write(&msg,sizeof(msg));
      delay(1);
        Serial.println("Down Button Pressed");
      }
       if(digitalRead(left_button)==HIGH)
      {
        char msg[]="left";
      radio.write(&msg,sizeof(msg));
      delay(1);
        Serial.println("Left Button Pressed");
      }
       if(digitalRead(right_button)==HIGH)
       {
        char msg[]="right";
      radio.write(&msg,sizeof(msg));
      delay(1);
        Serial.println("Rigth Button Pressed");
      }
      if(digitalRead(analog_button)==LOW)
       {
        char msg[]="analgobot";
      radio.write(&msg,sizeof(msg));
      delay(1);
        Serial.println("analog Button Pressed");
      }
      else{
        char msg[]="NO";
      radio.write(&msg,sizeof(msg));
      delay(1);
        Serial.println("NO Button Pressed");
      }
       
      
      
      
//      Serial.print("\n X = "),Serial.print(analogRead(x_axis)),Serial.print(" \n Y = "), Serial.print(analogRead(y_axis));
//      Serial.print("  ");
//      delay(10);
}
