#include "TrafficLightController.h"

Lamp* red = new Lamp(0);
Lamp* amber = new Lamp(1);
Lamp* green = new Lamp(2);

void setup() {
  // No Setup Required!
  // (it happens above)
}

void loop() {
  //PUT GREEN LIGHT ON 5 Secs
  green->turnOn(5);

  //PUT AMBER ON 2 SECS
  amber->turnOn(2);

  //PUT RED LIGHT ON 5 Secs
  red->turnOn(5);

}
