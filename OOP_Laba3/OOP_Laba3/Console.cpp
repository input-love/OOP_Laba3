#include "Console.h"

Console::Console() = default;

void Console::run() {
    setlocale(LC_ALL, "Russian");

    Shape** arr_figures = new Shape* [2];

    for (int i = 0; i < 2; ++i) {
        char T;
        cout << "����� ������ ������ �������?(T) - �����������, (R) - �������������\n";
        cin >> T;

        try {
            arr_figures[i] = Shape::createShape(T);
        } catch (const std::exception& exept) {
            std::cout << exept.what() << std::endl;
        }

        int count = arr_figures[i]->getNumberOfEdges();

        cout << "������� ���������� ������(x, y): " << endl;
        for (int j = 0; j < count; ++j) {
            cin >> (*arr_figures[i])[j].x >> (*arr_figures[i])[j].y;
        }
    }

    int operation, numberOfFigure;

    do {
        printMenu();

        cin >> operation;

        switch (operation) {
        case 1:
            cout << "� ����� ������ ��������� �������? (1) ��� (2)\n";
            cin >> numberOfFigure;

            if (numberOfFigure == 1) {
                cout << arr_figures[0]->getArea() << endl;
            } else if (numberOfFigure == 2) {
                cout << arr_figures[1]->getArea() << endl;
            }
            break;
        case 2:
            cout << "� ����� ������ ��������� ����� �������? (1) ��� (2)\n";
            cin >> numberOfFigure;

            if (numberOfFigure == 1) {
                Point point = arr_figures[0]->getCenterOfGravity();
                cout << point.x << " | " << point.y << endl;
            } else if (numberOfFigure == 2) {
                Point point = arr_figures[1]->getCenterOfGravity();
                cout << point.x << " | " << point.y << endl;
            }
            break;
        case 3:
            cout << "����� ������ �����������? (1) ��� (2)\n";
            cin >> numberOfFigure;

            int degrees;
            cout << "����� ���� �������� ������?\n";
            cin >> degrees;

            if (numberOfFigure == 1) {
                //arr_figures[0]->rotate(degrees);
            } else if (numberOfFigure == 2) {
                //arr_figures[1]->rotate(degrees);
            }
            break;
        case 4:
            cout << "����� ������ �����������? (1) ��� (2)\n";
            cin >> numberOfFigure;

            Point point;
            cout << "�� ����� ���������� ��������? x | y\n";
            cin >> point.x >> point.y;

            if (numberOfFigure == 1) {
                arr_figures[0]->move(point);
            } else if (numberOfFigure == 2) {
                arr_figures[1]->move(point);
            }
            break;
        case 5:
            double area_first = arr_figures[0]->getArea();
            double area_second = arr_figures[1]->getArea();
            string result = arr_figures[0]->compare(area_first, area_second);
            if (result == "More") {
                cout << "������� 1-�� ������ ������ 2-��\n";
            }
            else if (result == "Less") {
                cout << "������� 1-�� ������ ������ 2-��\n";
            }
            else {
                cout << "������� 1-�� ������ � 2-�� - �����\n";
            }
            break;
        case 6:
            bool result = Operations::IsIntersect(figure1, figure2);
            if (result) {
                cout << "������ ������������\n";
            } else {
                cout << "������ �� ������������\n";
            }
        default:
            operation = 0;
        }
    } while (operation);

    deleteArray(arr_figures);
}

void Console::deleteArray(Shape** arr) {
    for (int i = 0; i < 2; ++i) {
        delete arr[i];
    }
    delete[] arr;
}

void Console::printMenu() {
    cout << "1 - �������\n";
    cout << "2 - ����� �������\n";
    cout << "3 - ���������\n";
    cout << "4 - �����������\n";
    cout << "5 - �������� ������\n";
    cout << "6 - ������������ �� ������\n";
    cout << "7 - �������� �� ������\n";
    cout << "0 - �����\n";
}