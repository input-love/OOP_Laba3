#pragma once
#include "Figures.h"
#include "Line.h"
#include "Vector.h"

class Triangle: public Shape {
public:
	Triangle();
	double getArea() override;
};
