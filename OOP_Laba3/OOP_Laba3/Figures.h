#pragma once
#include "Point.h"
#include "Vector.h"
#include "Radian.h"
#include "Rounding.h"
#include "Error.h"
using std::string;

class Shape { 
public:
	Shape(int count);
	virtual ~Shape();
	static Shape* createShape(char T); 
	virtual double getArea() = 0;
	Point getCenterOfGravity() const;
	virtual void rotate(int degrees);
	void move(const Point& point);
	string compare(double area_first, double area_second); // Пофиксить вирк функции
	//virtual bool IsIntersect(Shape* first, Shape* second);
	int getNumberOfEdges();
	virtual Point& operator [] (int i) const;
protected:
	const int _numberOfEdges;
	Point* _point = nullptr;
};
