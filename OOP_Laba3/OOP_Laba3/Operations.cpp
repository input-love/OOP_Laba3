#include "Operations.h"

bool Operations::isIntersect(const Shape& first, const Shape& second) const {
    int count_first = first.getNumberOfEdges();
    int count_second = second.getNumberOfEdges();

    bool result = false;
    for (int i = 0; i < count_first; ++i) {
        for (int j = 0; j < count_second; ++j) {
            result = Vector::intersectOfVectors(first[i], first[(i + 1) % count_first],
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