#include "Triangle.h"

Triangle::Triangle(): Shape(3) {}

double Triangle::getArea() {
	double a = Vector::getVectorLength(_point[0], _point[1]);
	double b = Vector::getVectorLength(_point[1], _point[2]);
	double c = Vector::getVectorLength(_point[2], _point[0]);
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}