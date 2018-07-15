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

void broken();    // Flash Amber Light for 5 Seconds
void english();   // Red -> Red/Amber -> Green -> Amber
void aussie();    // Red -> Green -> Amber
void upAndDown(); // Red -> Amber -> Green -> Amber
void randomFlash();    // Random Flashing
void allOn();     // All lights on

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

  if (buttonState % 5 == 0){
    english();
  }
  else if (buttonState % 5 == 1){
    aussie();
  }
  else if (buttonState % 5 == 2){
    upAndDown();
  }
  else if (buttonState % 5 == 3){
    randomFlash();
  }
  else if (buttonState % 5 == 4){
    allOn();
  }
  else{
    red.turnOn();
    green.turnOn(5);
    red.turnOff();
  }

}

void broken(){
  amber.flash(1,1,5);
}

void english(){
  // RED
  red.turnOn();
  delay(5000);

  // RED AMBER
  amber.turnOn(2.5);
  red.turnOff();

  // GREEN
  green.turnOn(5);

  // AMBER
  amber.turnOn(2.5);
}

void aussie(){
  // RED
  red.turnOn(5);

  // GREEN
  green.turnOn(5);

  // AMBER
  amber.turnOn(2.5);
}

void upAndDown(){
  red.turnOn(1);

  amber.turnOn(1);

  green.turnOn(1);

  amber.turnOn(1);
}

void randomFlash(){
  int randomNum;

  for (int i = 0; i < 10; i++){
    randomNum = random(1,100);

    if (randomNum < 33){
      red.turnOn(1);
    }
    else if (randomNum >= 33 && randomNum < 67){
      amber.turnOn(1);
    }
    else{
      green.turnOn(1);
    }
  }

}

void allOn(){
  // ALL On 10 Secs
  red.turnOn();
  amber.turnOn();
  green.turnOn(10);
  red.turnOff();
  amber.turnOff();
}