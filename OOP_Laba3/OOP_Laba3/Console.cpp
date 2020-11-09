#include "Console.h"

Console::Console() = default;

void Console::run() {
    setlocale(LC_ALL, "Russian");

    Shape** arr_figures = new Shape* [2];

    for (int i = 0; i < 2; ++i) {
        char T;
        cout << "Какую фигуру хотите создать?(T) - треугольник, (R) - прямоугольник\n";
        cin >> T;

        try {
            arr_figures[i] = Shape::createShape(T);
        } catch (const std::exception& exept) {
            std::cout << exept.what() << std::endl;
        }

        int count = arr_figures[i]->getNumberOfEdges();

        cout << "Введите координаты фигуры(x, y): " << endl;
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
            cout << "У какой фигуры вычислить площадь? (1) или (2)\n";
            cin >> numberOfFigure;

            if (numberOfFigure == 1) {
                cout << arr_figures[0]->getArea() << endl;
            } else if (numberOfFigure == 2) {
                cout << arr_figures[1]->getArea() << endl;
            }
            break;
        case 2:
            cout << "У какой фигуры вычислить центр тяжести? (1) или (2)\n";
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
            cout << "Какую фигуру перевернуть? (1) или (2)\n";
            cin >> numberOfFigure;

            int degrees;
            cout << "Какой угол поворота фигуры?\n";
            cin >> degrees;

            if (numberOfFigure == 1) {
                //arr_figures[0]->rotate(degrees);
            } else if (numberOfFigure == 2) {
                //arr_figures[1]->rotate(degrees);
            }
            break;
        case 4:
            cout << "Какую фигуру передвинуть? (1) или (2)\n";
            cin >> numberOfFigure;

            Point point;
            cout << "На какие координаты сдвинуть? x | y\n";
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
                cout << "Площадь 1-ой фигуры больше 2-ой\n";
            }
            else if (result == "Less") {
                cout << "Площадь 1-ой фигуры меньше 2-ой\n";
            }
            else {
                cout << "Площадь 1-ой фигуры и 2-ой - равны\n";
            }
            break;
        case 6:
            bool result = Operations::IsIntersect(figure1, figure2);
            if (result) {
                cout << "Фигуры пересекаются\n";
            } else {
                cout << "Фигуры не пересекаются\n";
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
    cout << "1 - Площадь\n";
    cout << "2 - Центр тяжести\n";
    cout << "3 - Повернуть\n";
    cout << "4 - Переместить\n";
    cout << "5 - Сравнить фигуры\n";
    cout << "6 - Пересекаются ли фигуры\n";
    cout << "7 - Включены ли фигуры\n";
    cout << "0 - Выход\n";
}