#pragma once
#include "Figures.h"

class Rectangle: public Shape {
public:
	Rectangle();
	double getArea(const double* arr) override;
};
