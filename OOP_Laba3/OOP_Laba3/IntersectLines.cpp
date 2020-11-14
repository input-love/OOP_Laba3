#include "IntersectLines.h"

IntersectLines::IntersectLines() = default;

bool IntersectLines::checkLines(
    const Point& first, const Point& second, const Point& third, const Point& fourth
) {
    double denominator = (fourth.y - third.y) * (first.x - second.x) - (fourth.x - third.x) * (first.y - second.y);
    if (denominator == 0) {
        if ((first.x * second.y - second.x * first.y) * (fourth.x - third.x) - (third.x * fourth.y - fourth.x * third.y)
            * (second.x - first.x) == 0 && (first.x * second.y - second.x * first.y) * (fourth.y - third.y)
            - (third.x * fourth.y - fourth.x * third.y) * (second.y - first.y) == 0) {
            return true;
        } else {
            return false;
        }
    } else {
        double numerator_first = (fourth.x - second.x) * (fourth.y - third.y) - (fourth.x - third.x) * (fourth.y - second.y);
        double numerator_second = (first.x - second.x) * (fourth.y - second.y) - (fourth.x - second.x) * (first.y - second.y);
        double temp1 = numerator_first / denominator;
        double temp2 = numerator_second / denominator;
        if ((temp1 >= 0 && temp1 <= 1 && temp2 >= 0 && temp2 <= 1)) {
            return true;
        } else {
            return false;
        }
    }
}