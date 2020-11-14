#include "Vector.h"

Vector::Vector() = default;

double Vector::getVectorLength(const Point & first, const Point & second) {
    double x = second.x - first.x;
    double y = second.y - first.y;
    return (sqrt(pow(x, 2) + pow(y, 2)));
}