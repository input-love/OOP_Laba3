#include "Triangle.h"

Triangle::Triangle(): Shape(3) {}

double Triangle::getArea() {
	Line line_first(_point[0], _point[1]);
	Line line_second(_point[1], _point[2]);
	Line line_third(_point[2], _point[0]);

	double a = Vector::findMagnitude(line_first);
	double b = Vector::findMagnitude(line_second);
	double c = Vector::findMagnitude(line_third);

	double p = (a + b + c) / 2.0;

	return sqrt(p * (p - a) * (p - b) * (p - c));
}