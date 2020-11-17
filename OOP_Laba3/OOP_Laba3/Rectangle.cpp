#include "Rectangle.h"

Rectangle::Rectangle(): Shape(4) {}

double Rectangle::getArea() {
	double result = 1;
	for (int i = 0; i < 2; ++i) {
		Line line(_point[i], _point[i + 1]);
		result *= Vector::findMagnitude(line);
	}
	return result;
}