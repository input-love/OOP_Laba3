#pragma once
#include <cmath>
#include <algorithm>
#include "Line.h"
#include "Point.h"

class Vector {
public:
	static bool isIntersectLines(const Line& line_first, const Line& line_second);
	static double findMagnitude(const Line& line);
private:
	static double pointCheck(double a, double b, double c, double d);
	static bool intersectVector(double a, double b, double c, double d);
	static bool compare(double a, double b, double c);
};