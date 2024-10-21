#include <iostream>
#include "include/array.hpp"
#include "include/figure.hpp"

using namespace lab4;

int main() {
    Array<std::shared_ptr<Figure<double>>> array;  // Use shared_ptr<Figure<double>>

    auto rect = std::make_shared<Rectangle<double>>(Point<double>{0, 0}, Point<double>{4, 4});
    auto tr = std::make_shared<Trapezoid<double>>(Point<double>{0, 0}, Point<double>{4, 0}, Point<double>{3, 2}, Point<double>{1, 2});
    auto sq = std::make_shared<Square<double>>(Point<double>{0, 0}, Point<double>{4, 4});

    array.pushBack(rect);
    array.pushBack(tr);
    array.pushBack(sq);

    for (size_t i = 0; i < array.size(); ++i) {
        std::cout << "Figure " << i << " center: " << array[i]->geometricCenter() << std::endl;  // Use -> to access member functions
    }

    return 0;
}