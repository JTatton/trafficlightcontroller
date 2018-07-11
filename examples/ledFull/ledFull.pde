#include "TrafficLightController.h"

LEDLamp* red = new LEDLamp(0);
LEDLamp* amber = new LEDLamp(1)
LEDLamp* green = new LEDLamp(2);

void setup(){} //Noe Required

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