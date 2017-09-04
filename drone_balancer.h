#ifndef H_DRONE_BALANCER
#define H_DRONE_BALANCER

#define INIT_DURATION 2000
#define ACCEL_SENSITIVITY 100

#include "drone_esc.h"
#include "accel.h"
#include "common.h"
#include "vector.h"


class DroneBalancer {
private:
	Vector gravity;
	Vector target_accel;
	DroneESC *drone_esc;
	AccelSensor *accel_sensor;
	
public:
	DroneBalancer(AccelSensor *accel_sensor, DroneESC *drone_esc);
	void initialize();
	void set_target(const Vector &target);
	void balance();
};

#endif
