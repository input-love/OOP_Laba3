#include "Rectangle.h"

Rectangle::Rectangle(): Shape(4) {}

double Rectangle::getArea() {
	Vector vector;
	return vector.getVectorLength(_point[0], _point[1]) * vector.getVectorLength(_point[1], _point[2]);
}