#include "TrafficLightController.h"

Light* red = new Light(0);
Light* green = new Light(1);

void setup() {
  // No Setup Required!
  // (it happens above)
}

void loop() {
  //PUT GREEN LIGHT ON 5 Secs
  green->turnOn(5);

  //FLASH RED LIGHT
  for(int i = 0; i < 3; i++){
    red->turnOn(0.5);
  }

  //PUT RED LIGHT ON 5 Secs
  red->turnOn(5);

}
