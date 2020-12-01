#pragma once
#include <iostream>
#include <clocale>
#include "Figures.h"
#include "ShapeFactory.h"
#include "Operations.h"

class Console {
public:
	~Console();
	void start();
private:
	void dialogFigureCount();
	void createEmptyArr();
	void createFigure();
	void dialog();
	int figureID() const;
	void area(Shape& figure) const;
	void centerOfGravity(const Shape& figure) const;
	void rotate(Shape& figure) const;
	void move(Shape& figure) const;
	void compare(Shape& figure_first, Shape& figure_second) const;
	void intersect(Shape& figure_first, Shape& figure_second) const;
	void insertion(Shape& figure_first, Shape& figure_second) const;
	void printMenu();

	int _count = 0;
	Shape** _figure = nullptr;
};
