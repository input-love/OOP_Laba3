#include "Rectangle.h"

Rectangle::Rectangle(): Shape(4) {}

double Rectangle::getArea() {
	return Vector::getVectorLength(_point[0], _point[1]) * 
		Vector::getVectorLength(_point[1], _point[2]);
}