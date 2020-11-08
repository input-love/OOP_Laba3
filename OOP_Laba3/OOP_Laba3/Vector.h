#pragma once
#include <iostream>
#include "Point.h"

class Vector {
public:
	Vector();
	double getVectorLength(const Point& first, const Point& second) const;
};