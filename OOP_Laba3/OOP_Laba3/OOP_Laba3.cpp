#include <vld.h>
#include <stdexcept>
#include "Console.h"

int main() {
	try {
		Console console;
		console.start();
	} catch (const std::exception& exept) {
		std::cout << exept.what() << std::endl;
	}
	return 0;
}
