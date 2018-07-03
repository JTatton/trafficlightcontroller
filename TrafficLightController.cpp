#include "TrafficLightController.h"

Lamp::Lamp(int pinNumber){
  Lamp::pinNumber = pinNumber;
  pinMode(pinNumber, OUTPUT);         // Set pin to output
  digitalWrite(pinNumber, HIGH);      // Make sure lamp is off
}

void Lamp::void setpinNumber(int pinNumber){
  Lamp::pinNumber = pinNumber;
}

void Lamp::turnOn(float seconds){
  digitalWrite(pinNumber, LOW);       // Lamp ON
  delay(seconds*1000);                // Delay
  digitalWrite(pinNumber, HIGH);      // Lamp OFF
}