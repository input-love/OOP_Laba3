#pragma once
#include "Figures.h"
#include "Line.h"
#include "Vector.h"
#include "Angle.h"
const double PI = std::acos(-1);

class Operations {
public:
	static bool isIntersect(const Shape& first, const Shape& second);
	static bool isInsertion(const Shape& first, const Shape& second);
};