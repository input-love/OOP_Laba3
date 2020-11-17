#include "Vector.h"

bool Vector::intersectOfVectors(const Line& line_first, const Line& line_second) {
    double denominator = (line_second.end.y - line_second.begin.y) * (line_first.begin.x - line_first.end.x) - (line_second.end.x - line_second.begin.x) * (line_first.begin.y - line_first.end.y);
    if (!denominator) {
        return ((line_first.begin.x * line_first.end.y - line_first.end.x * line_first.begin.y) * (line_second.end.x - line_second.begin.x) - (line_second.begin.x * line_second.end.y - line_second.end.x * line_second.begin.y)
            * (line_first.end.x - line_first.begin.x) == 0 && (line_first.begin.x * line_first.end.y - line_first.end.x * line_first.begin.y) * (line_second.end.y - line_second.begin.y)
            - (line_second.begin.x * line_second.end.y - line_second.end.x * line_second.begin.y) * (line_first.end.y - line_first.begin.y) == 0) ? true : false;
    } else {
        double numerator_first = (line_second.end.x - line_first.end.x) * (line_second.end.y - line_second.begin.y) - (line_second.end.x - line_second.begin.x) * (line_second.end.y - line_first.end.y);
        double numerator_second = (line_first.begin.x - line_first.end.x) * (line_second.end.y - line_first.end.y) - (line_second.end.x - line_first.end.x) * (line_first.begin.y - line_first.end.y);
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