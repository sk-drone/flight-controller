/** A high-level interface for manipulating
  * drone behaviors.
  */

#ifndef H_DRONE
#define H_DRONE

#define PIN_NW 6
#define PIN_NE 9
#define PIN_SE 10
#define PIN_SW 11

#include "common.h"
#include "drone_balancer.h"
#include "drone_esc.h"
#include "speed_controller.h"
#include "gps.h"
#include "accel.h"


class Drone {
private:
	GPSSensor *gps_sensor;
	AccelSensor *accel_sensor;
	DroneBalancer *drone_balancer;
	DroneESC *drone_esc;
	SpeedController *speed_controller;
	
public:
	Drone(GPSSensor *gps_sensor);
	~Drone();
	void initialize();
	void update();
	
	// direct manipulation
	void move_up();
	void move_down();
	void move_left();
	void move_right();
	void move_forward();
	void move_backward();
	void turn_left();
	void turn_right();
};

#endif