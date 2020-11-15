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
		throw Error("Некорректный ввод данных");
	}
	return shape; 
}

Point Shape::getCenterOfGravity() const {
	Point point;
	for (int i = 0; i < _numberOfEdges; ++i) {
		point.x += _point[i].x;
		point.y += _point[i].y;
	}
	point.x = point.x / _numberOfEdges;
	point.y = point.y / _numberOfEdges;
	return point;
}

void Shape::rotate(int degrees) {
	Point center = getCenterOfGravity();
	double angle = Radian::degreesToRadian(degrees);
	for (int i = 0; i < _numberOfEdges; ++i) {
		_point[i].x -= center.x;
		_point[i].y -= center.y;

		double temp_x = _point[i].x * cos(angle) - _point[i].y * sin(angle);
		double temp_y = _point[i].y * cos(angle) + _point[i].x * sin(angle);

		_point[i].x = temp_x + center.x;
		_point[i].y = temp_y + center.y;

		_point[i].x = Rounding::roundingNumber(_point[i].x);
		_point[i].y = Rounding::roundingNumber(_point[i].y);
	}
}

void Shape::move(const Point& point) {
	for (int i = 0; i < _numberOfEdges; ++i) {
		_point[i].x += point.x;
		_point[i].y += point.y;
	}
}

bool Shape::compare(double area_first, double area_second) {
	return area_first > area_second;
}

int Shape::getNumberOfEdges() const {
	return _numberOfEdges;
}

Point& Shape::operator [] (int i) const {
	return _point[i];
}