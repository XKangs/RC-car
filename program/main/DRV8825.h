#ifndef DRV8825_h
#define DRV8825_h

#include "Arduino.h"

class DRV8825{
public:
	enum Direction
	{
		clockwise,
		anti_clockwise
	};
  DRV8825(uint8_t pinDirection, uint8_t pinStep, uint8_t pinSleep,uint8_t pinFault, uint8_t pinReset);
  void rotate(uint8_t steps = 1, Direction dir = Direction::clockwise);
  void sleep();
  void enable();
  void reset();
  bool isFault();
  bool isSleeping;
private:
	uint8_t _pinDir;
	uint8_t _pinStep;
	uint8_t _pinSleep;
	uint8_t _pinFault;
  uint8_t _pinReset;
};

#endif
