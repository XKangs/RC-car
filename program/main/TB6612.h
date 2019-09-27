#ifndef TB6612_h
#define TB6612_h

#include "Arduino.h"

class TB6612{
public:
    TB6612(uint8_t pinPWM, uint8_t pinIN1, uint8_t pinIN2, uint8_t pinSTBY);
    void forward(uint8_t speed = 225);
    void backward(uint8_t speed = 225);
    void forward();
    void backward();
    void enable();
    void disable();
    void shortBrake();
    void stop();
    bool isEnable;
	bool isMoving;
private:
	uint8_t _pinPWM;
	uint8_t _pinIN1;
	uint8_t _pinIN2;
	uint8_t _pinSTBY;
};

#endif
