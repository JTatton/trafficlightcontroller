#include "TrafficLightController.h"

#define NUM_LIGHTS 3
#define NUM_LEDS_PER_LIGHT 12

#define RED_PIN 0
#define AMBER_PIN 1
#define GREEN_PIN 2

CRGB leds[NUM_LIGHTS][NUM_LEDS_PER_LIGHT];

LEDLamp* red = new LEDLamp(leds[0], NUM_LEDS_PER_LIGHT);
LEDLamp* amber = new LEDLamp(leds[1], NUM_LEDS_PER_LIGHT);
LEDLamp* green = new LEDLamp(leds[2], NUM_LEDS_PER_LIGHT);

void setup(){
  FastLED.addLeds<WS2811, RED_PIN, RGB>(leds[0], NUM_LEDS_PER_LIGHT);
  FastLED.addLeds<WS2811, AMBER_PIN, RGB>(leds[1], NUM_LEDS_PER_LIGHT);
  FastLED.addLeds<WS2811, GREEN_PIN, RGB>(leds[2], NUM_LEDS_PER_LIGHT);
}

void loop(){
	// GREEN
	green -> turnOn(5);

	// AMBER
	amber -> turnOn(2.5);

	// RED
	red -> turnOn(5);

	// RED AMBER
	red -> turnOn();
	amber -> turnOn(2.5);
	red -> turnOff();
}