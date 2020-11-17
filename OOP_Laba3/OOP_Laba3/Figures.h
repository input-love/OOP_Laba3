#pragma once
#include "Point.h"
#include "Angle.h"
#include "Rounding.h"
#include "Error.h"

class Shape { 
public:
	Shape(int count);
	virtual ~Shape();
	static Shape* createShape(char T);
	virtual double getArea() = 0;
	Point& getCenterOfGravity() const;
	void rotate(int degrees); 
	void move(const Point& point);
	std::string compare(double area_first, double area_second) const;
	int getNumberOfEdges() const;
	virtual Point& operator [] (int i) const;
protected:
	const int _numberOfEdges;
	Point* _point;
};
