#pragma once
#include <stdexcept>
#include <string>
#include "Point.h"
#include "Angle.h"
#include "Vector.h"

class Shape { 
public:
	Shape(int count);
	virtual ~Shape();
	virtual double getArea() = 0;
	Point getCenterOfGravity() const;
	void rotate(int degrees); 
	void move(const Point& point);
	int getNumberOfEdges() const;
	Point& operator [] (int i) const;
protected:
	const int _numberOfEdges;
	Point* _point;
};
