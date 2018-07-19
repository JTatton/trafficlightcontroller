#include "TrafficLightController.h"

/*
 *    SIMPLE IMPLEMENTATION BELOW
 */

Lamp::Lamp(byte pinNumber){
  _pinNumber = pinNumber;
  pinMode(_pinNumber, OUTPUT);         // Set pin to output
  digitalWrite(_pinNumber, HIGH);      // Make sure lamp is off
  _status = 0;
}

void Lamp::setPinNumber(byte pinNumber){
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

void Lamp::flash(float timeOn, float timeOff, byte numRepeats){
  for (byte i = 0; i < numRepeats; i++){
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

LEDLamp::LEDLamp(CRGB* leds, byte numLEDs) : Lamp(-1){
  _numLEDs = numLEDs;
  _leds = leds;
}

void LEDLamp::turnOn(){
  _status = 1;
  for (byte i = 0; i < _numLEDs; i++){   //Set all LEDs in Ring to White
    *(_leds+i) = CRGB::White;
  }
  FastLED.show();
}

void LEDLamp::turnOff(){
  _status = 0;
  for (byte i = 0; i < _numLEDs; i++)  //Set all LEDs in Ring to Black
  {
    *(_leds+i) = CRGB::Black;
  }
  FastLED.show();
}

void LEDLamp::turnOn(float seconds){
  _status = 1;
  for (byte i = 0; i < _numLEDs; i++){   //Set all LEDs in Ring to White
    *(_leds+i) = CRGB::White;
  }
  FastLED.show();

  delay(seconds * 1000);

  _status = 0;
  for (byte i = 0; i < _numLEDs; i++){  //Set all LEDs in Ring to Black
    *(_leds+i) = CRGB::Black;
  }
  FastLED.show();
}

void LEDLamp::flip(){
  if (_status == 1){
    _status = 0;
    for (byte i = 0; i < _numLEDs; i++)  //Set all LEDs in Ring to Black
    {
      *(_leds+i) = CRGB::Black;
    }
    FastLED.show();
  }
  else{
    _status = 1;
    for (byte i = 0; i < _numLEDs; i++){   //Set all LEDs in Ring to White
      *(_leds+i) = CRGB::White;
    }
    FastLED.show();
  }
}

void LEDLamp::flash(float timeOn, float timeOff, byte numRepeats){
  for (byte j = 0; j < numRepeats; j++)
  {
    for (byte i = 0; i < _numLEDs; ++i)
    {
      *(_leds+i) = CRGB::White;
    }
    _status = 1;
    FastLED.show();
    delay(timeOn*1000);

    for (byte i = 0; i < _numLEDs; ++i)
    {
      *(_leds+i) = CRGB::Black;
    }
    _status = 0;
    FastLED.show();
    delay(timeOff*1000);
  }
}