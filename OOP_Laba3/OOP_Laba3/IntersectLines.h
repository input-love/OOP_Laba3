#pragma once
#include "Point.h"

class IntersectLines {
public:
	IntersectLines ();
	bool checkLines(const Point& first, const Point& second, const Point& third, const Point& fourth);
};
