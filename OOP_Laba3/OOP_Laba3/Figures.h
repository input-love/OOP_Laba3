#pragma once
#include <iostream>
#include "Point.h"
#include "Vector.h"
#include "Radian.h"
#include "Rounding.h"
#include "Operations.h"
#include "Error.h"

class Shape { 
public:
	Shape(int count);
	virtual ~Shape();
	static Shape* createShape(char T); 
	virtual double getArea() = 0;
	Point getCenterOfGravity() const;
	void rotate(int degrees); 
	void move(const Point& point);
	bool compare(double area_first, double area_second);
	int getNumberOfEdges() const;
	virtual Point& operator [] (int i) const;
protected:
	const int _numberOfEdges;
	Point* _point;
};
