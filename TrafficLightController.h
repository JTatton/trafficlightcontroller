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
  Lamp(uint8_t pinNumber);               // Constructor Setup Pin Number
  void setPinNumber(uint8_t pinNumber);  // use if the pinNumber needs to change
  virtual void turnOn();             // Turn on Indefinitely
  virtual void turnOff();            // Turn off Indefinitely
  virtual void turnOn(float seconds);// Turn On Lamp for 'seconds' seconds
  bool getStatus();                  // Returns 1 for Lamp is on or 0 if off
  virtual void flip();               // If Lamp is Off, Turn it On & Vice Versa
  virtual void flash(float timeOn, float timeOff, uint8_t numRepeats); // Flash light

protected:
  uint8_t _pinNumber;                   // Stores the pinNumber
  bool _status;                     // Stores whether the light is on 1 or off 0

};

class LEDLamp : public Lamp {
  public:
    LEDLamp(CRGB* leds, uint8_t numLEDs);  // Constructor Setup Pin Number and Num LEDS
    virtual void turnOn();             // Turn on Indefinitely
    virtual void turnOff();            // Turn off Indefinitely
    virtual void turnOn(float seconds);// Turn On Lamp for 'seconds' seconds
    virtual void flip();               // If Lamp is Off, Turn it On & Vice Versa
    virtual void flash(float timeOn, float timeOff, uint8_t numRepeats); // Flash light

  private:
    uint8_t _numLEDs;
    CRGB* _leds;
};

#endif //TRAFFICLIGHTCONTROLLER_H