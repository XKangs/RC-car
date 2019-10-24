#include <Servo.h>


Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(5,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(10,OUTPUT);  
}

void loop() {
  digitalWrite(10, HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  delay(2000); 
  analogWrite(5,180); //80%
  delay(2000); 
  analogWrite(5,127); //50%  
  delay(2000);
  digitalWrite(10, HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(3,HIGH);
  delay(2000); 
  analogWrite(5,180); //80%
  delay(2000); 
  analogWrite(5,127); //50%  
  delay(2000);
  myservo.write(0);
  delay(2000);
  myservo.write(90);
  delay(2000);
}
