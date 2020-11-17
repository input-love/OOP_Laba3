#pragma once
#include <cmath>
#include "Line.h"
#include "Point.h"

class Vector {
public:
	Vector() = default;
	static bool intersectOfVectors(const Line& line_first, const Line& line_second);
	static double findMagnitude(const Line& line);
};