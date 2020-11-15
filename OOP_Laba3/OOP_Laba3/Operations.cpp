#include "Operations.h"

bool Operations::isIntersect(const Shape& first, const Shape& second) const {
    bool result = false;
    int count_first = first.getNumberOfEdges();
    int count_second = second.getNumberOfEdges();
    for (int i = 0; i < count_first; ++i) {
        for (int j = 0; j < count_second; ++j) {
            result = intersectLines(first[i], first[(i + 1) % count_first],
                second[j], second[(j + 1) % count_second]);
        }
    }
    return result;
}

std::string Operations::isInsertion(const Shape& first, const Shape& second) const {
    std::string figure_first = getMostLeftCoord(first, second);
    std::string figure_second = getMostRightCoord(first, second);
    if (!isIntersect(first, second) && (figure_first == figure_second)) {
        return (figure_first == "First figure") ? "More" : "Less";
    } else {
        return "Equally";
    }
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

std::string Operations::getMostLeftCoord(const Shape& first, const Shape& second) const {
    std::string figure;
    Point MostLeft = first[0];

    int count = first.getNumberOfEdges();
    for (int i = 1; i < count; ++i) {
        if (first[i].x < MostLeft.x) {
            MostLeft = first[i];
            figure = "First figure";
        }
    }

    count = second.getNumberOfEdges();
    for (int i = 0; i < count; ++i) {
        if (second[i].x < MostLeft.x) {
            MostLeft = second[i];
            figure = "Second figure";
        }
    }
    return figure;
}

std::string Operations::getMostRightCoord(const Shape& first, const Shape& second) const {
    std::string figure;
    Point MostRight = first[0];

    int count = first.getNumberOfEdges();
    for (int i = 1; i < count; ++i) {
        if (first[i].x < MostRight.x) {
            MostRight = first[i];
            figure = "First figure";
        }
    }

    count = second.getNumberOfEdges();
    for (int i = 0; i < count; ++i) {
        if (second[i].x < MostRight.x) {
            MostRight = second[i];
            figure = "Second figure";
        }
    }
    return figure;
}