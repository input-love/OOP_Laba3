#include "Console.h"

void Console::start() {
    setlocale(LC_ALL, "Russian");

    Shape* figure_first = nullptr;
    Shape* figure_second = nullptr;

    // ---------------------------------------------------
    char T;
    std::cout << "����� ������ ������ �������? | (T) - �����������, (R) - �������������\n";
    std::cin >> T;

    try {
        figure_first = Shape::createShape(T);
    } catch (const std::exception& exept) {
        std::cout << exept.what() << std::endl;
        return;
    }

    int count = figure_first->getNumberOfEdges();

    std::cout << "������� ���������� ������: | (x, y): " << std::endl;
    for (int i = 0; i < count; ++i) {
        std::cin >> figure_first->operator[](i).x >> figure_first->operator[](i).y;
    }
    // ---------------------------------------------------
    std::cout << "����� ������ ������ �������? | (T) - �����������, (R) - �������������\n";
    std::cin >> T;

    try {
        figure_second = Shape::createShape(T);
    } catch (const std::exception& exept) {
        std::cout << exept.what() << std::endl;
        return;
    }

    count = figure_second->getNumberOfEdges();

    std::cout << "������� ���������� ������: | (x, y): " << std::endl;
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
            std::cout << "� ����� ������ ��������� �������? | (1) ��� (2)\n";
            std::cin >> numberOfFigure;

            std::cout << "������� ������:= ";
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
            std::cout << "� ����� ������ ��������� ����� �������? | (1) ��� (2)\n";
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
            std::cout << "����� ������ �����������? | (1) ��� (2)\n";
            std::cin >> numberOfFigure;

            int degrees;
            std::cout << "����� ���� �������� ������?\n";
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
            std::cout << "����� ������ �����������? | (1) ��� (2)\n";
            std::cin >> numberOfFigure;

            Point point;
            std::cout << "�� ����� ���������� ��������? | (x, y)\n";
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
                std::cout << "������� 1-�� ������ ������ 2-��\n";
            } else if (result == "Less") {
                std::cout << "������� 2-�� ������ ������ 1-��\n";
            } else if (result == "Same") {
                std::cout << "������� 1-�� ������ ����� ������� 2-�� ������\n";
            }
            break;
        }
        case 6:
        {
            bool result = Operations::isIntersect(*figure_first, *figure_second);
            if (result) {
                std::cout << "������ ������������\n";
            } else {
                std::cout << "������ �� ������������\n";
            }
            break;
        }
        case 7:
        {
            int id_figure_first, id_figure_second;
            std::cout << "� ����� ����� ��������� ���������? | (ID ������ ������, ID ������ ������)\n";
            std::cin >> id_figure_first >> id_figure_second;

            bool result = false;
            if(id_figure_first == 1 && id_figure_second == 2) {
                result = Operations::isInsertion(*figure_second, *figure_first);
            } else if(id_figure_first == 2 && id_figure_second == 1) {
                result = Operations::isInsertion(*figure_first, *figure_second);
            }

            if (result && !Operations::isIntersect(*figure_first, *figure_second)) {
                std::cout << "��, ��������!\n";
            } else {
                std::cout << "���, �� ��������!\n";
            }
            break;
        }
        default:
            throw Error("������������ ���� ������");
        }
    } while (operation);

    delete figure_first;
    delete figure_second;
}

void Console::printMenu() {
    std::cout << "1 - �������\n";
    std::cout << "2 - ����� �������\n";
    std::cout << "3 - ���������\n";
    std::cout << "4 - �����������\n";
    std::cout << "5 - ��������\n";
    std::cout << "6 - �����������\n";
    std::cout << "7 - ���������\n";
    std::cout << "0 - �����\n";
}