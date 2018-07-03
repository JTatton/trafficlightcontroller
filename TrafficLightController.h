/*
  TrafficLightController.h - Library for controlling Traffic Lights
  Created by Joshua Tatton - June 2018
*/

#ifndef LAMP_H
#define LAMP_H

#include "Arduino.h"

class Lamp{
 public:
  Lamp(int pinNumber);              // Constructor Setup Pin Number
  void setpinNumber(int pinNumber); // use if the pinNumber needs to change
  void turnOn();                    // Turn on Indefnitely
  void turnOff();                   // Turn off Indefinitely
  void turnOn(float seconds);       // Turn On Lamp for 'seconds' seconds
  bool getStatus();                 // Returns 1 for Lamp is on or 0 if off
  void flip();                      // If Lamp is Off, Turn it On & Vice Versa
private:
  int _pinNumber;                   // Stores the pinNumber
  bool _status;                     // Stores whether the light is on 1 or off 0
};

#endif //LAMP_H