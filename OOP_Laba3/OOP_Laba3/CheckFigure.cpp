#include "CheckFigure.h"

bool CheckFigure::check(char T, const Shape& figure) {
    if (T == 'T') {
        Line line_first(figure[0], figure[1]);
        Line line_second(figure[1], figure[2]);
        Line line_third(figure[2], figure[0]);

        double a = Vector::findMagnitude(line_first);
        double b = Vector::findMagnitude(line_second);
        double c = Vector::findMagnitude(line_third);

        if (a < b + c || b < c + a || c < a + b) {
            return true;
        } else {
            throw std::exception("Ошибка ввода координат... Завершение программы!");
        }
    } else {
        Line line_first(figure[0], figure[1]);
        Line line_second(figure[1], figure[2]);
        Line line_third(figure[2], figure[3]);
        Line line_fourth(figure[3], figure[4]);

        if (Vector::findMagnitude(line_first) == Vector::findMagnitude(line_third) &&
            Vector::findMagnitude(line_second) == Vector::findMagnitude(line_fourth)) {
            return true;
        } else {
            throw std::exception("Ошибка ввода координат... Завершение программы!");
        }
    }
}