#include "Angle.h"

double Angle::Radian(int degrees) {
	double result = (degrees * 2 * asin(1)) / 180;
	return result;
}

double Angle::findAngle(const Line& first, const Line& second) {
    Point vector_first(first.end.x - first.begin.x, first.end.y - first.begin.y);
    Point vector_second(second.end.x - second.begin.x, second.end.y - second.begin.y);

    double scalar = vector_first.x * vector_second.x + vector_first.y * vector_second.y;

    double magnitude1 = Vector::findMagnitude(first);
    double magnitude2 = Vector::findMagnitude(second);

    return acos(scalar / (magnitude1 * magnitude2));
}