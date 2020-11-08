#include "Figures.h"
#include "Triangle.h"
#include "Rectangle.h"

Shape::Shape(int count): _numberOfEdges(count), _point(new Point[_numberOfEdges]) {} 

Shape::~Shape() {
	delete[] _point;
}

Shape* Shape::createShape(char T) { 
	Shape* shape = nullptr; 
	switch (T) { 
	case 'T':
		{
		shape = new Triangle();
		}
		break; 
	case 'R':
		{
		shape = new Rectangle();
		}
		break;
	default:
		throw Error("������������ ���� ������");
	}
	return shape; 
}

Point Shape::getCenterOfGravity() const {
	Point point;
	point.x = 0.0;
	point.y = 0.0;
	for (int i = 0; i < _numberOfEdges; ++i) {
		point.x = point.x + _point[i].x;
		point.y = point.y + _point[i].y;
	}
	point.x = point.x / _numberOfEdges;
	point.y = point.y / _numberOfEdges;
	return point;
}

/*void Shape::rotate(int degrees) {
	double angle = AdditionalFunctions::degreesToRadian(degrees);

	Point center = getCenterOfGravity();
	for (int i = 0; i < _numberOfEdges; ++i)
	{
		_point[i].x -= center.x;
		_point[i].y -= center.y;

		double tempX = _point[i].x * cos(angle) - _point[i].y * sin(angle);
		double tempY = _point[i].y * cos(angle) + _point[i].x * sin(angle);

		_point[i].x = tempX + center.x;
		_point[i].y = tempY + center.y;

		_point[i].x = AdditionalFunctions::rounding(_point[i].x);
		_point[i].y = AdditionalFunctions::rounding(_point[i].y);
	}
}*/

void Shape::move(const Point& point) {
	for (int i = 0; i < _numberOfEdges; ++i)
	{
		_point[i].x += point.x;
		_point[i].y += point.y;
	}
}

string Shape::compare(double area_first, double area_second) {
	if (area_first > area_second) {
		return "More";
	} else if (area_first < area_second) {
		return "Less";
	} else {
		return "Equal";
	}
}

int Shape::getNumberOfEdges() {
	return _numberOfEdges;
}

Point& Shape::operator [] (int i) const {
	return _point[i];
}