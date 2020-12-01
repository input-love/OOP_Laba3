#pragma once
#include "Figures.h"
#include "Triangle.h"
#include "Rectangle.h"

class ShapeFactory {
public :
	Shape* createShape(char T);
};