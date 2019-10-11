#include "DRV8825.h"
DRV8825::DRV8825(uint8_t pinDirection, uint8_t pinStep, uint8_t pinSleep,uint8_t pinFault, uint8_t pinReset){
	_pinDir = pinDirection;
	_pinStep = pinStep;
	_pinSleep = pinSleep;
	_pinFault = pinFault;
	_pinReset = pinReset;

	pinMode(_pinDir,OUTPUT);
	pinMode(_pinStep,OUTPUT);
	pinMode(_pinSleep,OUTPUT);
	pinMode(_pinReset,OUTPUT);

	pinMode(_pinFault,INPUT);

	this->enable();

}
void DRV8825::rotate(uint8_t steps = 1, Direction dir = Direction::clockwise){
	digitalWrite(_pinDir, dir);
	for(int i = 0; i < steps; i++)
	{
		digitalWrite(_pinStep, HIGH);
		delayMicroseconds(2000);
		digitalWrite(_pinStep, LOW);
		delayMicroseconds(2000);
	}
}
void DRV8825::sleep(){
  isSleeping = true;
  digitalWrite(_pinSleep, LOW);
}
void DRV8825::enable(){
  isSleeping = false;
  digitalWrite(_pinSleep, HIGH);
}
void DRV8825::reset(){
  digitalWrite(_pinReset, LOW);
  delay(50);
  digitalWrite(_pinReset, HIGH);
}
bool DRV8825::isFault(){
  return !digitalRead(_pinFault);
}
