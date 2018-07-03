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

void Lamp::turnOn(float seconds){
  digitalWrite(_pinNumber, LOW);       // Lamp ON
  _status = 1;
  delay(seconds*1000);                // Delay
  digitalWrite(_pinNumber, HIGH);      // Lamp OFF
  _status = 0;
}

bool Lamp::getStatus(){
  return _status;
}