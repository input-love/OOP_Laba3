#pragma once
#include <cmath>
#include "Point.h"

class Vector {
public:
	Vector() = default;
	static double getVectorLength(const Point& first, const Point& second);
};