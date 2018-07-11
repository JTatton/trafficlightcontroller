/*
  TrafficLightController.h - Library for controlling Traffic Lights
  Created by Joshua Tatton - June 2018
*/

#ifndef TRAFFICLIGHTCONTROLLER_H
#define TRAFFICLIGHTCONTROLLER_H

#include "Arduino.h"
#include "FastLED.h"

class Lamp{
 public:
  Lamp(int pinNumber);               // Constructor Setup Pin Number
  void setPinNumber(int pinNumber);  // use if the pinNumber needs to change
  virtual void turnOn();             // Turn on Indefinitely
  virtual void turnOff();            // Turn off Indefinitely
  virtual void turnOn(float seconds);// Turn On Lamp for 'seconds' seconds
  bool getStatus();                  // Returns 1 for Lamp is on or 0 if off
  virtual void flip();               // If Lamp is Off, Turn it On & Vice Versa
  virtual void flash(float timeOn, float timeOff, int numRepeats); // Flash light

private:
  int _pinNumber;                   // Stores the pinNumber
  bool _status;                     // Stores whether the light is on 1 or off 0
  int _numLEDs;                     // Stores number of LEDs in ring
  CRGB _leds[];                     // Used for setup of FastLED
};

class LEDLamp : public Lamp {
  LEDLamp(int pinNumber, int numLEDs);  // Constructor Setup Pin Number and Num LEDS
};

#endif //TRAFFICLIGHTCONTROLLER_H