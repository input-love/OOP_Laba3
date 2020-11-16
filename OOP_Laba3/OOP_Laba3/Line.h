#pragma once
#include "Point.h"

struct Line {
	Line();
	Line(Point _begin, Point _end);
	Point begin;
	Point end;
};