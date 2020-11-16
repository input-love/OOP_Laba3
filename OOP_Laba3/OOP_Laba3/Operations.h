#pragma once
#include "Figures.h"
#include "Line.h"
#define PI 3.1415926535

class Operations {
public:
	Operations() = default;
	bool isIntersect(const Shape& first, const Shape& second) const;
	bool isInsertion(const Shape& first, const Shape& second) const;
private:
	bool intersectLines(const Point& first, const Point& second, const Point& third, const Point& fourth) const;
	double findMagnitude(const Line& line) const;
	double findAngle(const Line& first, const Line& second) const;
};