#include "drone.h"
#include "gps.h"


GPSSensor *gps_sensor;
Drone *drone;

void setup() {
	gps_sensor = new GPSSensor();
	drone = new Drone(gps_sensor);
	
	// gps_sensor.initialize();
	drone->initialize();
}

void loop() {
	drone->update();
}