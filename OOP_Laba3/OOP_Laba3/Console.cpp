#include "Console.h"

Console::Console() = default;

void Console::run() {
    setlocale(LC_ALL, "Russian");

    Shape* first_figure = nullptr;
    Shape* second_figure = nullptr;

    // ---------------------------------------------------
    char T;
    std::cout << "����� ������ ������ �������?(T) - �����������, (R) - �������������\n";
    std::cin >> T;

    try {
        first_figure = Shape::createShape(T);
    } catch (const std::exception& exept) {
        std::cout << exept.what() << std::endl;
    }

    int count = first_figure->getNumberOfEdges();

    std::cout << "������� ���������� ������(x, y): " << std::endl;
    for (int i = 0; i < count; ++i) {
        std::cin >> first_figure->operator[](i).x >> first_figure->operator[](i).y;
    }
    // ---------------------------------------------------
    std::cout << "����� ������ ������ �������?(T) - �����������, (R) - �������������\n";
    std::cin >> T;

    try {
        second_figure = Shape::createShape(T);
    } catch (const std::exception& exept) {
        std::cout << exept.what() << std::endl;
    }

    count = second_figure->getNumberOfEdges();

    std::cout << "������� ���������� ������(x, y): " << std::endl;
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
            std::cout << "� ����� ������ ��������� �������? (1) ��� (2)\n";
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
            std::cout << "� ����� ������ ��������� ����� �������? (1) ��� (2)\n";
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
            std::cout << "����� ������ �����������? (1) ��� (2)\n";
            std::cin >> numberOfFigure;

            int degrees;
            std::cout << "����� ���� �������� ������?\n";
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
            std::cout << "����� ������ �����������? (1) ��� (2)\n";
            std::cin >> numberOfFigure;

            Point point;
            std::cout << "�� ����� ���������� ��������? x | y\n";
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
                std::cout << "������� 1-�� ������ ������ 2-��\n";
            } else {
                std::cout << "������� 2-�� ������ ������ 1-��\n";
            }
            break;
        }
        case 6:
        {
            bool result = first_figure->IsIntersect(*first_figure, *second_figure);
            if (result) {
                std::cout << "������ ������������\n";
            } else {
                std::cout << "������ �� ������������\n";
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
    std::cout << "1 - �������\n";
    std::cout << "2 - ����� �������\n";
    std::cout << "3 - ���������\n";
    std::cout << "4 - �����������\n";
    std::cout << "5 - �������� ������\n";
    std::cout << "6 - ������������ �� ������\n";
    std::cout << "7 - �������� �� ������\n";
    std::cout << "0 - �����\n";
}