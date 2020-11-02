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

int Shape::getNumberOfEdges() {
	return _numberOfEdges;
}

Point& Shape::operator [] (int i) const {
	return _point[i];
}