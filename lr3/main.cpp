#include "include/array.hpp"
#include "include/figures.hpp"
#include <iostream>

using namespace lab3;

int main() {
    Point p1{0, 0}, p2{2, 2}, p3{4, 0}, p4{4, 4};

    try {
        Rectangle rect(p1, p2);
        std::cout << "Rectangle area: " << double(rect) << std::endl;
        std::cout << "Rectangle geometric center: " << rect.geometricCenter() << std::endl;

        Trapezoid tr(p1, p2, p3, p4);
        std::cout << "Trapezoid area: " << double(tr) << std::endl;
        std::cout << "Trapezoid geometric center: " << tr.geometricCenter() << std::endl;

        Square sq(p1, p2);
        std::cout << "Square area: " << double(sq) << std::endl;
        std::cout << "Square geometric center: " << sq.geometricCenter() << std::endl;

        Array array;
        array.pushBack(new Rectangle(p1, p2));
        array.pushBack(new Trapezoid(p1, p2, p3, p4));
        array.pushBack(new Square(p1, p2));

        for (size_t i = 0; i < array.size(); i++) {
            std::cout << *array[i] << std::endl;
        }

        array.erase(1);
        std::cout << "After erase:" << std::endl;
        for (size_t i = 0; i < array.size(); i++) {
            std::cout << *array[i] << std::endl;
        }

    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
