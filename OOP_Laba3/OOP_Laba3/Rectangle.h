#pragma once
#include "Figures.h"
#include "Line.h"
#include "Vector.h"

class Rectangle: public Shape {
public:
	Rectangle();
	double getArea() override;
};
