#include "Vector.h"

bool Vector::isIntersectLines(const Line& line_first, const Line& line_second) {
	double A1 = line_first.begin.y - line_first.end.y, B1 = line_first.end.x - line_first.begin.x, C1 = -A1 * line_first.begin.x - B1 * line_first.begin.y;
	double A2 = line_second.begin.y - line_second.end.y, B2 = line_second.end.x - line_second.begin.x, C2 = -A2 * line_second.begin.x - B2 * line_second.begin.y;
	double result = Vector::pointCheck(A1, B1, A2, B2);
	if (result) {
		double x = -pointCheck(C1, B1, C2, B2) * 1.0 / result;
		double y = -pointCheck(A1, C1, A2, C2) * 1.0 / result;
		return Vector::compare(line_first.begin.x, line_first.end.x, x) && Vector::compare(line_first.begin.y, line_first.end.y, y)
			&& Vector::compare(line_second.begin.x, line_second.end.x, x) && Vector::compare(line_second.begin.y, line_second.end.y, y);
	} else {
		return !pointCheck(A1, C1, A2, C2) && !pointCheck(B1, C1, B2, C2)
			&& Vector::intersectVector(line_first.begin.x, line_first.end.x, line_second.begin.x, line_second.end.x)
			&& Vector::intersectVector(line_first.begin.y, line_first.end.y, line_second.begin.y, line_second.end.y);
	}
}

double Vector::findMagnitude(const Line& line) {
	double x = std::abs(line.end.x - line.begin.x);
	double y = std::abs(line.end.y - line.begin.y);
	return sqrt(pow(x, 2) + pow(y, 2));
}

double Vector::pointCheck(double a, double b, double c, double d) {
	return a * d - b * c;
}

bool Vector::intersectVector(double a, double b, double c, double d) {
	if (a > b) { std::swap(a, b); }
	if (c > d) { std::swap(c, d); }
	return std::max(a, c) <= std::min(b, d);
}

bool Vector::compare(double a, double b, double c) {
	return std::min(a, b) <= c + 1E-9 && c <= std::max(a, b) + 1E-9;
}