#include "Vector.h"

Vector::Vector() = default;

double Vector::getVectorLength(double x, double y) {
    return (sqrt(pow(x, 2) + pow(y, 2)));
}