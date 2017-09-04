#ifndef H_CVECTOR
#define H_CVECTOR


class Vector {
public:
	double x, y, z;
	
	Vector();
	Vector(double x, double y, double z);
	void add(const Vector &other);
	void div(const double scalar);
};

#endif