#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>

template <typename T>
class Point {
public:
    T x, y;

    Point(T x = 0, T y = 0) : x(x), y(y) {}

    Point<T> operator+(const Point<T>& other) const {
        return Point<T>(x + other.x, y + other.y);
    }

    Point<T> operator*(double scalar) const {
        return Point<T>(x * scalar, y * scalar);
    }

    static Point<T> mid(const Point<T>& p1, const Point<T>& p2) {
        return Point<T>((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
    }

    static double distance(const Point<T>& p1, const Point<T>& p2) {
        return std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2));
    }

    bool operator==(const Point<T>& other) const {
        return std::abs(x - other.x) < 1e-6 && std::abs(y - other.y) < 1e-6;
    }

    friend std::ostream& operator<<(std::ostream& os, const Point<T>& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Point<T>& point) {
        is >> point.x >> point.y;
        return is;
    }
};

#endif