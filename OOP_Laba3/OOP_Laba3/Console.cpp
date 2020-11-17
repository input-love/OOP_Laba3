#include "Console.h"

void Console::start() {
    setlocale(LC_ALL, "Russian");

    Shape* figure_first = nullptr;
    Shape* figure_second = nullptr;

    // ---------------------------------------------------
    char T;
    std::cout << "Какую фигуру хотите создать? | (T) - треугольник, (R) - прямоугольник\n";
    std::cin >> T;

    try {
        figure_first = Shape::createShape(T);
    } catch (const std::exception& exept) {
        std::cout << exept.what() << std::endl;
        return;
    }

    int count = figure_first->getNumberOfEdges();

    std::cout << "Введите координаты фигуры: | (x, y): " << std::endl;
    for (int i = 0; i < count; ++i) {
        std::cin >> figure_first->operator[](i).x >> figure_first->operator[](i).y;
    }
    // ---------------------------------------------------
    std::cout << "Какую фигуру хотите создать? | (T) - треугольник, (R) - прямоугольник\n";
    std::cin >> T;

    try {
        figure_second = Shape::createShape(T);
    } catch (const std::exception& exept) {
        std::cout << exept.what() << std::endl;
        return;
    }

    count = figure_second->getNumberOfEdges();

    std::cout << "Введите координаты фигуры: | (x, y): " << std::endl;
    for (int i = 0; i < count; ++i) {
        std::cin >> figure_second->operator[](i).x >> figure_second->operator[](i).y;
    }
    // ---------------------------------------------------

    int operation;

    do {
        printMenu();

        std::cin >> operation;

        switch (operation) {
        case 0:
        {
            operation = 0;
            break;
        }
        case 1:
        {
            int numberOfFigure;
            std::cout << "У какой фигуры вычислить площадь? | (1) или (2)\n";
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
            std::cout << "У какой фигуры вычислить центр тяжести? | (1) или (2)\n";
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
            std::cout << "Какую фигуру перевернуть? | (1) или (2)\n";
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
            std::cout << "Какую фигуру передвинуть? | (1) или (2)\n";
            std::cin >> numberOfFigure;

            Point point;
            std::cout << "На какие координаты сдвинуть? | (x, y)\n";
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

            std::string result = figure_first->compare(area_first, area_second);
            if (result == "More") {
                std::cout << "Площадь 1-ой фигуры больше 2-ой\n";
            } else if (result == "Less") {
                std::cout << "Площадь 2-ой фигуры больше 1-ой\n";
            } else if (result == "Same") {
                std::cout << "Площадь 1-ой фигуры равна площади 2-ой фигуры\n";
            }
            break;
        }
        case 6:
        {
            bool result = Operations::isIntersect(*figure_first, *figure_second);
            if (result) {
                std::cout << "Фигуры пересекаются\n";
            } else {
                std::cout << "Фигуры не пересекаются\n";
            }
            break;
        }
        case 7:
        {
            int id_figure_first, id_figure_second;
            std::cout << "У каких фигур проверить включение? | (ID первой фигуры, ID второй фигуры)\n";
            std::cin >> id_figure_first >> id_figure_second;

            bool result = false;
            if(id_figure_first == 1 && id_figure_second == 2) {
                result = Operations::isInsertion(*figure_second, *figure_first);
            } else if(id_figure_first == 2 && id_figure_second == 1) {
                result = Operations::isInsertion(*figure_first, *figure_second);
            }

            if (result && !Operations::isIntersect(*figure_first, *figure_second)) {
                std::cout << "Да, включает!\n";
            } else {
                std::cout << "Нет, не включает!\n";
            }
            break;
        }
        default:
            throw Error("Некорректный ввод данных");
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
    std::cout << "5 - Сравнить\n";
    std::cout << "6 - Пересечение\n";
    std::cout << "7 - Включение\n";
    std::cout << "0 - Выход\n";
}