/** A wrapper class for dealing with ESCs.
  * Comes with calibration function.
  */
  
#ifndef H_DRONE_ESC
#define H_DRONE_ESC

#define SERVO_OUTPUT_MAX 1000
#define SERVO_OUTPUT_MIN 2000
#define INTENSITY_MAX 1.0
#define INTENSITY_MIN 0.0
#define CALI_MAX_DURATION 2000
#define CALI_MIN_DURATION 2000
#define CALI_GRAD_DURATION 2000

#include <Servo.h>
#include "common.h"


class DroneESC {
private:
	static const int16_t ESC_NW = 0;
	static const int16_t ESC_NE = 1;
	static const int16_t ESC_SE = 2;
	static const int16_t ESC_SW = 3;
	
	Servo escs[4];
	int16_t pins[4];
	double intensities[4];
	
	static int intensity_to_servo(double intensity);
	void apply_intensities();
	void apply_intensity(int16_t direction);
public:
	DroneESC(int16_t pin_nw, int16_t pin_ne, int16_t pin_se, int16_t pin_sw);
	void set_intensities(double intensity);
	void set_intensity(int16_t direction, double intensity);
	void set_max_intensities();
	void set_min_intensities();
	void set_max_intensity(int16_t direction);
	void set_min_intensities(int16_t direction);
	void change_intensity(int16_t direction, double pcn);
	void change_intensities(double pcn);
	void set_intensity_linear(int16_t direction, double intensity_before, double intensity_after, int duration);
	void set_intensities_linear(double intensity_before, double intensity_after, int duration);
	void initialize();
	void calibrate();
};

#endif