#include <Servo.h>
Servo myservo;  

int light,pos = 0;   

void setup() {
  myservo.attach(9); 
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

void loop()
{
  light = analogRead(A0);
  Serial.println(light);
  if(light<850)
    {
      press();
      delay(10);
    }
}

void press()
{
  for (pos = 0; pos <= 50; pos ++) { 
    // in steps of 1 degree
    myservo.write(pos);
    delay(2);
  }
  for (pos = 50; pos >= 00; pos -= 1)
  {
    myservo.write(pos);
    delay(2);
  }
}