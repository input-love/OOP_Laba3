#include "Angle.h"

double Angle::radian(int degrees) {
	double result = (degrees * 2.0 * std::asin(1)) / 180;
	return result;
}

double Angle::findAngle(const Line& first, const Line& second) {
    Point vector_first(first.end.x - first.begin.x, first.end.y - first.begin.y);
    Point vector_second(second.end.x - second.begin.x, second.end.y - second.begin.y);

    double scalar = vector_first.x * vector_second.x + vector_first.y * vector_second.y;

    double magnitude_first = Vector::findMagnitude(first);
    double magnitude_second = Vector::findMagnitude(second);

    return std::acos(scalar / (magnitude_first * magnitude_second));
}