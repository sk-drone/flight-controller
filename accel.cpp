#include "accel.h"


SimpleAccelSensor::SimpleAccelSensor() {
}


void SimpleAccelSensor::initialize() {
	sensor.initialize();
}


void SimpleAccelSensor::get_accel_gyro(Vector *accel, Vector *gyro) {
	int16_t ax, ay ,az;
	int16_t gx, gy, gz;
	
	sensor.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
	accel->x = (double)ax;
	accel->y = (double)ay;
	accel->z = (double)az;
	gyro->x = (double)gx;
	gyro->y = (double)gy;
	gyro->z = (double)gz;
}


void SimpleAccelSensor::get_accel(Vector *accel) {
	int16_t ax, ay ,az;
	int16_t gx, gy, gz;
	
	sensor.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
	accel->x = (double)ax;
	accel->y = (double)ay;
	accel->z = (double)az;
}


SmoothedAccelSensor::SmoothedAccelSensor() : SimpleAccelSensor() {
}


void SmoothedAccelSensor::get_accel_gyro(Vector *accel, Vector *gyro) {
	// TODO: smoothed accel gyro sensor data
	// use `base::get_accel_gyro` to AccelSensor's method
}


void SmoothedAccelSensor::get_accel(Vector *accel) {
	// TODO: smoothed accel gyro sensor data
	// use `base::get_accel_gyro` to AccelSensor's method
}