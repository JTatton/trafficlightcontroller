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
  red->flash(0.5,0.5,3);

  //PUT RED LIGHT ON 5 Secs
  red->turnOn(5);

}
