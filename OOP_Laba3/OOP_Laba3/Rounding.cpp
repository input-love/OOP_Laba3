#include "Rounding.h"

Rounding::Rounding() = default;

double Rounding::da(double number) {
    double result;
    if (abs(number - 0) < DIFF) {
        result = 0;
    } else {
        result = number;
    }
    return result;
}