#ifndef H_SPEED_CONTROLLER
#define H_SPEED_CONTROLLER

#include "common.h"
#include "drone_balancer.h"
#include "gps.h"

class SpeedController {
private:
	DroneBalancer *balancer;
	GPSSensor *gps_sensor;
	
public:
	SpeedController(GPSSensor *gps_sensor, DroneBalancer *balancer);
};

#endif
