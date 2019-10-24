#include "TB6612.h"
TB6612::TB6612(uint8_t pinPWM, uint8_t pinIN1, uint8_t pinIN2, uint8_t pinSTBY){
	_pinPWM = pinPWM;
	_pinIN1 = pinIN1;
	_pinIN2 = pinIN2;
	_pinSTBY = pinSTBY;

	isMoving = false;
	isSleeping = false;

	pinMode(pinPWM,OUTPUT);
	pinMode(pinIN1,OUTPUT);
	pinMode(pinIN2,OUTPUT);
	pinMode(pinSTBY,OUTPUT);

	this->enable();
}
void TB6612::forward(uint8_t speed = 255){
  isMoving = true;
	analogWrite(_pinPWM, speed);
	digitalWrite(_pinIN1,LOW);
	digitalWrite(_pinIN2,HIGH);
}
void TB6612::backward(uint8_t speed = 255){
  isMoving = true;
	analogWrite(_pinPWM, speed);
	digitalWrite(_pinIN1,HIGH);
	digitalWrite(_pinIN2,LOW);
}
void TB6612::forward(){
  isMoving = true;
	digitalWrite(_pinPWM,HIGH);
	digitalWrite(_pinIN1,LOW);
	digitalWrite(_pinIN2,HIGH);
}
void TB6612::backward(){
  isMoving = true;
  digitalWrite(_pinPWM,HIGH);
  digitalWrite(_pinIN1,HIGH);
  digitalWrite(_pinIN2,LOW);
}
void TB6612::reset(){
	digitalWrite(_pinSTBY, LOW);
	delay(50);
	digitalWrite(_pinSTBY, HIGH);
}
void TB6612::enable(){
	isSleeping = false;
	digitalWrite(_pinSTBY, HIGH);
}
void TB6612::sleep(){
	isSleeping = true;
	digitalWrite(_pinSTBY, LOW);
}
void TB6612::shortBrake(){
  isMoving = false;
  digitalWrite(_pinPWM,HIGH);
  digitalWrite(_pinIN1,HIGH);
  digitalWrite(_pinIN2,HIGH);
}
void TB6612::stop(){
  isMoving = false;
  digitalWrite(_pinPWM,HIGH);
  digitalWrite(_pinIN1,LOW);
  digitalWrite(_pinIN2,LOW);
}
