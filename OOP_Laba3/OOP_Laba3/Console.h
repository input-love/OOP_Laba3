#pragma once
#include <iostream>
#include <clocale>
#include "Figures.h"
#include "Vector.h"

class Console {
public:
	Console();
	void run();
private:
	void printMenu();
};
