#include "TrafficLightController.h"

/*
 *    SIMPLE IMPLEMENTATION BELOW
 */

Lamp::Lamp(int pinNumber){
  _pinNumber = pinNumber;
  pinMode(_pinNumber, OUTPUT);         // Set pin to output
  digitalWrite(_pinNumber, HIGH);      // Make sure lamp is off
  _status = 0;
}

void Lamp::setPinNumber(int pinNumber){
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

void Lamp::flip(){
  if (_status == 0){
    digitalWrite(_pinNumber, LOW);
    _status == 1;
  }
  else{
    digitalWrite(_pinNumber, HIGH);
    _status == 0;
  }
}

void Lamp::flash(float timeOn, float timeOff, int numRepeats){
  for (int i = 0; i < numRepeats; i++){
    digitalWrite(_pinNumber, LOW);
    _status = 1;
    delay(timeOn*1000);
    digitalWrite(_pinNumber, HIGH);
    _status = 0;
    delay(timeOff*1000);
  }
}

/*
 *    LED IMPLEMENTATION BELOW
 */

LEDLamp::LEDLamp(int pinNumber, int numLEDs){
  _pinNumber = pinNumber;
  _numLEDs = numLEDs;

  CRGB temp[_numLEDs];
  _leds = temp;

  FastLED.addLeds<WS2811, _pinNumber, GRB>(_leds, _numLEDs);
}