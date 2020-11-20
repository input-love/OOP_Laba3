#pragma once
#include <math.h>
#include "Line.h"
#include "Vector.h"

class Angle {
public:
	static double Radian(int degrees);
	static double findAngle(const Line& first, const Line& second);
};