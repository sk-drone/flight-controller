#ifndef H_ACCEL
#define H_ACCEL

#define SMOOTH_WINDOW_SIZE 10

#include "MPU6050.h"
#include "vector.h"


class AccelSensor {
public:
	virtual void initialize() = 0;
	virtual void get_accel(Vector *accel) = 0;
	virtual void get_accel_gyro(Vector *accel, Vector *gyro) = 0;
};
 

class SimpleAccelSensor : public AccelSensor {
private:
	MPU6050 sensor;
	
public:
	SimpleAccelSensor();
	void initialize();
	virtual void get_accel(Vector *accel);
	virtual void get_accel_gyro(Vector *accel, Vector *gyro);
};


class SmoothedAccelSensor : public SimpleAccelSensor {
public:
	SmoothedAccelSensor();
	void get_accel(Vector *accel);
	void get_accel_gyro(Vector *accel, Vector *gyro);
};

#endif