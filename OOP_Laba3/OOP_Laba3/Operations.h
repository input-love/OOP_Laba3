#pragma once
#include "Figures.h"
#include "Line.h"
#include "Angle.h"
#define PI 3.1415926535

class Operations {
public:
	Operations() = default;
	static bool isIntersect(const Shape& first, const Shape& second);
	static bool isInsertion(const Shape& first, const Shape& second);
};