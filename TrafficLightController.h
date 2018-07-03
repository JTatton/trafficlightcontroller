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
  void turnOn(float seconds);       // Turn On Lamp for 'seconds' seconds
private:
  int pinNumber;                    // Stores the pinNumber
};

#endif //LAMP_H