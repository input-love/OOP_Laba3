#pragma once
#include <iostream>
#include <clocale>
#include "Figures.h"
#include "Vector.h"
using std::cout;
using std::cin;
using std::endl;

class Console {
public:
	Console();
	void run();
private:
	void deleteArray(Shape** arr);
	void printMenu();
};
