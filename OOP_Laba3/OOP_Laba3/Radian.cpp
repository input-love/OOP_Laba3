#include "Radian.h"
#include <math.h>

Radian::Radian() = default;

double Radian::degreesToRadian(int degrees) {
	double result = (degrees * 2.0 * asin(1)) / 180;
	return result;
}