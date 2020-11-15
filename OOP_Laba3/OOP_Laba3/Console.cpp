#include "Console.h"

Console::Console() = default;

void Console::run() {
    setlocale(LC_ALL, "Russian");

    Shape* figure_first = nullptr;
    Shape* figure_second = nullptr;

    // ---------------------------------------------------
    char T;
    std::cout << "Какую фигуру хотите создать?(T) - треугольник, (R) - прямоугольник\n";
    std::cin >> T;

    try {
        figure_first = Shape::createShape(T);
    } catch (const std::exception& exept) {
        std::cout << exept.what() << std::endl;
    }

    int count = figure_first->getNumberOfEdges();

    std::cout << "Введите координаты фигуры(x, y): " << std::endl;
    for (int i = 0; i < count; ++i) {
        std::cin >> figure_first->operator[](i).x >> figure_first->operator[](i).y;
    }
    // ---------------------------------------------------
    std::cout << "Какую фигуру хотите создать?(T) - треугольник, (R) - прямоугольник\n";
    std::cin >> T;

    try {
        figure_second = Shape::createShape(T);
    } catch (const std::exception& exept) {
        std::cout << exept.what() << std::endl;
    }

    count = figure_second->getNumberOfEdges();

    std::cout << "Введите координаты фигуры(x, y): " << std::endl;
    for (int i = 0; i < count; ++i) {
        std::cin >> figure_second->operator[](i).x >> figure_second->operator[](i).y;
    }
    // ---------------------------------------------------

    int operation;

    do {
        printMenu();

        std::cin >> operation;

        switch (operation) {
        case 1:
        {
            int numberOfFigure;
            std::cout << "У какой фигуры вычислить площадь? (1) или (2)\n";
            std::cin >> numberOfFigure;

            std::cout << "Площадь фигуры:= ";
            if (numberOfFigure == 1) {
                std::cout << figure_first->getArea() << std::endl;
            } else if (numberOfFigure == 2) {
                std::cout << figure_second->getArea() << std::endl;
            }
            break;
        }
        case 2:
        {
            int numberOfFigure;
            std::cout << "У какой фигуры вычислить центр тяжести? (1) или (2)\n";
            std::cin >> numberOfFigure;

            if (numberOfFigure == 1) {
                Point point = figure_first->getCenterOfGravity();
                std::cout << point.x << " | " << point.y << std::endl;
            } else if (numberOfFigure == 2) {
                Point point = figure_second->getCenterOfGravity();
                std::cout << point.x << " | " << point.y << std::endl;
            }
            break;
        }
        case 3:
        {
            int numberOfFigure;
            std::cout << "Какую фигуру перевернуть? (1) или (2)\n";
            std::cin >> numberOfFigure;

            int degrees;
            std::cout << "Какой угол поворота фигуры?\n";
            std::cin >> degrees;

            if (numberOfFigure == 1) {
                figure_first->rotate(degrees);
            } else if (numberOfFigure == 2) {
                figure_second->rotate(degrees);
            }
            break;
        }
        case 4:
        {
            int numberOfFigure;
            std::cout << "Какую фигуру передвинуть? (1) или (2)\n";
            std::cin >> numberOfFigure;

            Point point;
            std::cout << "На какие координаты сдвинуть? x | y\n";
            std::cin >> point.x >> point.y;

            if (numberOfFigure == 1) {
                figure_first->move(point);
            } else if (numberOfFigure == 2) {
                figure_second->move(point);
            }
            break;
        }
        case 5:
        {
            double area_first = figure_first->getArea();
            double area_second = figure_second->getArea();
            bool result = figure_first->compare(area_first, area_second);
            if (result) {
                std::cout << "Площадь 1-ой фигуры больше 2-ой\n";
            } else {
                std::cout << "Площадь 2-ой фигуры больше 1-ой\n";
            }
            break;
        }
        case 6:
        {
            Operations operations;
            bool result = operations.isIntersect(*figure_first, *figure_second);
            if (result) {
                std::cout << "Фигуры пересекаются\n";
            } else {
                std::cout << "Фигуры не пересекаются\n";
            }
            break;
        }
        case 7:
        {
            Operations operations;
            std::string result = operations.isInsertion(*figure_first, *figure_second);
            if (result == "More") {
                std::cout << "Фигура 1 включает фигуру 2\n";
            } else if (result == "Less") {
                std::cout << "Фигура 2 включает фигуру 1\n";
            } else {
                std::cout << "Фигуры не включены\n";
            }
        }
        default:
            operation = 0;
        }
    } while (operation);

    delete figure_first;
    delete figure_second;
}

void Console::printMenu() {
    std::cout << "1 - Площадь\n";
    std::cout << "2 - Центр тяжести\n";
    std::cout << "3 - Повернуть\n";
    std::cout << "4 - Переместить\n";
    std::cout << "5 - Сравнить фигуры\n";
    std::cout << "6 - Пересекаются ли фигуры\n";
    std::cout << "7 - Включены ли фигуры\n";
    std::cout << "0 - Выход\n";
}