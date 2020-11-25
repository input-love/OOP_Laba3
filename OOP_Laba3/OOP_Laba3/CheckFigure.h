#pragma once
#include <stdexcept>
#include "Figures.h"

class CheckFigure {
public:
	static bool check(char T, const Shape& figure);
};