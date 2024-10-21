#include "figure.hpp"
#include <cmath>
#include <stdexcept>

namespace lab4 {

// Rectangle
template <typename T>
Rectangle<T>::Rectangle(const Point<T>& point1, const Point<T>& point2) {
    if (std::abs(point1.x - point2.x) <= 1e-6 && std::abs(point1.y - point2.y) <= 1e-6) {
        throw std::invalid_argument("Bad points.");
    }
    this->point1 = std::make_unique<Point<T>>(point1);
    this->point2 = std::make_unique<Point<T>>(point2);
}

template <typename T>
Rectangle<T>::Rectangle(const Rectangle &rect) {
    point1 = std::make_unique<Point<T>>(*rect.point1);
    point2 = std::make_unique<Point<T>>(*rect.point2);
}

template <typename T>
Rectangle<T>::Rectangle(Rectangle &&rect) noexcept {
    point1 = std::move(rect.point1);
    point2 = std::move(rect.point2);
}

template <typename T>
Rectangle<T>& Rectangle<T>::operator=(const Rectangle &rect) {
    if (this != &rect) {
        point1 = std::make_unique<Point<T>>(*rect.point1);
        point2 = std::make_unique<Point<T>>(*rect.point2);
    }
    return *this;
}

template <typename T>
Rectangle<T>& Rectangle<T>::operator=(Rectangle &&rect) noexcept {
    if (this != &rect) {
        point1 = std::move(rect.point1);
        point2 = std::move(rect.point2);
    }
    return *this;
}

template <typename T>
bool Rectangle<T>::operator==(const Rectangle &other) const {
    return *point1 == *other.point1 && *point2 == *other.point2;
}

template <typename T>
Rectangle<T>::operator double () const {
    return std::abs(point1->y - point2->y) * std::abs(point1->x - point2->x);
}

template <typename T>
Point<T> Rectangle<T>::geometricCenter() const {
    return Point<T>::mid(*point1, *point2);
}

// Trapezoid
template <typename T>
Trapezoid<T>::Trapezoid(const Point<T>& point1, const Point<T>& point2, const Point<T>& point3, const Point<T>& point4) {
    this->point1 = std::make_unique<Point<T>>(point1);
    this->point2 = std::make_unique<Point<T>>(point2);
    this->point3 = std::make_unique<Point<T>>(point3);
    this->point4 = std::make_unique<Point<T>>(point4);
}

template <typename T>
Trapezoid<T>::Trapezoid(const Trapezoid &tr) {
    point1 = std::make_unique<Point<T>>(*tr.point1);
    point2 = std::make_unique<Point<T>>(*tr.point2);
    point3 = std::make_unique<Point<T>>(*tr.point3);
    point4 = std::make_unique<Point<T>>(*tr.point4);
}

template <typename T>
Trapezoid<T>::Trapezoid(Trapezoid &&tr) noexcept {
    point1 = std::move(tr.point1);
    point2 = std::move(tr.point2);
    point3 = std::move(tr.point3);
    point4 = std::move(tr.point4);
}

template <typename T>
Trapezoid<T>& Trapezoid<T>::operator=(const Trapezoid &tr) {
    if (this != &tr) {
        point1 = std::make_unique<Point<T>>(*tr.point1);
        point2 = std::make_unique<Point<T>>(*tr.point2);
        point3 = std::make_unique<Point<T>>(*tr.point3);
        point4 = std::make_unique<Point<T>>(*tr.point4);
    }
    return *this;
}

template <typename T>
Trapezoid<T>& Trapezoid<T>::operator=(Trapezoid &&tr) noexcept {
    if (this != &tr) {
        point1 = std::move(tr.point1);
        point2 = std::move(tr.point2);
        point3 = std::move(tr.point3);
        point4 = std::move(tr.point4);
    }
    return *this;
}

template <typename T>
bool Trapezoid<T>::operator==(const Trapezoid &other) const {
    return *point1 == *other.point1 && *point2 == *other.point2 &&
           *point3 == *other.point3 && *point4 == *other.point4;
}

template <typename T>
Trapezoid<T>::operator double () const {
    return 0.5 * std::abs(point1->x * point2->y + point2->x * point3->y + 
                           point3->x * point4->y + point4->x * point1->y - 
                           (point1->y * point2->x + point2->y * point3->x + 
                            point3->y * point4->x + point4->y * point1->x));
}

template <typename T>
Point<T> Trapezoid<T>::geometricCenter() const {
    return (*point1 + *point2 + *point3 + *point4) * 0.25;
}

// Square
template <typename T>
Square<T>::Square(const Point<T>& point1, const Point<T>& point2) {
    if (std::abs(std::abs(point1.x - point2.x) - std::abs(point1.y - point2.y)) >= 1e-6) {
        throw std::invalid_argument("Bad points.");
    }
    this->point1 = std::make_unique<Point<T>>(point1);
    this->point2 = std::make_unique<Point<T>>(point2);
}

template <typename T>
Square<T>::Square(const Square &sq) {
    point1 = std::make_unique<Point<T>>(*sq.point1);
    point2 = std::make_unique<Point<T>>(*sq.point2);
}

template <typename T>
Square<T>::Square(Square &&sq) noexcept {
    point1 = std::move(sq.point1);
    point2 = std::move(sq.point2);
}

template <typename T>
Square<T>& Square<T>::operator=(const Square &sq) {
    if (this != &sq) {
        point1 = std::make_unique<Point<T>>(*sq.point1);
        point2 = std::make_unique<Point<T>>(*sq.point2);
    }
    return *this;
}

template <typename T>
Square<T>& Square<T>::operator=(Square &&sq) noexcept {
    if (this != &sq) {
        point1 = std::move(sq.point1);
        point2 = std::move(sq.point2);
    }
    return *this;
}

template <typename T>
bool Square<T>::operator==(const Square &other) const {
    return *point1 == *other.point1 && *point2 == *other.point2;
}

template <typename T>
Square<T>::operator double () const {
    return std::pow(Point<T>::distance(*point1, *point2), 2);
}

template <typename T>
Point<T> Square<T>::geometricCenter() const {
    return Point<T>::mid(*point1, *point2);
}

// Explicit instantiation for double
template class Rectangle<double>;
template class Trapezoid<double>;
template class Square<double>;

}