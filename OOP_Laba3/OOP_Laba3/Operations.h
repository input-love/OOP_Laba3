#pragma once
#include "Figures.h"

class Operations {
public:
	Operations() = default;
	bool isIntersect(const Shape& first, const Shape& second);
	int isInsertion(const Shape& first, const Shape& second);
private:
	bool intersectLines(const Point& first, const Point& second, const Point& third, const Point& fourth);
	int getMostLeftCoord(const Shape& first, const Shape& second);
	int getMostRightCoord(const Shape& first, const Shape& second);
};