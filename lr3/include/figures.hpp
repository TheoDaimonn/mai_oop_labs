// Прямоугольник, трапеция, квадрат

#pragma once

#include "point.hpp"

#include <algorithm>

namespace lab3 {

class Figure {
public:
    virtual Point geometricCenter() const = 0;
    virtual operator double () const = 0; 
};

class Rectangle : public Figure {
private:
    // Two opposite points
    Point point1, point2;
public:
    Rectangle() = default;
    Rectangle(const Point& point1, const Point& point2);
    Rectangle(const Rectangle &rect);
    Rectangle(Rectangle &&rect);
    
    Rectangle& operator=(const Rectangle &rect);
    Rectangle& operator=(Rectangle &&rect);

    bool operator==(const Rectangle &other);

    operator double () const override;
    Point geometricCenter() const override;

    friend std::ostream& operator<<(std::ostream &stream, const Rectangle &rect);
    friend std::istream& operator>>(std::istream &stream, Rectangle &rect);
};


class Trapezoid : public Figure {
private:
    // four pionts
    Point point1, point2, point3, point4;
public:
    Trapezoid() = default;
    Trapezoid(const Point& point1, const Point& point2, const Point& point3, const Point& point4);
    Trapezoid(const Trapezoid &tr);
    Trapezoid(Trapezoid &&tr);
    
    Trapezoid& operator=(const Trapezoid &tr);
    Trapezoid& operator=(Trapezoid &&tr);

    bool operator==(const Trapezoid &other);

    operator double () const override;
    Point geometricCenter() const override;

    friend std::ostream& operator<<(std::ostream &stream, const Trapezoid &sq);
    friend std::istream& operator>>(std::istream &stream, Trapezoid &sq);   
};

class Square : public Figure {
private:
    // Two opposite points
    Point point1, point2;
public:
    Square() = default;
    Square(const Point& point1, const Point& point2);
    Square(const Square &sq);
    Square(Square &&sq);
    
    Square& operator=(const Square &sq);
    Square& operator=(Square &&sq);

    bool operator==(const Square &other);

    operator double () const override;
    Point geometricCenter() const override;

    friend std::ostream& operator<<(std::ostream &stream, const Square &sq);
    friend std::istream& operator>>(std::istream &stream, Square &sq);
};

}