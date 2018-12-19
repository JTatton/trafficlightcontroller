#include "FastLED.h"

#define NUM_LEDS_TOTAL 36

#define PIN 0

CRGB trafficLight[NUM_LEDS_TOTAL];


void redOn(){
    for(int i = 0; i < 12; i++)
    {
        trafficLight[i] = CRGB::White;
    }
    FastLED.show();  
}
void amberOn(){
    for(int i = 12; i < 24; i++)
    {
        trafficLight[i] = CRGB::White;
    }  
    FastLED.show();  
}
void greenOn(){
    for(int i = 24; i < 36; i++)
    {
        trafficLight[i] = CRGB::White;
    }  
    FastLED.show();  
}
void turnOff(){
    for(int i = 0; i < 36; i++)
    {
        trafficLight[i] = CRGB::Black;
    }
    FastLED.show();  
}

void setup(){
  FastLED.addLeds<WS2812, PIN, GRB>(trafficLight, 36);

  turnOff();

  delay(2000);
}

void loop(){
	greenOn();
    delay(5000);
    turnOff();

    amberOn();
    delay(2500);
    turnOff();

    redOn();
    delay(2500);
    amberOn();
    delay(1500);
    turnOff();
    
}
