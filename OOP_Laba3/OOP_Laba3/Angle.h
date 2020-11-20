#pragma once
#include "Line.h"
#include "Vector.h"

class Angle {
public:
	static double radian(int degrees);
	static double findAngle(const Line& first, const Line& second);
};