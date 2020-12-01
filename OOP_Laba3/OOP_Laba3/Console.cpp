#include "Console.h"

Console::~Console() {
    for (int i = 0; i < _count; ++i) {
        if (_figure[i] != nullptr) {
            delete _figure[i];
        }
    }
    delete[] _figure;
}

void Console::start() {
    setlocale(LC_ALL, "Russian");

    try {
        dialogFigureCount();
        createEmptyArr();
        createFigure();
        dialog();
    } catch (const std::exception& exept) {
        std::cout << exept.what() << std::endl;
    }
}

void Console::dialogFigureCount() {
    std::cout << "Сколько будет фигур?: ";
    std::cin >> _count;
}

void Console::createEmptyArr() {
    _figure = new Shape*[_count];
    for (int i = 0; i < _count; ++i) {
        _figure[i] = nullptr;
    }
}

void Console::createFigure() {
    try {
        for (int i = 0; i < _count; ++i) {
            std::cout << "\n---Фигура #" << i + 1 << "---" << std::endl;

            char T;
            std::cout << "Какую фигуру создать? | (T) - треугольник, (R) - прямоугольник" << std::endl;
            std::cin >> T;

            _figure[i] = ShapeFactory().createShape(T);

            int count = _figure[i]->getNumberOfEdges();

            std::cout << "Введите координаты фигуры: | (x, y): " << std::endl;
            for (int j = 0; j < count; ++j) {
                std::cin >> _figure[i]->operator[](j).x >> _figure[i]->operator[](j).y;
            }

            if (CheckFigure::check(T, *_figure[i])) {
                std::cout << "Ок, фигура существует, продолжаем..." << std::endl;
            } else {
                throw std::exception("Координаты не подходят описанию фигуры... Завершение программы!");
            }
        }
    } catch (const std::exception& exept) {
        throw std::exception(exept.what());
    }
}

void Console::dialog() {
    int operation;

    do {
        int ID_first = figureID(1);

        printMenu();
        std::cin >> operation;

        switch (operation) {
        case 1:
            area(*_figure[ID_first]);
            break;
        case 2:
            centerOfGravity(*_figure[ID_first]);
            break;
        case 3:
            rotate(*_figure[ID_first]);
            break;
        case 4:
            move(*_figure[ID_first]);
            break;
        case 5:
        {
            int ID_second = figureID(2);
            compare(*_figure[ID_first], *_figure[ID_second]);
            break;
        }
        case 6:
        {
            int ID_second = figureID(2);
            intersect(*_figure[ID_first], *_figure[ID_second]);
            break;
        }
        case 7:
        {
            int ID_second = figureID(2);
            insertion(*_figure[ID_first], *_figure[ID_second]);
            break;
        }
        default:
            operation = 0;
            break;
        }
    } while (operation);
}

int Console::figureID(int i) const {
    int ID;
    std::cout << "\nВведите ID фигуры №" << i << "(какую использовать)?: " << std::endl;
    std::cin >> ID;

    if (ID < 1 || ID > _count) {
        throw std::exception("Ошибка ввода ID фигуры... Завершение работы!");
    }

    return ID - 1;
}

void Console::area(Shape& figure) const {
    std::cout << figure.getArea() << std::endl;
}

void Console::centerOfGravity(const Shape& figure) const {
    Point point = figure.getCenterOfGravity();
    std::cout << point.x << " | " << point.y << std::endl;
}

void Console::rotate(Shape& figure) const {
    int degrees;
    std::cout << "Какой угол поворота фигуры?" << std::endl;
    std::cin >> degrees;

    figure.rotate(degrees);
}

void Console::move(Shape& figure) const {
    Point point;
    std::cout << "На какие координаты сдвинуть? | (x, y)" << std::endl;
    std::cin >> point.x >> point.y;

    figure.move(point);
}

void Console::compare(Shape& figure_first, Shape& figure_second) const {
    double result = figure_first.getArea() - figure_second.getArea();

    if (result > 0) {
        std::cout << "Площадь 1-ой фигуры больше 2-ой" << std::endl;
    } else if (result < 0) {
        std::cout << "Площадь 2-ой фигуры больше 1-ой" << std::endl;
    } else {
        std::cout << "Площадь 1-ой фигуры равна площади 2-ой фигуры" << std::endl;
    }
}

void Console::intersect(Shape& figure_first, Shape& figure_second) const {
    bool result = Operations::isIntersect(figure_first, figure_second);
    if (result) {
        std::cout << "Фигуры пересекаются" << std::endl;
    } else {
        std::cout << "Фигуры не пересекаются" << std::endl;
    }
}

void Console::insertion(Shape& figure_first, Shape& figure_second) const {
    bool result = Operations::isInsertion(figure_second, figure_first);

    if (result && !Operations::isIntersect(figure_first, figure_second)) {
        std::cout << "Да, включает!" << std::endl;
    } else {
        std::cout << "Нет, не включает!" << std::endl;
    }
}

void Console::printMenu() {
    std::cout << "\n-----------------------------" << std::endl;
    std::cout << "1 - Найти площадь" << std::endl;
    std::cout << "2 - Найти центр тяжести" << std::endl;
    std::cout << "3 - Повернуть фигуру" << std::endl;
    std::cout << "4 - Переместить фигуру" << std::endl;
    std::cout << "5 - Сравнить две фигуры (по площади)" << std::endl;
    std::cout << "6 - Пересечение фигур" << std::endl;
    std::cout << "7 - Включение одной фигуры в другую" << std::endl;
    std::cout << "0 - Выход" << std::endl;
    std::cout << "-----------------------------" << std::endl;
}