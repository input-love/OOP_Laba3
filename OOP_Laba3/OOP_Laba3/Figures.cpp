#include "Figures.h"

Shape::Shape(int count): _numberOfEdges(count), _point(new Point[_numberOfEdges]) {} 

Shape::~Shape() {
	delete[] _point;
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
	double angle = Angle::radian(degrees);
	for (int i = 0; i < _numberOfEdges; ++i) {
		_point[i].x -= center.x;
		_point[i].y -= center.y;

		double temp_x = _point[i].x * cos(angle) - _point[i].y * sin(angle);
		double temp_y = _point[i].y * cos(angle) + _point[i].x * sin(angle);

		_point[i].x = temp_x + center.x;
		_point[i].y = temp_y + center.y;
	}
}

void Shape::move(const Point& point) {
	for (int i = 0; i < _numberOfEdges; ++i) {
		_point[i].x += point.x;
		_point[i].y += point.y;
	}
}

int Shape::getNumberOfEdges() const {
	return _numberOfEdges;
}

Point& Shape::operator [] (int i) const {
	return _point[i];
}