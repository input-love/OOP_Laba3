#pragma once
#include "Figures.h"

class Operations {
public:
	Operations() = default;
	bool isIntersect(const Shape& first, const Shape& second) const;
	std::string isInsertion(const Shape& first, const Shape& second) const;
private:
	bool intersectLines(const Point& first, const Point& second, const Point& third, const Point& fourth) const;
	std::string getMostLeftCoord(const Shape& first, const Shape& second) const;
	std::string getMostRightCoord(const Shape& first, const Shape& second) const;
};