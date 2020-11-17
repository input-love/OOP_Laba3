#pragma once
#include <math.h>
#include "Line.h"
#include "Vector.h"

class Angle {
public:
	Angle() = default;
	static double Radian(int degrees);
	static double findAngle(const Line& first, const Line& second);
};