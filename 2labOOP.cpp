#include <iostream>
#include <string>

using namespace std;

class Point {
protected:
    int x;
    int y;

public:
    Point() : x(0), y(0) {
        cout << "  [Point] Конструктор БЕЗ параметров (" << x << ", " << y << ")\n";
    }

    Point(int px, int py) : x(px), y(py) {
        cout << "  [Point] Конструктор С параметрами (" << x << ", " << y << ")\n";
    }

    Point(const Point& other) : x(other.x), y(other.y) {
        cout << "  [Point] Конструктор КОПИРОВАНИЯ\n";
    }

    ~Point() {
        cout << "  [Point] ДЕСТРУКТОР для точки (" << x << ", " << y << ")\n";
    }

    
    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }
    void print() {
        cout << "Точка (" << x << ", " << y << ")\n";
    }
};

class ColoredPoint : public Point {
private:
    string color;

public:
    ColoredPoint(int px, int py, string c) : Point(px, py), color(c) {
        cout << "  [ColoredPoint] Конструктор потомка. Цвет: " << color << "\n";
    }

    ~ColoredPoint() {
        cout << "  [ColoredPoint] ДЕСТРУКТОР потомка\n";
    }
    void print() {
        cout << "Цветная точка [" << color << "] с координатами: ";
        Point::print();
    }
};

class Line {
private:
    Point start;
    Point* end;

public:
    Line(int sx, int sy, int ex, int ey) : start(sx, sy) {
        end = new Point(ex, ey);
        cout << "  [Line] Конструктор линии создан\n";
    }

    ~Line() {
        delete end;
        cout << "  [Line] ДЕСТРУКТОР линии (объект end удален вручную, start удалится сам)\n";
    }
};

int main() {
    cout << " Наследование и порядок конструкторов\n";
    {
        ColoredPoint cp(10, 20, "Красный");
        cp.print();
    }

    cout << "\nКомпозиция (Объект и Указатель)\n";
    {
        Line myLine(0, 0, 100, 100);
    }

    cout << "\nПрисваивание объектов (Копирование)\n";
    {
        Point p1(5, 5);
        Point p2 = p1;
        p2.move(10, 10);

        cout << "После сдвига p2:\n";
        cout << "p1: "; p1.print();
        cout << "p2: "; p2.print();
    }

    cout << "\nКопирование указателей\n";
    {
        Point* ptr1 = new Point(1, 1);
        Point* ptr2 = ptr1;

        ptr2->move(4, 4);

        cout << "После сдвига ptr2:\n";
        cout << "ptr1: "; ptr1->print();

        delete ptr1;
    }

    cout << "\nПомещение потомка в указатель базового класса\n";
    {
        Point* polyPtr = new ColoredPoint(7, 7, "Синий");
        polyPtr->print();
        delete polyPtr;
    }

    cout << "\nЗавершение программы\n";
    return 0;
}