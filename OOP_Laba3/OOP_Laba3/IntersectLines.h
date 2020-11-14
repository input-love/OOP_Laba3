#pragma once
#include "Point.h"

class IntersectLines {
public:
	IntersectLines ();
	static bool checkLines(const Point& first, const Point& second, const Point& third, const Point& fourth);
};
