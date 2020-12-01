#include "ShapeFactory.h"

Shape* ShapeFactory::createShape(char T) {
	switch (T) {
	case 'T':
	{
		return new Triangle();
	}
	case 'R':
	{
		return new Rectangle();
	}
	default:
		throw std::exception("Некорректный тип фигуры");
	}
}