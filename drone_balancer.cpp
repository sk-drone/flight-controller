#include "drone_balancer.h"


DroneBalancer::DroneBalancer(AccelSensor *accel_sensor, DroneESC *drone_esc) {
	this->accel_sensor = accel_sensor;
	this->drone_esc = drone_esc;
}


void DroneBalancer::initialize() {
	// Make sure that the drone is stablized on a horizontal surface
	// to measure the gravity.
	int i, n;
	Vector accel_sum, accel;
	
	n = INIT_DURATION / TIME_QUANTUM;
	
	for (i = 0; i < n; ++i) {
		accel_sensor->get_accel(&accel);
		accel_sum.add(accel);
		delay(TIME_QUANTUM);
	}
	
	accel_sum.div((double)n);
	gravity = accel_sum;
}


void DroneBalancer::set_target(const Vector &target) {
	target_accel = target;
}


void DroneBalancer::balance() {
	// TODO: accel balancer
}