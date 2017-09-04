#include "drone_esc.h"


int DroneESC::intensity_to_servo(double intensity) {
	int temp_min = 0, temp_max = 10000;
	int temp, ret;
	
	temp = ((int) round(intensity * (temp_max - temp_min))) + temp_min;
	ret = map(temp, temp_min, temp_max, SERVO_OUTPUT_MIN, SERVO_OUTPUT_MAX);
	
	return ret;
}


void DroneESC::apply_intensity(int16_t direction) {
	int value;
	double intensity;
	
	intensity = intensities[direction];
	value = intensity_to_servo(intensity);
	escs[direction].writeMicroseconds(value);
}


void DroneESC::apply_intensities() {
	int i;
	
	for (i = 0; i < 4; ++i) {
		apply_intensity(i);
	}
}


DroneESC::DroneESC(int16_t pin_nw, int16_t pin_ne, int16_t pin_se, int16_t pin_sw) {
	pins[0] = pin_nw;
	pins[1] = pin_ne;
	pins[2] = pin_se;
	pins[3] = pin_sw;
}


void DroneESC::initialize() {
	int i;
	
	for (i = 0; i < 4; ++i) {
		escs[i].attach(pins[i]);
		set_intensities(INTENSITY_MIN);
	}
}


void DroneESC::set_intensities(double intensity) {
	int i;
	
	for (i = 0; i < 4; ++i) {
		set_intensity(i, intensity);
	}
}


void DroneESC::set_intensity(int16_t direction, double intensity) {
	intensity = min(max(intensity, INTENSITY_MIN), INTENSITY_MAX);
	intensities[direction] = intensity;
	
	apply_intensity(direction);
}


void DroneESC::set_max_intensities() {
	set_intensities(INTENSITY_MAX);
}


void DroneESC::set_min_intensities() {
	set_intensities(INTENSITY_MIN);
}


void DroneESC::set_max_intensity(int16_t direction) {
	set_intensity(direction, INTENSITY_MAX);
}


void DroneESC::set_min_intensities(int16_t direction) {
	set_intensity(direction, INTENSITY_MIN);
}


void DroneESC::change_intensity(int16_t direction, double pcn) {
	double intensity = intensities[direction];
	intensity = intensity * (1 + pcn);
	set_intensity(direction, intensity);
}


void DroneESC::change_intensities(double pcn) {
	int i;
	
	for (i = 0; i < 4; ++i) {
		change_intensity(i, pcn);
	}
}


void DroneESC::set_intensity_linear(int16_t direction, double intensity_before, double intensity_after, int duration) {
	int i, n;
	double delta, intensity;
	
	n = duration / TIME_QUANTUM;
	delta = (intensity_after - intensity_before) / n;
	
	for (i = 0; i < n; ++i) {
		intensity = intensity_before + i * delta;
		set_intensity(direction, intensity);
		delay(TIME_QUANTUM);
	}
}


void DroneESC::set_intensities_linear(double intensity_before, double intensity_after, int duration) {
	int i, n;
	double delta, intensity;
	
	n = duration / TIME_QUANTUM;
	delta = (intensity_after - intensity_before) / n;
	
	for (i = 0; i < n; ++i) {
		intensity = intensity_before + i * delta;
		set_intensities(intensity);
		delay(TIME_QUANTUM);
	}
}


void DroneESC::calibrate() {
	set_max_intensities();
	delay(CALI_MAX_DURATION);
	
	set_min_intensities();
	delay(CALI_MIN_DURATION);
	
	set_intensities_linear(INTENSITY_MIN, INTENSITY_MAX, CALI_GRAD_DURATION);
}