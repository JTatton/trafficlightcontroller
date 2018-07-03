#include "TrafficLightController.h"

Lamp::Lamp(int pinNumber){
  _pinNumber = pinNumber;
  pinMode(_pinNumber, OUTPUT);         // Set pin to output
  digitalWrite(_pinNumber, HIGH);      // Make sure lamp is off
  _status = 0;
}

void Lamp::setpinNumber(int pinNumber){
  _pinNumber = pinNumber;
}

void Lamp::turnOn(){
  if (_status == 0){
    digitalWrite(_pinNumber, LOW);      // Lamp On
    _status = 1;
  }
}

void Lamp::turnOff(){
  if (_status == 1){
    digitalWrite(_pinNumber, HIGH);
    _status == 0;
  }
}

void Lamp::turnOn(float seconds){
  digitalWrite(_pinNumber, LOW);       // Lamp ON
  _status = 1;
  delay(seconds*1000);                 // Delay
  digitalWrite(_pinNumber, HIGH);      // Lamp OFF
  _status = 0;
}

bool Lamp::getStatus(){
  return _status;
}

void Lanp::flip(){
  if (_status == 0){
    digitalWrite(_pinNumber, LOW);
    _status == 1;
  }
  else{
    digitalWrite(_pinNumber, HIGH);
    _status == 0;
  }
}