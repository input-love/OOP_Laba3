#pragma once
#include "Point.h"
#include "Error.h"

class Shape { 
public:
	Shape(int count);
	virtual ~Shape();
	static Shape* createShape(char T); 
	virtual double getArea(const double* arr) = 0;
	int getNumberOfEdges();
	virtual Point& operator [] (int i) const;
private:
	const int _numberOfEdges;
	Point* _point = nullptr;
};
