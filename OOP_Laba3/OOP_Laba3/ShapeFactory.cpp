#include "ShapeFactory.h"

Shape* ShapeFactory::createShape(char T) {
	Shape* shape = nullptr;
	switch (T) {
	case 'T':
	{
		shape = new Triangle();
		break;
	}
	case 'R':
	{
		shape = new Rectangle();
		break;
	}
	default:
		throw std::exception("Некорректный тип фигуры");
	}
	return shape;
}