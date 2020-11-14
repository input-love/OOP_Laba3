#include "Rounding.h"

Rounding::Rounding() = default;

double Rounding::roundingNumber(double number) {
    double result;
    if (abs(number - 0) < 0.0000000001) {
        result = 0;
    } else {
        result = number;
    }
    return result;
}