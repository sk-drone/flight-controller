#include "drone.h"
#include <Servo.h>


Drone::Drone(GPSSensor *gps_sensor) {
	this->gps_sensor = gps_sensor;
	accel_sensor = new SmoothedAccelSensor();
	drone_esc = new DroneESC(PIN_NW, PIN_NE, PIN_SE, PIN_SW);
	drone_balancer = new DroneBalancer(accel_sensor, drone_esc);
	speed_controller = new SpeedController(gps_sensor, drone_balancer);
}


Drone::~Drone() {
	delete gps_sensor;
	delete accel_sensor;
	delete drone_balancer;
	delete drone_esc;
	delete speed_controller;
}


void Drone::initialize() {
	// gps_sensor->initialize();
	accel_sensor->initialize();
	drone_esc->initialize();
	drone_balancer->initialize();
	// speed_controller->initialize();
}


void Drone::update() {
	drone_balancer->balance();
	// speed_controller->update();
}