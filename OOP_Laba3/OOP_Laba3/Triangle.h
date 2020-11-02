#pragma once
#include "Figures.h"

class Triangle: public Shape {
public:
	Triangle();
	double getArea(const double* arr) override;
};
