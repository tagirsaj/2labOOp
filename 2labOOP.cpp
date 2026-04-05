#include <iostream>
class Point {
private:
    int x;
    int y;
public: 
    Point() : x(0), y(0) {
        std::cout << "Point: Вызван конструктор БЕЗ параметров. Координаты: (" << x << ", " << y << ")\n";
    }
    Point(int px, int py) : x(px), y(py) {
        std::cout << "Point: Вызван конструктор С параметрами. Координаты: (" << x << ", " << y << ")\n";
    }
    Point(const Point& other) : x(other.x), y(other.y) {
        std::cout << "Point: Вызван конструктор КОПИРОВАНИЯ.\n";
    }
    ~Point() {
        std::cout << "Point: Вызван ДЕСТРУКТОР для точки (" << x << ", " << y << ")\n";
    }
    void move(int dx, int dy) {
        x += dx;
        y += dy;
        std::cout << "Point: Точка перемещена. Новые координаты: (" << x << ", " << y << ")\n";
    }
};

int main() {
    std::cout << "Тестирование статического создания объектов\n";
    Point p1;                  
    Point p2(10, 20);
    Point p3(p2);              

    p1.move(5, 5);             
    std::cout << "\nТестирование динамического создания объектов\n";
    
    Point* p4 = new Point(100, 200);
    p4->move(50, 0);

    std::cout << "\nУдаление динамических объектов\n"; 
    delete p4;

    std::cout << "\nЗавершение программы (удаление статических объектов)\n";
    return 0;
}   