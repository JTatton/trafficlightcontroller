#include "TrafficLightController.h"

Lamp* red = new Lamp(0);
Lamp* green = new Lamp(1);

void setup() {
  // No Setup Required!
  // (it happens above)
}

void loop() {
  //PUT GREEN LIGHT ON 5 Secs
  green->turnOn(5);

  //FLASH RED LIGHT
  red->flash(0.5,0.5,3);

  //PUT RED LIGHT ON 5 Secs
  red->turnOn(5);

}
