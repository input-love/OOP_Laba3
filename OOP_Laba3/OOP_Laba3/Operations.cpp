#include "Operations.h"

bool Operations::isIntersect(const Shape& first, const Shape& second) const {
    int count_first = first.getNumberOfEdges();
    int count_second = second.getNumberOfEdges();

    bool result = false;
    for (int i = 0; i < count_first; ++i) {
        for (int j = 0; j < count_second; ++j) {
            result = intersectLines(first[i], first[(i + 1) % count_first],
                second[j], second[(j + 1) % count_second]);
        }
    }
    return result;
}

bool Operations::isInsertion(const Shape& first, const Shape& second) const {
    int count_first = first.getNumberOfEdges();
    int count_second = second.getNumberOfEdges();
    
    Line* lines = new Line[second.getNumberOfEdges()];
    for (int i = 0; i < count_first; ++i) {

        for (int j = 0; j < count_second; ++j) {
            lines[j] = Line(first[i], second[j]);
        }

        double angle = 0;
        for (int j = 0; j < count_second - 1; ++j) {
            angle += findAngle(lines[j], lines[j + 1]);
        }
        angle += findAngle(lines[count_second - 1], lines[0]);

        if (std::abs(angle - 2 * PI) >= 1e-9) {
            delete[] lines;
            return false;
        }
    }
    delete[] lines;
    return true;
}

bool Operations::intersectLines(const Point& first, const Point& second, const Point& third, const Point& fourth) const {
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

double Operations::findMagnitude(const Line& line) const {
    double x = std::abs(line.end.x - line.begin.x);
    double y = std::abs(line.end.y - line.begin.y);
    return sqrt(x * x + y * y);
}

double Operations::findAngle(const Line& first, const Line& second) const {
    Point vector_first(first.end.x - first.begin.x, first.end.y - first.begin.y);
    Point vector_second(second.end.x - second.begin.x, second.end.y - second.begin.y);

    double scalar = vector_first.x * vector_second.x + vector_first.y * vector_second.y;

    double magnitude1 = findMagnitude(first);
    double magnitude2 = findMagnitude(second);

    return acos(scalar / (magnitude1 * magnitude2));
}