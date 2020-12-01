#pragma once
#include "Figures.h"

class Rectangle: public Shape {
public:
	Rectangle();
	double getArea() override;
	bool checkFigure() override;
};
