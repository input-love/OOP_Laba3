#include "Operations.h"

bool Operations::isIntersect(const Shape& first, const Shape& second) {
    int count_first = first.getNumberOfEdges();
    int count_second = second.getNumberOfEdges();

    bool result = false;
    for (int i = 1; i < count_first - 1 && !result; ++i) {
        for (int j = 1; j < count_second - 1 && !result; ++j) {
            Line line_first(first[i - 1], first[i]);
            Line line_second(second[j - 1], second[j]);
            if (Vector::isIntersectLines(line_first, line_second)) {
                result = true;
            }
        }
    }

    Line line_first(first[count_first - 1], first[0]);
    Line line_second(second[count_second - 1], second[0]);
    if (Vector::isIntersectLines(line_first, line_second)) {
        result = true;
    }

    return result;
}


bool Operations::isInsertion(const Shape& first, const Shape& second) {
    int count_first = first.getNumberOfEdges();
    int count_second = second.getNumberOfEdges();
    
    Line* lines = new Line[count_second];
    for (int i = 0; i < count_first; ++i) {

        for (int j = 0; j < count_second; ++j) {
            lines[j] = Line(first[i], second[j]);
        }

        double angle = 0;
        for (int j = 0; j < count_second - 1; ++j) {
            angle += Angle::findAngle(lines[j], lines[j + 1]);
        }
        angle += Angle::findAngle(lines[count_second - 1], lines[0]);

        if (std::abs(angle - 2 * PI) >= 1e-9) {
            delete[] lines;
            return false;
        }

    }
    delete[] lines;
    return true;
}