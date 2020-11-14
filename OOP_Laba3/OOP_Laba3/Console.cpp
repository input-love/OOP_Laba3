#include "Console.h"

Console::Console() = default;

void Console::run() {
    setlocale(LC_ALL, "Russian");

    Shape* first_figure = nullptr;
    Shape* second_figure = nullptr;

    // ---------------------------------------------------
    char T;
    std::cout << "Какую фигуру хотите создать?(T) - треугольник, (R) - прямоугольник\n";
    std::cin >> T;

    try {
        first_figure = Shape::createShape(T);
    } catch (const std::exception& exept) {
        std::cout << exept.what() << std::endl;
    }

    int count = first_figure->getNumberOfEdges();

    std::cout << "Введите координаты фигуры(x, y): " << std::endl;
    for (int i = 0; i < count; ++i) {
        std::cin >> first_figure->operator[](i).x >> first_figure->operator[](i).y;
    }
    // ---------------------------------------------------
    std::cout << "Какую фигуру хотите создать?(T) - треугольник, (R) - прямоугольник\n";
    std::cin >> T;

    try {
        second_figure = Shape::createShape(T);
    } catch (const std::exception& exept) {
        std::cout << exept.what() << std::endl;
    }

    count = second_figure->getNumberOfEdges();

    std::cout << "Введите координаты фигуры(x, y): " << std::endl;
    for (int i = 0; i < count; ++i) {
        std::cin >> second_figure->operator[](i).x >> second_figure->operator[](i).y;
    }
    // ---------------------------------------------------

    int operation, numberOfFigure;

    do {
        printMenu();

        std::cin >> operation;

        switch (operation) {
        case 1:
        {
            std::cout << "У какой фигуры вычислить площадь? (1) или (2)\n";
            std::cin >> numberOfFigure;

            if (numberOfFigure == 1) {
                std::cout << first_figure->getArea() << std::endl;
            } else if (numberOfFigure == 2) {
                std::cout << second_figure->getArea() << std::endl;
            }
            break;
        }
        case 2:
        {
            std::cout << "У какой фигуры вычислить центр тяжести? (1) или (2)\n";
            std::cin >> numberOfFigure;

            if (numberOfFigure == 1) {
                Point point = first_figure->getCenterOfGravity();
                std::cout << point.x << " | " << point.y << std::endl;
            } else if (numberOfFigure == 2) {
                Point point = second_figure->getCenterOfGravity();
                std::cout << point.x << " | " << point.y << std::endl;
            }
            break;
        }
        case 3:
        {
            std::cout << "Какую фигуру перевернуть? (1) или (2)\n";
            std::cin >> numberOfFigure;

            int degrees;
            std::cout << "Какой угол поворота фигуры?\n";
            std::cin >> degrees;

            if (numberOfFigure == 1) {
                first_figure->rotate(degrees);
            } else if (numberOfFigure == 2) {
                second_figure->rotate(degrees);
            }
            break;
        }
        case 4:
        {
            std::cout << "Какую фигуру передвинуть? (1) или (2)\n";
            std::cin >> numberOfFigure;

            Point point;
            std::cout << "На какие координаты сдвинуть? x | y\n";
            std::cin >> point.x >> point.y;

            if (numberOfFigure == 1) {
                first_figure->move(point);
            } else if (numberOfFigure == 2) {
                second_figure->move(point);
            }
            break;
        }
        case 5:
        {
            double area_first = first_figure->getArea();
            double area_second = second_figure->getArea();
            bool result = first_figure->compare(area_first, area_second);
            if (result) {
                std::cout << "Площадь 1-ой фигуры больше 2-ой\n";
            } else {
                std::cout << "Площадь 2-ой фигуры больше 1-ой\n";
            }
            break;
        }
        case 6:
        {
            bool result = first_figure->IsIntersect(*first_figure, *second_figure);
            if (result) {
                std::cout << "Фигуры пересекаются\n";
            } else {
                std::cout << "Фигуры не пересекаются\n";
            }
        }
        default:
            operation = 0;
        }
    } while (operation);

    delete first_figure;
    delete second_figure;
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