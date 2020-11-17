#pragma once
#include "Point.h"

struct Line {
	Line();
	Line(Point begin, Point end);
	Point begin;
	Point end;
};