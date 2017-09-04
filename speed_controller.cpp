#include "speed_controller.h"


SpeedController::SpeedController(GPSSensor *gps_sensor, DroneBalancer *balancer) {
	this->gps_sensor = gps_sensor;
	this->balancer = balancer;
}
