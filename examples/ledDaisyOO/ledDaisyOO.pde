#include "TrafficLightController.h"

#define NUM_LEDS 36
#define NUM_LEDS_PER_LIGHT 12

#define PIN 0

CRGB leds[NUM_LEDS];

LEDLamp red(leds, NUM_LEDS_PER_LIGHT, 0);
LEDLamp amber(leds, NUM_LEDS_PER_LIGHT, 12);
LEDLamp green(leds, NUM_LEDS_PER_LIGHT, 24);

void setup(){
  FastLED.addLeds<WS2812, PIN, GRB>(leds, NUM_LEDS);

  red.turnOff();
  amber.turnOff();
  green.turnOff();

  delay(2000);
}

void loop(){
  // GREEN
  green.turnOn(5);

  // AMBER
  amber.turnOn(5);

  // RED
  red.turnOn(5);

  // RED AMBER
  red.turnOn();
  amber.turnOn(5);
  red.turnOff();
}
