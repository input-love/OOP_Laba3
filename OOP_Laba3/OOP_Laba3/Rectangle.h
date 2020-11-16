#pragma once
#include "Figures.h"
#include "Vector.h"

class Rectangle: public Shape {
public:
	Rectangle();
	double getArea() override;
};
