#include "Console.h"

Console::Console() = default;

void Console::run() {
    setlocale(LC_ALL, "Russian");

    int operation;
    Shape** arr_figures = new Shape* [2];
    double** arr_vector = new double* [2];
    Vector vector;

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

        arr_vector[i] = new double[count];
        for (int j = 0; j < count; ++j) { // Убрать 
            double x, y;
            if (j == count - 1) {
                x = (*arr_figures[i])[0].x - (*arr_figures[i])[j].x;
                y = (*arr_figures[i])[0].y - (*arr_figures[i])[j].y;
            } else {
                x = (*arr_figures[i])[j + 1].x - (*arr_figures[i])[j].x;
                y = (*arr_figures[i])[j + 1].y - (*arr_figures[i])[j].y;
            }
            arr_vector[i][j] = vector.getVectorLength(x, y);
        }
    }

    do {
        printMenu();
        cin >> operation;
        int numberOfFigure;
        switch (operation) {
        case 1:
            cout << "У какой фигуры вычилсить площадь? (1) или (2)\n";
            cin >> numberOfFigure;
            if (numberOfFigure == 1) {
                cout << arr_figures[0]->getArea(arr_vector[0]) << endl;
            } else if (numberOfFigure == 2) {
                cout << arr_figures[1]->getArea(arr_vector[1]) << endl;
            }
            break;
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
    cout << "8 - Вывести координаты фигур\n";
    cout << "0 - Выход\n";
}