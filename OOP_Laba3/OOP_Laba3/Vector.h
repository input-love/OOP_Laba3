#pragma once
#include <cmath>
#include "Line.h"
#include "Point.h"

class Vector {
public:
	Vector() = default;
	static bool intersectOfVectors(const Point& first, const Point& second, const Point& third, const Point& fourth);
	static double findMagnitude(const Line& line);
};