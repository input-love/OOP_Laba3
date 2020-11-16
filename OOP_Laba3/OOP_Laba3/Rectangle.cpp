#include "Rectangle.h"

Rectangle::Rectangle(): Shape(4) {}

double Rectangle::getArea() {
	double vector_first = Vector::getVectorLength(_point[0], _point[1]);
	double vector_second = Vector::getVectorLength(_point[1], _point[2]);
	return vector_first * vector_second;
}