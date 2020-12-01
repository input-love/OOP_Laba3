#pragma once
#include "Point.h"

struct Line {
	Line();
	Line(const Point& begin, const Point& end);
	Point begin;
	Point end;
};