#include <Servo.h>
#include "TB6612.h"

#define BTStatus 6


Servo _servo;  // create servo object to control a servo
TB6612 _motor(5, 3, 4, 10);
char buffer [32];
int cnt = 0;
boolean ready = false;
boolean isBTConnected = false;

void setup() {
  Serial.begin(9600);
  _servo.attach(9);
  _motor.sleep();

}

void loop()
{
  if (digitalRead(BTStatus) == HIGH) {
    isBTConnected = true;
    if(_motor.isSleeping){
      _motor.enable();
    }
  } else {
    isBTConnected = false;
    if(!_motor.isSleeping){
      _motor.sleep();
    }
    
  }
  if (ready)
  {
    ParseLine();
    ready = false;
  } else {
    while (Serial.available()) {
      char c = Serial.read();
      buffer[cnt++] = c;
      if ((c == '\n') || (cnt == sizeof(buffer) - 1))
      {
        buffer[cnt] = '\0';
        cnt = 0;
        ready = true;
      }
    }
  }
}

void ParseLine() {
  if (!isBTConnected) {
    return;
  }
  char str[3] = {""};
  strncpy(str, buffer + 0, 2);
  int steering = atoi(str);
  Serial.print("steering:");
  Serial.println(steering);
  _servo.write(steering);

  char the[3] = {""};
  strncpy(the, buffer + 4, 2);
  int throttle = atoi(the) * 10 * 255 / 100;
  Serial.print(throttle);

  switch (buffer[3]) {
    case 'f': {
        Serial.println("forward");
        _motor.forward(throttle);
        break;
      }
    case 'b': {
        Serial.println("backward");
        _motor.backward(throttle);
        break;
      }
    case 'n':
    default: {
        Serial.println("stop");
        _motor.stop();
        break;
      }
  }
}
