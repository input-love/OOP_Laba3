#pragma once
#include <iostream>
#include "Point.h"

class Vector {
public:
	Vector();
	static double getVectorLength(const Point& first, const Point& second);
};