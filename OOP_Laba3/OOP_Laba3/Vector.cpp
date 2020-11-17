#include "Vector.h"

bool Vector::intersectOfVectors(const Point& first, const Point& second, const Point& third, const Point& fourth) {
    double denominator = (fourth.y - third.y) * (first.x - second.x) - (fourth.x - third.x) * (first.y - second.y);
    if (denominator == 0) {
        return ((first.x * second.y - second.x * first.y) * (fourth.x - third.x) - (third.x * fourth.y - fourth.x * third.y)
            * (second.x - first.x) == 0 && (first.x * second.y - second.x * first.y) * (fourth.y - third.y)
            - (third.x * fourth.y - fourth.x * third.y) * (second.y - first.y) == 0) ? true : false;
    }
    else {
        double numerator_first = (fourth.x - second.x) * (fourth.y - third.y) - (fourth.x - third.x) * (fourth.y - second.y);
        double numerator_second = (first.x - second.x) * (fourth.y - second.y) - (fourth.x - second.x) * (first.y - second.y);
        double temp_first = numerator_first / denominator;
        double temp_second = numerator_second / denominator;
        return (temp_first >= 0 && temp_first <= 1 && temp_second >= 0 && temp_second <= 1) ? true : false;
    }
}

double Vector::findMagnitude(const Line& line) {
    double x = std::abs(line.end.x - line.begin.x);
    double y = std::abs(line.end.y - line.begin.y);
    return sqrt(pow(x, 2) + pow(y, 2));
}