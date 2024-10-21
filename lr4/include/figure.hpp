#pragma once

#include "point.hpp"
#include <memory>
#include <algorithm>
#include <iostream>

namespace lab4 {

template <typename T>
class Figure {
public:
    virtual Point<T> geometricCenter() const = 0;
    virtual operator double () const = 0; 
    virtual ~Figure() = default;
};

template <typename T>
class Rectangle : public Figure<T> {
private:
    std::unique_ptr<Point<T>> point1, point2;
public:
    Rectangle() = default;
    Rectangle(const Point<T>& point1, const Point<T>& point2);
    Rectangle(const Rectangle &rect);
    Rectangle(Rectangle &&rect) noexcept;
    
    Rectangle& operator=(const Rectangle &rect);
    Rectangle& operator=(Rectangle &&rect) noexcept;

    bool operator==(const Rectangle &other) const;

    operator double () const override;
    Point<T> geometricCenter() const override;

    friend std::ostream& operator<<(std::ostream &stream, const Rectangle &rect) {
        T deltaX = rect.point2->x - rect.point1->x, deltaY = rect.point2->y - rect.point1->y;
        stream << "Rectangle[ " << *rect.point1 << " " << *rect.point1 + Point<T>{deltaX, 0} << " " <<
                  *rect.point1 + Point<T>{0, deltaY} << " " << *rect.point2 << " ]";
        return stream;
    }

    friend std::istream& operator>>(std::istream &stream, Rectangle &rect) {
        Point<T> p1, p2;
        stream >> p1 >> p2;
        rect = Rectangle(p1, p2);
        return stream;
    }
};

template <typename T>
class Trapezoid : public Figure<T> {
private:
    std::unique_ptr<Point<T>> point1, point2, point3, point4;
public:
    Trapezoid() = default;
    Trapezoid(const Point<T>& point1, const Point<T>& point2, const Point<T>& point3, const Point<T>& point4);
    Trapezoid(const Trapezoid &tr);
    Trapezoid(Trapezoid &&tr) noexcept;
    
    Trapezoid& operator=(const Trapezoid &tr);
    Trapezoid& operator=(Trapezoid &&tr) noexcept;

    bool operator==(const Trapezoid &other) const;

    operator double () const override;
    Point<T> geometricCenter() const override;

    friend std::ostream& operator<<(std::ostream &stream, const Trapezoid &tr) {
        stream << "Trapezoid[ " 
               << *tr.point1 << " " 
               << *tr.point2 << " " 
               << *tr.point3 << " " 
               << *tr.point4 << " ]";
        return stream;
    }

    friend std::istream& operator>>(std::istream &stream, Trapezoid &tr) {
        Point<T> p1, p2, p3, p4;
        stream >> p1 >> p2 >> p3 >> p4;
        tr = Trapezoid(p1, p2, p3, p4);
        return stream;
    }
};

template <typename T>
class Square : public Figure<T> {
private:
    std::unique_ptr<Point<T>> point1, point2;
public:
    Square() = default;
    Square(const Point<T>& point1, const Point<T>& point2);
    Square(const Square &sq);
    Square(Square &&sq) noexcept;
    
    Square& operator=(const Square &sq);
    Square& operator=(Square &&sq) noexcept;

    bool operator==(const Square &other) const;

    operator double () const override;
    Point<T> geometricCenter() const override;

    friend std::ostream& operator<<(std::ostream &stream, const Square &sq) {
        T deltaX = sq.point2->x - sq.point1->x, deltaY = sq.point2->y - sq.point1->y;
        stream << "Square[ " << *sq.point1 << " " << *sq.point1 + Point<T>{deltaX, 0} << " " <<
                  *sq.point1 + Point<T>{0, deltaY} << " " << *sq.point2 << " ]";
        return stream;
    }

    friend std::istream& operator>>(std::istream &stream, Square &sq) {
        Point<T> p1, p2;
        stream >> p1 >> p2;
        sq = Square(p1, p2);
        return stream;
    }
};

}