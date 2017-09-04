#include "vector.h"


Vector::Vector() {
}


Vector::Vector(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}


void Vector::add(const Vector &other) {
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
}


void Vector::div(const double scalar) {
	this->x /= scalar;
	this->y /= scalar;
	this->z /= scalar;
}