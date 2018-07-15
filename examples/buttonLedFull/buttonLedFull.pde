#include "TrafficLightController.h"

#define NUM_LIGHTS 3
#define NUM_LEDS_PER_LIGHT 12

#define RED_PIN 0
#define AMBER_PIN 1
#define GREEN_PIN 2

#define BUTTON_PIN 4

CRGB leds[NUM_LIGHTS][NUM_LEDS_PER_LIGHT];

LEDLamp red(leds[0], NUM_LEDS_PER_LIGHT);
LEDLamp amber(leds[1], NUM_LEDS_PER_LIGHT);
LEDLamp green(leds[2], NUM_LEDS_PER_LIGHT);

void broken();
void english();
void aussie();
void random();
void allOn();

void setup(){
  FastLED.addLeds<WS2812, RED_PIN, GRB>(leds[0], NUM_LEDS_PER_LIGHT);
  FastLED.addLeds<WS2812, AMBER_PIN, GRB>(leds[1], NUM_LEDS_PER_LIGHT);
  FastLED.addLeds<WS2812, GREEN_PIN, GRB>(leds[2], NUM_LEDS_PER_LIGHT);

  red.turnOff();
  amber.turnOff();
  green.turnOff();

  pinMode(BUTTON_PIN, INPUT);

  delay(2000);
}

void loop(){

	// IF BUTTON IS PRESSED ON STARTUP - FLASH AMBER
	if(digitalRead(BUTTON_PIN) == LOW){
		broken();
	}

	int buttonState = 0;

	if (buttonState % 5 == 0)
	{
		/* code */
	}

}