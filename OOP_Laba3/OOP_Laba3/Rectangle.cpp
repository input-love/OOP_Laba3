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

bool Rectangle::checkFigure() {
	Line line_first(_point[0], _point[1]);
	Line line_second(_point[1], _point[2]);
	Line line_third(_point[2], _point[3]);
	Line line_fourth(_point[3], _point[0]);

	return Vector::findMagnitude(line_first) == Vector::findMagnitude(line_third)
		&& Vector::findMagnitude(line_second) == Vector::findMagnitude(line_fourth);
}