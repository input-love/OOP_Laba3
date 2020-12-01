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
    do {
        std::cout << "Сколько будет фигур?: ";
        std::cin >> _count;
    } while (_count <= 0);
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

            if (_figure[i]->checkFigure()) {
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
        printMenu();

        std::cin >> operation;

        switch (operation) {
        case 1:
        {
            area(*_figure[figureID()]);
            break;
        }
        case 2:
        {
            centerOfGravity(*_figure[figureID()]);
            break;
        }
        case 3:
        {
            rotate(*_figure[figureID()]);
            break;
        }
        case 4:
        {
            move(*_figure[figureID()]);
            break;
        }
        case 5:
        {
            compare(*_figure[figureID()], *_figure[figureID()]);
            break;
        }
        case 6:
        {
            intersect(*_figure[figureID()], *_figure[figureID()]);
            break;
        }
        case 7:
        {
            insertion(*_figure[figureID()], *_figure[figureID()]);
            break;
        }
        default:
            operation = 0;
        }
    } while (operation);
}

int Console::figureID() const {
    int figure_id;
    do {
        std::cout << "Введите ID фигуры: " << std::endl;
        std::cin >> figure_id;
    } while (figure_id < 1 || figure_id > _count);

    return figure_id - 1;
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
    if (result < 0) {
        std::cout << "Площадь 1-ой фигуры больше 2-ой" << std::endl;
    } else if (result > 0) {
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
    if (result) {
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