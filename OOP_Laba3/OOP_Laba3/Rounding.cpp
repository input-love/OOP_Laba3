#include "Rounding.h"

double Rounding::roundingNumber(double number) {
    return (std::abs(number) < 1e-9) ? 0 : number;
}