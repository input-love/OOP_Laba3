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
    std::cout << "������� ����� �����?: ";
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
            std::cout << "\n---������ #" << i + 1 << "---" << std::endl;

            char T;
            std::cout << "����� ������ �������? | (T) - �����������, (R) - �������������" << std::endl;
            std::cin >> T;

            _figure[i] = ShapeFactory().createShape(T);

            int count = _figure[i]->getNumberOfEdges();

            std::cout << "������� ���������� ������: | (x, y): " << std::endl;
            for (int j = 0; j < count; ++j) {
                std::cin >> _figure[i]->operator[](j).x >> _figure[i]->operator[](j).y;
            }

            if (CheckFigure::check(T, *_figure[i])) {
                std::cout << "��, ������ ����������, ����������..." << std::endl;
            } else {
                throw std::exception("���������� �� �������� �������� ������... ���������� ���������!");
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
    std::cout << "\n������� ID ������ �" << i << "(����� ������������)?: " << std::endl;
    std::cin >> ID;

    if (ID < 1 || ID > _count) {
        throw std::exception("������ ����� ID ������... ���������� ������!");
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
    std::cout << "����� ���� �������� ������?" << std::endl;
    std::cin >> degrees;

    figure.rotate(degrees);
}

void Console::move(Shape& figure) const {
    Point point;
    std::cout << "�� ����� ���������� ��������? | (x, y)" << std::endl;
    std::cin >> point.x >> point.y;

    figure.move(point);
}

void Console::compare(Shape& figure_first, Shape& figure_second) const {
    double result = figure_first.getArea() - figure_second.getArea();

    if (result > 0) {
        std::cout << "������� 1-�� ������ ������ 2-��" << std::endl;
    } else if (result < 0) {
        std::cout << "������� 2-�� ������ ������ 1-��" << std::endl;
    } else {
        std::cout << "������� 1-�� ������ ����� ������� 2-�� ������" << std::endl;
    }
}

void Console::intersect(Shape& figure_first, Shape& figure_second) const {
    bool result = Operations::isIntersect(figure_first, figure_second);
    if (result) {
        std::cout << "������ ������������" << std::endl;
    } else {
        std::cout << "������ �� ������������" << std::endl;
    }
}

void Console::insertion(Shape& figure_first, Shape& figure_second) const {
    bool result = Operations::isInsertion(figure_second, figure_first);

    if (result && !Operations::isIntersect(figure_first, figure_second)) {
        std::cout << "��, ��������!" << std::endl;
    } else {
        std::cout << "���, �� ��������!" << std::endl;
    }
}

void Console::printMenu() {
    std::cout << "\n-----------------------------" << std::endl;
    std::cout << "1 - ����� �������" << std::endl;
    std::cout << "2 - ����� ����� �������" << std::endl;
    std::cout << "3 - ��������� ������" << std::endl;
    std::cout << "4 - ����������� ������" << std::endl;
    std::cout << "5 - �������� ��� ������ (�� �������)" << std::endl;
    std::cout << "6 - ����������� �����" << std::endl;
    std::cout << "7 - ��������� ����� ������ � ������" << std::endl;
    std::cout << "0 - �����" << std::endl;
    std::cout << "-----------------------------" << std::endl;
}