#pragma once
#include <iostream>
#include <clocale>
#include "Figures.h"
#include "Operations.h"

class Console {
public:
	Console() = default;
	void start();
private:
	void printMenu();
};
