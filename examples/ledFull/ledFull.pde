#include "TrafficLightController.h"

#define NUM_LIGHTS 3
#define NUM_LEDS_PER_LIGHT 12

#define RED_PIN 0
#define AMBER_PIN 1
#define GREEN_PIN 2

CRGB leds[NUM_LIGHTS][NUM_LEDS_PER_LIGHT];

LEDLamp red(leds[0], NUM_LEDS_PER_LIGHT);
LEDLamp amber(leds[1], NUM_LEDS_PER_LIGHT);
LEDLamp green(leds[2], NUM_LEDS_PER_LIGHT);

void setup(){
  FastLED.addLeds<WS2812, RED_PIN, GRB>(leds[0], NUM_LEDS_PER_LIGHT);
  FastLED.addLeds<WS2812, AMBER_PIN, GRB>(leds[1], NUM_LEDS_PER_LIGHT);
  FastLED.addLeds<WS2812, GREEN_PIN, GRB>(leds[2], NUM_LEDS_PER_LIGHT);

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