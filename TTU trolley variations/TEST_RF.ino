//Arduino Joystick shield Code





int up_button     = 3; // Boton Amarillo - A
int down_button   = 5; // Boton Amarillo - C 
int left_button   = 6; // Boton Azul     - D 
int right_button  = 4; // Boton Azul     - B
int start_button  = 7; // Boton F
int select_button = 8; // Boton E
int analog_button = 2; // 
int x_axis = A0;
int y_axis = A1;
int buttons[]={up_button, down_button,left_button,
               right_button,start_button,select_button,analog_button};




void setup(){
     for(int i; i <7 ; i++)
     {
         pinMode(buttons[i],INPUT);
         digitalWrite(buttons[i],HIGH);  
     } 
     Serial.begin(9600);
    
}

void loop(){
       
      if(digitalRead(up_button)==LOW)
      {
        delay(500);
        Serial.println("UP Button Pressed");
      }
      
       else if(digitalRead(down_button)==LOW)
       {
        delay(500);
        Serial.println("Down Button Pressed");
      }
       else if(digitalRead(left_button)==LOW)
      {
       delay(500);
        Serial.println("Left Button Pressed");
      }
       else if(digitalRead(right_button)==LOW)
       {
       delay(500);
        Serial.println("Right Button Pressed");
      }
       else if(digitalRead(start_button)==LOW)
       {
        delay(500);
    
        Serial.println("Start Button Pressed");
      }
       else if(digitalRead(select_button)==LOW)
       {
        delay(500);
        Serial.println("Select Button Pressed");
      }
       else if(digitalRead(analog_button)==LOW)
       {
        delay(500);
        Serial.println("Analog Button Pressed");
      }
      //Serial.print("\n X = "),Serial.print(analogRead(x_axis)),Serial.print(" \n Y = "), Serial.print(analogRead(y_axis));
      //Serial.print("  ");
      //delay(500);
}
