#pragma once
#include "Point.h"
#include "Vector.h"
#include "Error.h"
using std::string;

class Shape { 
public:
	Shape(int count);
	virtual ~Shape();
	static Shape* createShape(char T); 
	virtual double getArea() = 0;
	virtual Point getCenterOfGravity() const;
	//virtual void rotate(int degrees);
	virtual void move(const Point& point);
	virtual string compare(double area_first, double area_second);
	int getNumberOfEdges();
	virtual Point& operator [] (int i) const;
protected:
	const int _numberOfEdges;
	Point* _point = nullptr;
};
