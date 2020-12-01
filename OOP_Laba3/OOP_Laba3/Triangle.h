#pragma once
#include "Figures.h"

class Triangle: public Shape {
public:
	Triangle();
	double getArea() override;
	bool checkFigure() override;
};
